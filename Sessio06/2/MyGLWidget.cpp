#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent) {
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  scale = 1.0f;
  giry = 0.0f;
}

MyGLWidget::~MyGLWidget () {
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL() {
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  inicialitzaCamera();
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  carregaShaders();
  createBuffers();
}

void MyGLWidget::paintGL () {
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model

  viewTransform();
  projectTransform();
  glBindVertexArray (VAO);

  modelTransform ();
  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 3 * model.faces().size());

  glBindVertexArray (0);

  glBindVertexArray (VAO_terra);
  // pintem
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glBindVertexArray (0);
}

void MyGLWidget::inicialitzaCamera(){
  radiEsferaContenidora();

  obs = glm::vec3(0.0, 0.0, 1.5 * radi);
  vrp = glm::vec3(0.0, 0.0, 0.0);
  vup = glm::vec3(0.0, 1.0, 0.0);

  float d = 0;
  for (int i = 0; i < 3; i += 1){
    d = d + (obs[i] - vrp[i]) * (obs[i] - vrp[i]);
  }
  d     = sqrt(d);
  znear = (d - radi) / 2.0;
  zfar  = d + radi;
  fovi  = 2.0 * asin(radi / d); // (float)M_PI / 2.0f;
  fov   = fovi;
  ra    = 1.0;
  angle = 0.0;

  viewTransform ();
  projectTransform ();
}

void MyGLWidget::radiEsferaContenidora(){

  /*valors min-max determinats manualment per
  inspeccio de la geometria coneguda de l'escena*/
  float xmin = -1.0;
  float ymin = -1.0;
  float zmin = -1.0;
  float xmax =  1.0;
  float ymax =  2.0;
  float zmax =  1.0;
  float dx   = xmax - xmin;
  float dy   = ymax - ymin;
  float dz   = zmax - zmin;
  radi       = sqrt(dx * dx + dy * dy + dz * dz)/2.0;
  centre[0]  = (xmax + xmin) / 2.0;
  centre[1]  = (ymax + ymin) / 2.0;
  centre[2]  = (zmax + zmin) / 2.0;
}

void MyGLWidget::modelTransform () {
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = transform * glm::rotate(transform, giry, glm::vec3(0.0f, 1.0f, 0.0f));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::viewTransform () {
  // Matriu de projecciÃ³ del model. lookAt(obs, vrp, vup)
  glm::mat4 view = glm::lookAt(obs, vrp, vup);
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
}

void MyGLWidget::projectTransform () {
  // Matriu de projecciÃ³ del model: perspective(fov (en rad), ra, znear, zfar)
  glm::mat4 projecta = glm::perspective(fov, ra, znear, zfar);
  glUniformMatrix4fv(projectaLoc, 1, GL_FALSE, &projecta[0][0]);
}

void MyGLWidget::resizeGL (int w, int h) {
    ra = float (w) / float (h);
    if (ra < 1.0) {
      fov = 2.0 * atan(tan(fovi/2.0)/ra);
    }
    glViewport(0, 0, w, h);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: {
      giry += (float)M_PI/4.0f;
  }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::createBuffers () {
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  model.load("../../models/HomerProves.obj");

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO_vertexs);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_vertexs);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(GLfloat) * model.faces().size() * 3 * 3,
               model.VBO_vertices(), GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_color);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_color);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(GLfloat) * model.faces().size() * 3 * 3,
               model.VBO_matdiff(), GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);
  //------------------------------------------------------------
  glm::vec3 posicio[4] = {
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

   glBindVertexArray (0);
}

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
