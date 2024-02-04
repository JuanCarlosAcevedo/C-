#include<iostream>
#include<stdio.h>
using namespace std;
struct jugadores{
    int codigo;
    int seleccion;
    int edad;
    int altura;
};

struct jugadoresA{
    int codigoA;
    int seleccionA;
    int edadA;
};

void inicializar(jugadores vec[], int cantpos, jugadores valini);
void inicializarA(jugadoresA vec[], int cantpos, jugadores valini);
void insertar(jugadores vec1[], int &len1, jugadores val1, int pos1);
void insertarA(jugadoresA vec1[], int &len1, jugadoresA val1, int pos1);
void insertarordenado(jugadores vec2[], int &len2, jugadores val2);

int main(){
  
    jugadores vc[100];
    int len=0;

    jugadoresA vcA[100];
    int lenA=0;

    FILE * jug;
    
    jugadores valini1;
    valini1.codigo=0;
    valini1.seleccion=0;
    valini1.edad=0;
    valini1.altura=0;

    jugadoresA valini2;
    valini2.codigoA=0;
    valini2.seleccionA=0;
    valini2.edadA=0;

    inicializar(vc,100,valini1);
    inicializarA(vcA,100,valini2);
    
    jug=fopen("jugadores2021.dat","rb");
    
    jugadores raux;
    jugadoresA rauxA;

    fread(&raux,sizeof(struct jugadores),1,jug);

    int i=0;
    while(!feof(jug)){
        if(vc[i].edad<=23){
            insertarordenado(vc,len,raux);
        }
        if(vc[i].altura>180){
            rauxA.codigoA=raux.codigo;
            rauxA.seleccionA=raux.seleccion;
            rauxA.edadA=raux.edad;

            insertarordenadoA(vcA,lenA,rauxA);
        }
        fread(&raux,sizeof(struct jugadores),1,jug);
    }
    fclose(jug);
    return 0;

}
void inicializar(jugadores vec[], int cantpos, jugadores valini){
    for(int i=0; i<cantpos; i++){
        vec[i].codigo=valini.codigo;
        vec[i].seleccion=valini.seleccion;
        vec[i].edad=valini.edad;
        vec[i].altura=valini.altura;
    }
}

void inicializarA(jugadoresA vec[], int cantpos, jugadoresA valini){
    for(int i=0; i<cantpos; i++){
        vec[i].codigoA=valini.codigoA;
        vec[i].seleccionA=valini.seleccionA;
        vec[i].edadA=valini.edadA;
    }
}

void insertar(jugadores vec1[], int &len1, jugadores val1, int pos1){
    for(int i=len1; i>pos1; i--){
        vec1[i].codigo=vec1[i-1].codigo;
        vec1[i].seleccion=vec1[i-1].seleccion;
        vec1[i].edad=vec1[i-1].edad;
        vec1[i].altura=vec1[i-1].altura;
    }
    vec1[pos1].codigo=val1.codigo;
    vec1[pos1].seleccion=val1.seleccion;
    vec1[pos1].edad=val1.edad;
    vec1[pos1].altura=val1.altura;
    len1++;
}

void insertarA(jugadoresA vec1[], int &len1, jugadoresA val1, int pos1){
    for(int i=len1; i>pos1; i--){
        vec1[i].codigoA=vec1[i-1].codigoA;
        vec1[i].seleccionA=vec1[i-1].seleccionA;
        vec1[i].edadA=vec1[i-1].edadA;
    }
    vec1[pos1].codigoA=val1.codigoA;
    vec1[pos1].seleccionA=val1.seleccionA;
    vec1[pos1].edadA=val1.edadA;
    len1++;
}

void insertarordenado(jugadores vec2[], int &len2, jugadores val2){
    int i=0;
    while(i<len2 && vec2[i].codigo < val2.codigo){
        i++;
    }
    if(i==len2){
        vec2[len2].codigo=val2.codigo;
        vec2[len2].seleccion=val2.seleccion;
        vec2[len2].edad=val2.edad;
        vec2[len2].altura=val2.edad;
        len2++;
    }
    else{
        insertar(vec2,len2,val2,i);
    }
}

void insertarordenadoA(jugadoresA vec2[], int &len2, jugadoresA val2){
    int i=0;
    while(i<len2 && vec2[i].codigoA < val2.codigoA){
        i++;
    }
    if(i==len2){
        vec2[len2].codigoA=val2.codigoA;
        vec2[len2].seleccionA=val2.seleccionA;
        vec2[len2].edadA=val2.edadA;
        len2++;
    }
    else{
        insertarA(vec2,len2,val2,i);
    }
}
