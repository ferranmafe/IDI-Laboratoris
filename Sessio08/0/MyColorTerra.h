/*
 * colors amb QT  
 * RJA abril 2017

 * MyLabel.h
 */

#define GLM_FORCE_RADIANS

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QLabel>
#include <QColor>
#include <QString>

class MyColorTerra : public QLabel
{
  Q_OBJECT

  public:
  MyColorTerra (QWidget *parent);
    // ~MyColorTerra ();

  public slots:
    void setRoig (int);
    void setVerd (int);
    void setBlau (int);

  signals:
    /*
    void iniRoig(int);
    void iniVerd(int);
    void iniBlau(int);
    */
    void sendColorTerra(int, int, int);

  private:  // global variables
    int roig, verd, blau;
};
