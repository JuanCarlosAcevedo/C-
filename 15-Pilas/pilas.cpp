#include<iostream>
using namespace std;
struct nodo{
    int info;
    nodo *sgte;
};
void push(nodo *&pila, int valor);
int pop(nodo *&pila);

int main(){
    nodo *pila=NULL;
    int carga;
    cout<<"Ingrese los valores a cargar en la pila o 0 para terminar: "<<endl;
    cin>>carga;

    while(carga!=0){
        push(pila,carga);
        cout<<"Ingrese los valores a cargar en la pila o 0 para terminar: "<<endl;
        cin>>carga;
    }

    int rdo;
    while(pila!=NULL){
        rdo=pop(pila);
        cout<<rdo<<endl;
    }

    return 0;
    
}

void push(nodo *&pila, int valor){
    nodo *nuevo = new nodo();
    nuevo->info=valor;
    nuevo->sgte=pila;
    pila=nuevo;
}

int pop(nodo *&pila){
    int ret;
    ret=pila->info;
    nodo *aux=pila;
    pila=aux->sgte;
    delete aux;
    return ret;
}
