#include<iostream>
using namespace std;
struct nodo{
    int info;
    nodo *sgte;
};
void encolar(nodo *&cfte, nodo *&cfin, int valor);
int desencolar(nodo *&cfte, nodo *&cfin);
int main(){
    nodo *colafte=NULL;
    nodo *colafin=NULL;
    int carga;

    cout<<"Ingrese los valores a cargar en la cola o 0 para terminar: "<<endl;
    cin>>carga;

    while(carga!=0){
        encolar(colafte,colafin,carga);
        cout<<"Ingrese los valores a cargar en la cola o 0 para terminar: "<<endl;
        cin>>carga;
    }

    int rdo;
    while(colafte!=NULL){
        rdo=desencolar(colafte,colafin);
        cout<<rdo<<endl;
    }

    return 0;

}
void encolar(nodo *&cfte, nodo *&cfin, int valor){
    nodo *nuevo = new nodo();
    nuevo->info=valor;
    nuevo->sgte=NULL;
    if(cfte==NULL){
        cfte=nuevo;
    }
    else{
        cfte->sgte=nuevo;
    }
    cfin=nuevo;
}
int desencolar(nodo *&cfte, nodo *&cfin){
    int ret;
    ret=cfte->info;
    nodo *aux=cfte;
    cfte=aux->sgte;
    if(cfte==NULL){
        cfin=NULL;
    }
    delete aux;
    return ret;
}
