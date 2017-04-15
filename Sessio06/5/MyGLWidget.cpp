#include "MyGLWidget.h"

#include <iostream>

//Constructora de la classe.
MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent) {
  //Activem el fet de poder rebre events de teclat
  setFocusPolicy(Qt::ClickFocus);
}

//Destructora de la classe.
MyGLWidget::~MyGLWidget () {
  if (program != NULL)
    delete program;
}

//Funció que inicialitza els paràmetres necessaris per al correcte funcionament
//de OpenGL
void MyGLWidget::initializeGL() {

  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();

  //Defineix el color de fons (el color d'esborrat)
  glClearColor(0.5, 0.7, 1.0, 1.0);

  //Activa el buffer de profunditat (per evitar pintar coses innecessàries)
  glEnable(GL_DEPTH_TEST);

  //Funció que carrega els shaders i crea tots els punters que usarem després per
  //pasarls-hi informació
  carregaShaders();

  //Creem els VBO amb tota la informació sobre el nostre model
  createBuffers();

  //Inicialitzem tots els paràmetres de la càmera (obs, vrp, up,...)
  inicialitzaCamera();
}

//Funció que s'activa cada cop que es pinta de nou la pantalla que estem mostrant
//(1 cop per frame)
void MyGLWidget::paintGL () {

  // Esborrem el frame-buffer i el depth buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Creem les matrius que s'encarreguen de la posició de la càmera (view) i dels
  //paràmetres de la seva òptica (project)
  viewTransform();
  projectTransform();

  //Funció que serveix per especificar sobre quin VAO concret anem a treballar
  glBindVertexArray (VAO);

  //Creem la matriu que aplica les transformacions de posició, rotació i angle sobre
  //l'objecte
  modelTransform ();

  //Pintem l'objecte
  glDrawArrays(GL_TRIANGLES, 0, 3 * model.faces().size());

  //Funció que indica al sistema que ja hem acabar d'usar aquest VAO
  glBindVertexArray (0);

  //Ara obrim el segon VAO
  glBindVertexArray (VAO_terra);

  //Pintem el terra
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  //Tanquem el segon VAO
  glBindVertexArray (0);
}

//Funció que inicialitza els paràmetres de la càmera (obs, vrp, vup, ra, fov...)
void MyGLWidget::inicialitzaCamera(){
  //Calculem el radi de la esfera contenidora (el resultat quedarà com a variable global)
  radiEsferaContenidora();

  //Paràmetres necessaris per definir la càmera usant angles d'euler. Estem definint
  //Les coordenades base dels tres eixos de la càmera i els seus angles inicials.
  eixX   = glm::vec3(1.0, 0.0, 0.0);
  eixY   = glm::vec3(0.0, 1.0, 0.0);
  eixZ   = glm::vec3(0.0, 0.0, 1.0);
  theta  = 0.0;
  psi    = 0.0;
  phi    = 0.0;

  //Inicialitzem obs, vrp i vup
  obs = glm::vec3(0.0, 0.0, 1.5 * radi);
  vrp = glm::vec3(0.0, 0.0, 0.0);

  //Inicialitzem d (distància entre obs i vrp) a 0, i el calculem
  float d = 0;
  for (int i = 0; i < 3; i += 1){
    d = d + (obs[i] - vrp[i]) * (obs[i] - vrp[i]);
  }
  d     = sqrt(d);

  //Inicialitzem la resta de valors de càmera
  znear = (d - radi) / 2.0;
  zfar  = d + radi;
  fovi  = 2.0 * asin(radi / d); // (float)M_PI / 2.0f;
  fov   = fovi;
  ra    = 1.0;

  //Calculem la view matrix i la project matrix
  viewTransform ();
  projectTransform ();
}

//Funció que calcula el radi de la esfera contenidora i el seu centre
void MyGLWidget::radiEsferaContenidora(){
  //Definim els valors mínim i màxim de cada coordenada
  float xmin, xmax, ymin, ymax, zmin, zmax;

  //Ens recorrem tots els vertex del model en totes les coordenades, buscant els
  //elements mínim i màxim
  xmin = xmax = model.vertices()[0];
  ymin = ymax = model.vertices()[1];
  zmin = zmax = model.vertices()[2];
  for (unsigned int i = 3; i < model.vertices().size(); i += 3)
  {
    if (model.vertices()[i+0] < xmin)
      xmin = model.vertices()[i+0];
    if (model.vertices()[i+0] > xmax)
      xmax = model.vertices()[i+0];
    if (model.vertices()[i+1] < ymin)
      ymin = model.vertices()[i+1];
    if (model.vertices()[i+1] > ymax)
      ymax = model.vertices()[i+1];
    if (model.vertices()[i+2] < zmin)
      zmin = model.vertices()[i+2];
    if (model.vertices()[i+2] > zmax)
      zmax = model.vertices()[i+2];
  }
  //Calculem el radi de la esfera
  float dx  = xmax - xmin;
  float dy  = ymax - ymin;
  float dz  = zmax - zmin;
  radi      = sqrt(dx * dx + dy * dy + dz * dz)/2.0;

  //Calculem el centre de la esfera contenidora
  centre[0] = (xmax + xmin) / 2.0;
  centre[1] = (ymax + ymin) / 2.0;
  centre[2] = (zmax + zmin) / 2.0;
}

//Funció que genera la Model Matrix
void MyGLWidget::modelTransform () {
  //Generem la matriu amb la identitat
  glm::mat4 transform (1.0f);

  //Apliquem les transformacions que volguem
  transform = glm::translate(transform, -centre);

  //Carreguem la matriu com a uniform
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

//Funció que genera la View Matrix
void MyGLWidget::viewTransform () {
  //Aquest cop generem la View matrix amb angles d'euler
  glm::mat4 view(1.0f);
  //Posem el model a l'origen
  view = glm::translate(view, -obs);
  //El rotem en els 3 eixos, perque quedi tal i com estaba abans
  view = glm::rotate(view, -psi,  eixY);
  view = glm::rotate(view, theta, eixX);
  view = glm::rotate(view, phi,   eixZ);
  //Desplaçem el model, perque es vegi a la mateixa distància que abans
  view = glm::translate(view, -vrp);
  //Passem la View Matrix resultant als shaders
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
}

//Funció que genera la Project Matrix
void MyGLWidget::projectTransform () {
  // Matriu de Projecció del model: perspective(fov (en rad), ra, znear, zfar)
  glm::mat4 projecta = glm::perspective(fov, ra, znear, zfar);
  //Passem la matriu als shaders
  glUniformMatrix4fv(projectaLoc, 1, GL_FALSE, &projecta[0][0]);
}

//Funció que s'activa només quan redimensionem el viewport, la qual redimensiona
//el fov quan calgui i la ra sempre
void MyGLWidget::resizeGL (int w, int h) {
    //Calculem ra de nou
    ra = float (w) / float (h);
    //Si ra es menor que 1, toca recalcular el fov
    if (ra < 1.0) {
      fov = 2.0 * atan(tan(fovi/2.0)/ra);
    }
    //Indiquem el nou viewport
    glViewport(0, 0, w, h);
}

//Funció que crea els VBO que s'usaràn per pintar els models
void MyGLWidget::createBuffers () {
  //Carreguem les dades del nostre objecte a pintar
  model.load("../../models/Patricio.obj");

  //Generem el VAO
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  //A partir del VAO generem el VBO de vèrtex
  glGenBuffers(1, &VBO_vertexs);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_vertexs);
  //Omplim el VBO amb les dades
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(GLfloat) * model.faces().size() * 3 * 3,
               model.VBO_vertices(), GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  //El mateix que abans, pero amb els colors
  glGenBuffers(1, &VBO_color);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_color);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(GLfloat) * model.faces().size() * 3 * 3,
               model.VBO_matdiff(), GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  //Al acabar desactivem el VAO
  glBindVertexArray (0);
  //------------------------------------------------------------
  /*glm::vec3 posicio[4] = {
         glm::vec3(-1.0, -1.0, 1.0),
         glm::vec3( 1.0, -1.0, 1.0),
         glm::vec3(-1.0, -1.0, -1.0),
         glm::vec3( 1.0, -1.0, -1.0)
   };
   glm::vec3 color[4] = {
         glm::vec3(1,0,0),
         glm::vec3(0,1,0),
         glm::vec3(0,0,1),
         glm::vec3(1,0,0)
   };

   // Creació del Vertex Array Object per pintar
   glGenVertexArrays(1, &VAO_terra);
   glBindVertexArray(VAO_terra);

   glGenBuffers(1, &VBO_vertexs_terra);
   glBindBuffer(GL_ARRAY_BUFFER, VBO_vertexs_terra);
   glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);

   // Activem l'atribut vertexLoc
   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   glGenBuffers(1, &VBO_color_terra);
   glBindBuffer(GL_ARRAY_BUFFER, VBO_color_terra);
   glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

   // Activem l'atribut colorLoc
   glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(colorLoc);

   glBindVertexArray (0);*/
}

//Funció que genera els shaders, els uniforms que usarem
void MyGLWidget::carregaShaders() {
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  viewLoc = glGetUniformLocation(program->programId(), "view");
  projectaLoc = glGetUniformLocation(program->programId(), "PR");
}
