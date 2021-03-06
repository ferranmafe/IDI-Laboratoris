#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  public slots:
    void changeFov(int);
    void changeModel(bool);

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // Events del ratolí. El primer s'activa quan apretem el ratolí, el segon
    // quan deixem anar el botó i l'ultim quan el desplacem
    virtual void mousePressEvent   (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent    (QMouseEvent *event);
    virtual void keyPressEvent     (QKeyEvent* event);

  private:
    void createBuffersPatricio ();
    void createBuffersTerra ();
    void createBuffersLegoman ();
    void carregaShaders ();
    void modelTransformPatricio1 ();
    void modelTransformPatricio2 ();
    void modelTransformLegoman1 ();
    void modelTransformLegoman2 ();
    void modelTransformTerra ();
    void projectTransform ();
    void viewTransform ();
    void inicialitzaCamera();
    void radiEsferaContenidora();
    void calculCapsaContenidoraPatricio();
    void calculCapsaContenidoraLegoman();
    // attribute locations
    GLuint vertexLoc, colorLoc, projectaLoc, viewLoc;
    // uniform locations
    GLuint transLoc;
    // VAO i VBO names
    GLuint VBO_vertexs, VBO_color, VAO;
    GLuint VBO_vertexs_legoman, VBO_color_legoman, VAO_legoman;
    GLuint VAO_terra, VBO_vertexs_terra, VBO_color_terra;
    // Program
    QOpenGLShaderProgram *program;
    // Perspective values
    float fov, ra, fovi, znear, zfar;
    glm::vec3 eixX, eixY, eixZ, obs, vrp;
    float theta, psi, phi, deltaA, deltaFov;
    float radi;
    glm::vec3 centre, centrePatricio, centreLegoman;
    glm::vec3 pos;
    float yminPatricio, ymaxPatricio, xminPatricio, xmaxPatricio, zminPatricio, zmaxPatricio;
    float yminLegoman, ymaxLegoman, xminLegoman, xmaxLegoman, zminLegoman, zmaxLegoman;
    Model model, model_legoman;
    bool display_patricio;

    // Interaccio amb cursor
    typedef enum {NOINTERACCIO, ROTACIO} Interaccio;
    Interaccio interaccio;
    int        xClick, yClick;
};
