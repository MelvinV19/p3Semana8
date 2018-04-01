#include "Alumno.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ostream& operator<<(ostream& out,const Alumno& student){
  out<<student.nombre<<","<<student.cuenta<<","<<student.carrera<<","<<student.edad<<endl;
  return out;
}

istream& operator>>(istream& in,Alumno& student){
  string buffer;
  //leer linea de un archivo
  getline(in,buffer);
  string parse="";
  int cont=0;
  for (int i = 0; i < buffer.size(); i++) {
    if (buffer[i]!=',') {
      parse+=buffer[i];
    }
    else{
      switch (cont) {
        case 0:
          student.nombre=parse;
          parse="";
          break;
        case 1:
            student.cuenta=parse;
            parse="";
            break;
      }
      cont++;
    }

  }
}

Alumno::Alumno(){
  nombre="JaJa";
  cuenta="312312312";
  carrera="nada";
  edad=54;
}

Alumno::Alumno(string nombre,string cuenta,string carrera,int edad){
  this->nombre=nombre;
  this->cuenta=cuenta;
  this->carrera=carrera;
  this->edad=edad;
}

//metodo para escribir en un archivo binario
void Alumno::write(ofstream& out){
  int size=nombre.size();
  //length del nombre y contenido
  out.write(reinterpret_cast<char*>(&size),sizeof(int));
  out.write(nombre.data(),size);


  //cuenta
  size=cuenta.size();
  out.write(reinterpret_cast<char*>(&size),sizeof(int));
  out.write(cuenta.data(),size);

  //carrera
  size=carrera.size();
  out.write(reinterpret_cast<char*>(&size),sizeof(int));
  out.write(carrera.data(),size);

  //edad
  out.write(reinterpret_cast<char*>(&edad),sizeof(int));
}
int Alumno::operator+(Alumno& rightValue){
  return this->edad+rightValue.getEdad();

}


//metodo para leer el archivo binario
void Alumno::read(ifstream& in){
  int size;
  in.read(reinterpret_cast<char*>(&size),sizeof(int));

  //buffer de nombre
  char nameBuffer[size];
  in.read(nameBuffer,size);

  nombre=nameBuffer;

  //cuenta
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  char numBuffer[size];
  in.read(numBuffer,size);

  cuenta=numBuffer;

  //carrera
  in.read(reinterpret_cast<char*>(&size),sizeof(int));
  char carreraBuffer[size];
  in.read (carreraBuffer,size);

  carrera=carreraBuffer;

  //edad

  in.read(reinterpret_cast<char*>(&size),sizeof(int));

}
