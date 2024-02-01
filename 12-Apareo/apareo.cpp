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
    FILE * A;
    FILE * B;
    FILE * C;

    A=fopen("archivoA.dat","rb");
    B=fopen("archivoB.dat","rb");
    C=fopen("archivoC.dat","wb");

    alumno rauxA;
    alumno rauxB;
    
    fread(&rauxA,sizeof(struct alumno),1,A);
    fread(&rauxB,sizeof(struct alumno),1,B);
    
    while((!feof(A) && !feof(B))){
        if(rauxA.legajo < rauxB.legajo){
            fwrite(&rauxA,sizeof(struct alumno),1,C);
            fread(&rauxA,sizeof(struct alumno),1,A);
        }
        else{
            fwrite(&rauxB,sizeof(struct alumno),1,C);
            fread(&rauxB,sizeof(struct alumno),1,B);
        }
    }

    while(!feof(A)){
        fwrite(&rauxA,sizeof(struct alumno),1,C);
        fread(&rauxA,sizeof(struct alumno),1,A);
    }

    while(!feof(B)){
        fwrite(&rauxB,sizeof(struct alumno),1,C);
        fread(&rauxB,sizeof(struct alumno),1,B);
    }

    return 0;

}
