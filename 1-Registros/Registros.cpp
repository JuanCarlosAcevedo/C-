#include <iostream>
using namespace std;

struct alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};
void mostrarnota(alumno pp);
int promedio(alumno p1);

int main(){
    alumno n1;
    int n, z;

    cout<<"Ingrese el legajo: "<<endl;
    cin>>n1.legajo;
    cout<<"Ingrese el DNI: "<<endl;
    cin>>n1.dni;
    cout<<"Ingrese la nota1: "<<endl;
    cin>>n1.nota1;
    cout<<"Ingrese la nota2: "<<endl;
    cin>>n1.nota2;

    mostrarnota(n1);
    cout<<"Ingrese la nota1 si recupero o 0 sino recupero: "<<endl;
    cin>>n;

    if(n>=6){
        n1.nota1=n;
    }
    
    cout<<"Ingrese la nota2 si recupero o 0 sino recupero: "<<endl;
    cin>>n;

    if(n>=6){
        n1.nota2=n;
    }
    
    mostrarnota(n1);
    z=promedio(n1);
    cout<<"El promedio es: "<<z<<endl;

    return 0;
    
}
void mostrarnota(alumno pp){
    cout<<"El alumno: "<<pp.legajo<<endl;
    cout<<"Con DNI numero: "<<pp.dni<<endl;
    cout<<"Tiene una nota1 de: "<<pp.nota1<<endl;
    cout<<"Tiene una nota2 de: "<<pp.nota2<<endl;
}
int promedio(alumno p1){
    return (p1.nota1 + p1.nota2)/2;
}
