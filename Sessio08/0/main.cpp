
/*
 * euler amb QT  
 * RJA abril 2017

 * main.cpp
 */

#include <QApplication>
#include "MyForm.h"

int main (int argc, char **argv) 
{
  QApplication app (argc, argv);
  QSurfaceFormat f;
  f.setVersion(3,3);
  f.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(f);

  MyForm myForm;
  myForm.show();
  return app.exec ();
}
