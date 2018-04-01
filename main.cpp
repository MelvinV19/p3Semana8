#include <fstream>
#include <iostream>
#include <string>
#include "Alumno.h"
using namespace std;
//manipular archivos binarios guardando objetos
//void binAlumno();

//ejemplo sobrecarga de operador <<
void writeAlumno();
//ejemplo sobrecarga de operador >>
void readAlumno();

void addAlumno(){
  Alumno* alumno1=new Alumno("dsdas","3232131","dsadas",25);
  Alumno* alumno2=new Alumno("rewrwerwe","54546645","pepepe",40);
  int edadTotal=*alumno1+*alumno2;
  cout << "La edad total es: "<<edadTotal<< endl;
  delete alumno1;
  delete alumno2;
}

int main() {
  //binAlumno();
  writeAlumno();
  readAlumno();
  addAlumno();
  return 0;
}

void writeAlumno(){
    Alumno* alumno=new Alumno("jiji","312312312","lol",32);
    cout << *alumno << '\n';
    delete alumno;
}

void readAlumno(){
  Alumno* alumno=new Alumno();
  cin>>*alumno;
  cout << "los datos son: " <<endl<<*alumno;
  delete alumno;
}

/*void binAlumno(){
  ofstream alumnos("Alumnos.dat",ios::binary);

  Alumno* alumno1=new Alumno("DASDASD","123123123","Sistemas",18);

  alumno1->write(alumnos);

  alumnos.close();
}*/
