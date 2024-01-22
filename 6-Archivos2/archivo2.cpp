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
    alum=fopen("K1151.dat","rb");
    fread(&raux,sizeof(struct alumno),1,alum);

    while(!feof(alum)){
        cout<<"El alumno de legajo: "<<raux.legajo<<" de DNI: "<<raux.dni<<" tiene nota1: "<<raux.nota1<<" tiene nota2: "<<raux.nota2<<" tiene un promedio de: "<<(raux.nota1 + raux.nota2)/2<<endl;
        fread(&raux,sizeof(struct alumno),1,alum);
    }
    fclose(alum);
    return 0;
}
