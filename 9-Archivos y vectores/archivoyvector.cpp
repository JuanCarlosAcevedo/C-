#include<iostream>
#include<stdio.h>
using namespace std;

struct alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};
void inicializar(alumno vec[], int cantpos, alumno valini);
void insertar(alumno vec1[], int &len1, alumno val1, int pos1);
void insertarordenado(alumno vec2[], int &len2, alumno val2);

int main(){
  
    FILE * alum;
    alumno vc[10];
    int len=0;

    alumno val;
    val.legajo=0;
    val.dni=0;
    val.nota1=0;
    val.nota2=0;

    inicializar(vc,10,val);

    alum=fopen("K1151.dat","rb");

    alumno raux;
    fread(&raux,sizeof(struct alumno),1,alum);
    while(!feof(alum)){
        insertarordenado(vc,len,raux);
        fread(&raux,sizeof(struct alumno),1,alum);
    }
    fclose(alum);
    alum=fopen("K1151.dat","wb");
    for(int i=0; i<len; i++){
        fwrite(&vc[i],sizeof(struct alumno),1,alum);
    }
    fclose(alum);
    return 0;

}
void inicializar(alumno vec[], int cantpos, alumno valini){
    for(int i=0; i<cantpos; i++){
        vec[i].legajo=valini.legajo;
        vec[i].dni=valini.dni;
        vec[i].nota1=valini.nota1;
        vec[i].nota2=valini.nota2;
    }
}
void insertar(alumno vec1[], int &len1, alumno val1, int pos1){
    for(int i=len1; i>pos1; i--){
        vec1[i].legajo = vec1[i-1].legajo;
        vec1[i].dni = vec1[i-1].dni;
        vec1[i].nota1 = vec1[i].nota1;
        vec1[i].nota2 = vec1[i].nota2;
    }
    vec1[pos1].legajo = val1.legajo;
    vec1[pos1].dni = val1.dni;
    vec1[pos1].nota1 = val1.nota1;
    vec1[pos1].nota2 = val1.nota2;
    len1++;
}
void insertarordenado(alumno vec2[], int &len2, alumno val2){
    int i=0;
    while(i<len2 && vec2[i].legajo<=val2.legajo){
        i++;
    }
    if(i==len2){
        vec2[len2].legajo=val2.legajo;
        vec2[len2].dni=val2.dni;
        vec2[len2].nota1=val2.nota1;
        vec2[len2].nota2=val2.nota2;
        len2++;
    }
    else{
        insertar(vec2,len2,val2,i);
    }
}
