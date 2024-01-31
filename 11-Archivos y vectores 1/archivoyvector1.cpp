/*Se tiene un archivo de películas infantiles en una plataforma digital con los títulos disponibles para la Argentina. 
  Dicho archivo contiene las películas agregadas con motivo de las vacaciones de invierno Infantil.DAT (Sin Orden)
-          Código de Película: 999999
-          Cantidad de opiniones positivas: 99999
-          Cantidad de vistas: 999999999
Se pide:
a)       Ordenar el Archivo por Opiones Positivas
b)       Listar las 10 películas que más vistas tuvieron (al listar incluir toda la información referente a la película)
Nota: Sólo debe leer 1 vez el archivo. Se sabe que no hay más de 50 películas.
 */
#include<iostream>
#include<stdio.h>

using namespace std;
struct peliculas{
    int codigo;
    int opiniones;
    int vistas;
};

void inicializar(peliculas vec[], int cantpos, peliculas valini);
void insertar(peliculas vec1[], int &len1, peliculas val1, int pos1);
void insertarordenadoA(peliculas vec2[], int &len2, peliculas val2);
void insertarordenadoB(peliculas vec3[], int &len3, peliculas val3);

int main(){
 
    peliculas vc[50];
    int lnvc=0;

    peliculas vc1[50];
    int lnvc1=0;

    FILE * peli;
    FILE * peli1;
  
    peliculas raux;
   
    raux.codigo=0;
    raux.opiniones=0;
    raux.vistas=0;

    inicializar(vc,50,raux);
    inicializar(vc1,50,raux);
  
    peli=fopen("infantil.dat","rb");
    
    peliculas raux1;
    fread(&raux1,sizeof(struct peliculas),1,peli);
    while(!feof(peli)){
        insertarordenadoA(vc,lnvc,raux);
        insertarordenadoB(vc1,lnvc1,raux1);
        fread(&raux1,sizeof(struct peliculas),1,peli);
    }
    fclose(peli);
    
    peli=fopen("infantil.dat","wb");
    for(int i=0; i<lnvc; i++){
        fwrite(&vc[i],sizeof(struct peliculas),1,peli);
    }
    fclose(peli);

    if(lnvc1>10){
        for(int i=0; i<10; i++){
            cout<<"-------------------------------"<<endl;
            cout<<"La pelicula: "<<vc1[i].codigo<<endl;
            cout<<"Con una cantidad de opiniones positivas de: "<<vc1[i].opiniones<<endl;
            cout<<"Obtubo una cantidad de vistas de:"<<vc1[i].vistas<<endl;
        }
    }
    else{
        for(int i=0; i<lnvc1; i++){
            cout<<"-------------------------------"<<endl;
            cout<<"La pelicula: "<<vc1[i].codigo<<endl;
            cout<<"Con una cantidad de opiniones positivas de: "<<vc1[i].opiniones<<endl;
            cout<<"Obtubo una cantidad de vistas de:"<<vc1[i].vistas<<endl;
        }
    }

    return 0;
}

void inicializar(peliculas vec[], int cantpos, peliculas valini){
    for(int i=0; i<cantpos; i++){
        vec[i].codigo=valini.codigo;
        vec[i].opiniones=valini.opiniones;
        vec[i].vistas=valini.vistas;
    }
}

void insertar(peliculas vec1[], int &len1, peliculas val1, int pos1){
    for(int i=len1; i>pos1; i--){
        vec1[i].codigo=vec1[i-1].codigo;
        vec1[i].opiniones=vec1[i-1].opiniones;
        vec1[i].vistas=vec1[i-1].vistas;
    }
    vec1[pos1].codigo=val1.opiniones;
    vec1[pos1].opiniones=val1.opiniones;
    vec1[pos1].vistas=val1.vistas;
    len1++;
}

void insertarordenadoA(peliculas vec2[], int &len2, peliculas val2){
    int i=0;
    while(i<len2 && vec2[i].opiniones>=val2.opiniones){
        i++;
    }
    if(i==len2){
        vec2[len2].codigo=val2.codigo;
        vec2[len2].opiniones=val2.opiniones;
        vec2[len2].vistas=val2.vistas;
    }
    else{
        insertar(vec2,len2,val2,i);
    }

}

void insertarordenadoB(peliculas vec3[], int &len3, peliculas val3){
    int i=0;
    while(i<len3 && vec3[i].vistas<=val3.vistas){
        i++;
    }
    if(i==len3){
        vec3[len3].codigo=val3.codigo;
        vec3[len3].opiniones=val3.opiniones;
        vec3[len3].vistas=val3.vistas;
        len3++;
    }
    else{
        insertar(vec3,len3,val3,i);
    }
}
