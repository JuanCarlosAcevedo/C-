#include<iostream>
using namespace std;
struct nodo{
    int info;
    nodo *sgte;
};
void agregarprimero(nodo *&lista, int valor);
int eliminarprimero(nodo *&lista);
void liberar(nodo *&lista);
void mostrar(nodo *lista);
void insertarordenado(nodo *&lista, int valor);
nodo *buscar(nodo *lista, int valor);
void buscarymostrar(nodo *lista, int valor);
int main(){
    nodo *listaX=NULL;

    insertarordenado(listaX,7);
    insertarordenado(listaX,8);
    insertarordenado(listaX,9);
    insertarordenado(listaX,10);

    buscarymostrar(listaX,8);
    mostrar(listaX);
    liberar(listaX);

    return 0;
}

void agregarprimero(nodo *&lista, int valor){
    nodo *nuevo=new nodo();
    nuevo->info=valor;
    nuevo->sgte=lista;
    lista=nuevo;
}
int eliminarprimero(nodo *&lista){
    int ret;
    ret=lista->info;
    nodo *aux=lista;
    lista=aux->sgte;
    delete (aux);
    return ret;
}
void liberar(nodo *&lista){
    nodo *aux;
    while(lista!=NULL){
        aux=lista;
        lista=aux->sgte;
        delete (aux);
    }
}
void mostrar(nodo *lista){
    nodo *aux=lista;
    while(aux!=NULL){
        cout<<aux->info<<endl;
        aux=aux->sgte;
    }
}
void insertarordenado(nodo *&lista, int valor){
    nodo *nuevo=new nodo();
    nuevo->info=valor;
    nuevo->sgte=NULL;
    nodo *ant=NULL;
    nodo *aux=lista;
    while(aux!=NULL && aux->info<valor){
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
nodo *buscar(nodo *lista, int valor){
    nodo *aux=lista;
    while(aux!=NULL && aux->info!=valor){
        aux=aux->sgte;
    }
    return aux;
}
void buscarymostrar(nodo *lista, int valor){
    nodo *aux=lista;
    while(aux!=NULL && aux->info!=valor){
        aux=aux->sgte;
    }
    if(aux==NULL){
        cout<<"No se encontro el valor"<<endl;
    }
    else{
        cout<<"se encontro: "<<aux->info<<endl;
    }

}
