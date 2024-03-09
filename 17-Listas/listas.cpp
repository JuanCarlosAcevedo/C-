#include<iostream>
using namespace std;
struct nodo{
    int info;
    nodo *sgte;
};
void agregarprimero(nodo *&lista, int valor);
int eliminarprimero(nodo *&lista);
void mostrar(nodo *lista);
void liberar(nodo *&lista);

int main(){
    nodo *listaX=NULL;

    agregarprimero(listaX,1);
    agregarprimero(listaX,2);
    agregarprimero(listaX,3);

    mostrar(listaX);
    liberar(listaX);
    return 0;

}

void agregarprimero(nodo *&lista, int valor){
    nodo *nuevo = new nodo();
    nuevo->info=valor;
    nuevo->sgte=lista;
    lista=nuevo;
}

int eliminarprimero(nodo *&lista){
    int ret;
    ret=lista->info;
    nodo *aux=lista;
    lista=lista->sgte;
    delete (aux);
    return ret;
}

void mostrar(nodo *lista){
    nodo *aux=lista;
    while(aux!=NULL){
        cout<<aux->info<<endl;
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
