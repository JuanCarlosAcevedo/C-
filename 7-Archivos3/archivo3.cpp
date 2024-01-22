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
    int cantA=0;
    int cantD=0;
    FILE * alum;
    alum=fopen("K1151.dat","rb");

    fread(&raux,sizeof(struct alumno),1,alum);

    while(!feof(alum)){
        if(raux.nota1>6 && raux.nota2>6){
            cantA++;
        }
        else{
            cantD++;
        }
        fread(&raux,sizeof(struct alumno),1,alum);
    }
    fclose(alum);
    cout<<"La cantidad de aprobados es de: "<<cantA<<endl;
    cout<<"La cantidad de desaprobados es de: "<<cantD<<endl;

    return 0;
}
