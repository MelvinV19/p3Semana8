#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Alumno{
private:
  string nombre,cuenta,carrera;
  int edad;

public:
  Alumno();
  //nombre ,cuenta, carrera,edad
  Alumno(string,string,string,int);

  void write(ofstream&);
  void read(ifstream&);
  //declaracion e implementacion inline
  int getEdad(){return edad;}
  int operator +(Alumno&);

  friend ostream& operator<<(ostream&,const Alumno&);
  friend istream& operator>>(istream&,Alumno&);

};
#endif
