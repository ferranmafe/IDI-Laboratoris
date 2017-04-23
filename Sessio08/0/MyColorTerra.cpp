/*
 * widget de paleta de colors
 * RJA abril 2017
 *
 */

#include "MyColorTerra.h"

MyColorTerra::MyColorTerra (QWidget *parent) : QLabel(parent)
{
  
  roig = 255;
  verd = 255;
  blau = 255;
  
  setStyleSheet(QString("background-color:rgb(%1, %2, %3)")
		        .arg(roig).arg(verd).arg(blau));

  /*
  // inicialitza el color dels spins en MyForm.ui
  emit iniRoig(roig);  
  emit iniVerd(verd);
  emit iniBlau(blau);
  */
  
  // inicialitza el color de la paleta en MyEuler.cpp
  emit sendColorTerra(roig, verd, blau);
}

void MyColorTerra::setRoig(int r)
{
  roig = r;
  setStyleSheet(QString("background-color:rgb(%1, %2, %3);")
		       .arg(roig).arg(verd).arg(blau));
  emit sendColorTerra(roig, verd, blau);
}

void MyColorTerra::setVerd(int g)
{
  verd = g;
  setStyleSheet(QString("background-color:rgb(%1, %2, %3);")
  		        .arg(roig).arg(verd).arg(blau));
  emit sendColorTerra(roig, verd, blau);
} 

void MyColorTerra::setBlau(int b)
{
  blau = b;
  setStyleSheet(QString("background-color:rgb(%1, %2, %3);")
		        .arg(roig).arg(verd).arg(blau));
  emit sendColorTerra(roig, verd, blau);
}

