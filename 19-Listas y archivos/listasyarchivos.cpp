#include<iostream>
#include<stdio.h>
struct nodo{
    int info;
    nodo *sgte;
};
void insertarordenado(nodo *&listaX, int valor);
void liberar(nodo *&listaX);
void mostrar(nodo *listaX);

using namespace std;

int main(){
    /*creacion y carga de un archivo, con datos introducidos por el usuario
    int carga;
    FILE *ent;

    ent=fopen("enteros.dat","wb");

    cout<<"Ingrese los elementos a cargar o 0 para terminar"<<endl;
    cin>>carga;
    
    while(carga!=0){
        fwrite(&carga, sizeof (int), 1, ent);
        cout<<"Ingrese los elementos a cargar o 0 para terminar"<<endl;
        cin>>carga;
    }
    fclose(ent);
    return 0;
    */
    
    
    nodo *lista=NULL;
    FILE *ent;
    int aread;

    ent=fopen("enteros.dat","rb");
    fread(&aread,sizeof (int),1,ent);

    while(!feof(ent)){
        insertarordenado(lista,aread);
        fread(&aread,sizeof (int),1,ent);
    }
    fclose(ent);

    ent=fopen("enteros.dat","wb");
    nodo *aux=lista;

    while(aux!=NULL){
        fwrite(&aux->info,sizeof (int),1,ent);
        aux=aux->sgte;
    }

    fclose(ent);    
    mostrar(lista);
    liberar(lista);
    return 0;    

}

void insertarordenado(nodo *&listaX, int valor){
    nodo *nuevo=new nodo();
    nuevo->info=valor;
    nuevo->sgte=NULL;
    nodo *ant=NULL;
    nodo *aux=listaX;
    while(aux!=NULL && aux->info<valor){
        ant=aux;
        aux=aux->sgte;
    }
    if(ant==NULL){
        listaX=nuevo;
    }
    else{
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux;

}

void liberar(nodo *&listaX){
    nodo *aux;
    if(listaX!=NULL){
        aux=listaX;
        listaX=aux->sgte;
        delete(aux);
    }
}

void mostrar(nodo *listaX){
    nodo *aux=listaX;
    while(aux!=NULL){
        cout<<aux->info<<endl;
        aux=aux->sgte;
    }
}
