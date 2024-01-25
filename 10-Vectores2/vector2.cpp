//Teniendo ya un vector creado y cargado, procedemos a calcular lo solicitado (no se inicializara, ni se cargara)
#include<iostream>
using namespace std;

struct producto{
    int cod;
    int uni;
};

void max(producto vec1[], int len1);
void min(producto vec2[], int len2);
void suma(producto vec3[], int len3);

int main(){

    producto vc[150];
    int len;

    max(vc,len);
    min(vc,len);
    suma(vc,len);

    return 0;
    
}

void max(producto vec1[], int len1){
    int posmax=0;
    int may=vec1[0].uni;

    for(int i=1; i<len1; i++){
        if(vec1[i].uni>may){
            posmax=i;
            may=vec1[i].uni;
        }
    }
    cout<<"El producto con mas unidades es: "<<vec1[posmax].cod<<" con una cantidad de unidades de: "<<may<<endl;
}

void min(producto vec2[], int len2){
    int posmin=0;
    int min=vec2[0].uni;

    for(int i=1; i<len2; i++){
        if(vec2[i].uni<min){
            posmin=i;
            min=vec2[i].uni;
        }
    }
    cout<<"El producto con menos unidades es: "<<vec2[posmin].cod<<" con una cantidad de unidades de: "<<min<<endl;
}

void suma(producto vec3[], int len3){
    int sum=0;
    for(int i=0; i<len3; i++){
        sum = sum + vec3[i].uni;
    }
    cout<<"La cantidad de unidades es: "<<sum<<endl;
}
