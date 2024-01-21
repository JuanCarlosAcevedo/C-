#include<iostream>
#include<stdio.h>
using namespace std;

struct alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){
    alumno raux;

    FILE * alum;
    alum=fopen("K1151.dat","wb");
    cout<<"Ingrese el numero de legajo o 0 para terminar: "<<endl;
    cin>>raux.legajo;

    while(raux.legajo>0){
        cout<<"Ingrese el DNI: "<<endl;
        cin>>raux.dni;
        cout<<"Ingrese la nota1: "<<endl;
        cin>>raux.nota1;
        cout<<"Ingrese la nota2: "<<endl;
        cin>>raux.nota2;

        fwrite(&raux,sizeof(struct alumno),1,alum);

        cout<<"Ingrese el numero de legajo o 0 para terminar: "<<endl;
        cin>>raux.legajo;

    }
    fclose(alum);

    return 0;

}
