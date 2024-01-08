#include <iostream>
using namespace std;

void inicializar(int vec[], int cantpos, int valorini);
void cargar(int vec1[], int &len1, int cantpos1);
void mostrar(int vec2[], int len2);
void suma(int vec3[], int len3);

int main(){
    int numeros[10];
    int len = 0;

    inicializar(numeros, 10, 0);
    cargar(numeros, len, 10);
    suma(numeros, len);
    mostrar(numeros, len);

    return 0;

}

void inicializar(int vec[], int cantpos, int valorini){
    for(int i=0; i<cantpos; i++){
        vec[i]=valorini;
    }
}

void cargar(int vec1[], int &len1, int cantpos1){
    for(int i=0; i<cantpos1; i++){
        cout<<"Ingrese el valor que desea cargar: "<<endl;
        cin>>vec1[i];
        len1++;
    }
}

void mostrar(int vec2[], int len2){
    for(int i=0; i<len2; i++){
        cout<<"La poscision: "<<i<<" del vector es: "<<vec2[i]<<endl;
    }
}

void suma(int vec3[], int len3){
    int sum = 0;
    for(int i=0; i<len3; i++){
        sum = sum + vec3[i];
    }
    cout<<"La suma de los vectores es: "<<sum<<endl;
}
