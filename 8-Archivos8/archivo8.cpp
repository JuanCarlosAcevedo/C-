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
    FILE * apro;
    FILE * des;

    alum=fopen("K1151.dat","rb");
    apro=fopen("K1151apro.dat","wb");
    des=fopen("K1151des.dat","wb");

    alumno raux;

    fread(&raux, sizeof(struct alumno),1,alum);

    while(!feof(alum)){
        if(raux.nota1 < 6 || raux.nota2 < 6){
        fwrite(&raux, sizeof(struct alumno),1,des);
        }
        else{
        fwrite(&raux, sizeof(struct alumno),1,apro);
        }
        fread(&raux, sizeof(struct alumno),1,alum);
    }

    fclose(alum);
    fclose(apro);
    fclose(des);

    return 0;


}
