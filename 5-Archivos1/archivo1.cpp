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
    FILE * alum;
    alum=fopen("K1151.dat","rb");

    alumno raux;

    fread(&raux,sizeof(struct alumno),1,alum);

    while(!feof(alum)){
        cout<<"El legajo es: "<<raux.legajo<<endl;
        cout<<"El DNI es: "<<raux.dni<<endl;
        cout<<"La nota1 es: "<<raux.nota1<<endl;
        cout<<"La nota2 es: "<<raux.nota2<<endl;
        cout<<"--------------------------------------"<<endl;

        fread(&raux,sizeof(struct alumno),1,alum);
    }

    fclose(alum);

    return 0;
}
