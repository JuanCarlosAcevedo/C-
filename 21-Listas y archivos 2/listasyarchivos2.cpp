#include<iostream>
#include<stdio.h>

using namespace std;
struct tinfo{
    int hab;
    char tipo;
    int dias;
    int precio;
};
struct nodo{
  tinfo info;
  nodo *sgte;
};
void insertarordenado(nodo *&lista, tinfo valor);
void mostrar(nodo *lista);
void liberar(nodo *&lista);


int main(){
  FILE *verano;
  nodo *listaA=NULL;
  nodo *listaB=NULL;

  verano=fopen("verano.dat","rb");
  tinfo raux;
  fread(&raux,sizeof (struct tinfo),1,verano);

  while(!feof(verano)){
    insertarordenado(listaA,raux);
    if((raux.dias<50) && ((raux.tipo == 'S') || (raux.tipo == 'D'))){
      insertarordenado(listaB,raux);
    }
    fread(&raux,sizeof (struct tinfo),1,verano);
  }
  fclose(verano);

  verano=fopen("verano.dat","wb");
  nodo *aux=listaA;
  while(aux!=NULL){
    fwrite(&aux->info,sizeof (struct tinfo),1,verano);
    aux=aux->sgte;
  }
  fclose(verano);
  mostrar(listaB);
  liberar(listaA);
  liberar(listaB);

  return 0;
}

void insertarordenado(nodo *&lista, tinfo valor){
  nodo *nuevo=new nodo();
  nuevo->info.hab=valor.hab;
  nuevo->info.tipo=valor.tipo;
  nuevo->info.dias=valor.dias;
  nuevo->info.precio=valor.precio;
  nuevo->sgte=NULL;

  nodo *aux=lista;
  nodo *ant=NULL;

  while(aux!=NULL && aux->info.hab<valor.hab){
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
    cout<<aux->info.hab<<endl;
    cout<<aux->info.tipo<<endl;
    cout<<aux->info.dias<<endl;
    cout<<aux->info.precio<<endl;
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
