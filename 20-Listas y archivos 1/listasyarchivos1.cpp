//Dado un archivo de registro (codPrd; tipodeProd) generar 2 archivos ordenados (según el tip'A' ó 'B') por codigo de producto
#include<iostream>
#include<stdio.h>
using namespace std;

struct tinfo{
    int cod;
    char tipo;
};

struct nodo{
    tinfo info;
    nodo *sgte;
};

void insertarordenado(nodo *&lista, tinfo valor);
void mostrar(nodo *lista);
void liberar(nodo *&lista);

int main(){

    nodo *listaA=NULL;
    nodo *listaB=NULL;

    FILE *arch;
    FILE *archA;
    FILE *archB;

    arch=fopen("archivo.dat","rb");
    tinfo raux;
    fread(&raux,sizeof (struct tinfo),1,arch);

    while(!feof(arch)){
        if(raux.tipo=='A'){
            insertarordenado(listaA,raux);
        }
        else{
            insertarordenado(listaB,raux);
        }
        fread(&raux,sizeof (struct tinfo),1,arch);
    }
    fclose(arch);

    archA=fopen("archivoA.dat","wb");    
    nodo *aux=listaA;

    while(aux!=NULL){
        fwrite(&aux->info,sizeof (struct tinfo),1,archA);
        aux=aux->sgte;
    }

    fclose(archA);
    mostrar(listaA);
    liberar(listaA);

    archB=fopen("archivoB.dat","wb");
    aux=listaB;

    while(aux!=NULL){
        fwrite(&aux->info,sizeof (struct tinfo),1,archB);
        aux=aux->sgte;
    }

    fclose(archB);
    mostrar(listaB);
    liberar(listaB);

    return 0;

}

void insertarordenado(nodo *&lista, tinfo valor){
    nodo *nuevo=new nodo();
    nuevo->info.cod=valor.cod;
    nuevo->info.tipo=valor.tipo;
    nuevo->sgte=NULL;
    nodo *aux=lista;
    nodo *ant=NULL;
    while(aux!=NULL && aux->info.cod<valor.cod){
        ant=aux;
        aux=aux->sgte;
    }
    if(ant==NULL){
        lista=nuevo;
    }
    else{
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux;
}
void mostrar(nodo *lista){
    nodo *aux=lista;
    while(aux!=NULL){
        cout<<aux->info.cod<<endl;
        cout<<aux->info.tipo<<endl;
        aux=aux->sgte;
    }
}
void liberar(nodo *&lista){
    nodo *aux;
    while(lista!=NULL){
        aux=lista;
        lista=aux->sgte;
        delete(aux);
    }
}
