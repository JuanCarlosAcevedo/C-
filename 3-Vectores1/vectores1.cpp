#include <iostream>
using namespace std;

void insertar(int vec[], int &len, int valor, int pos);
void insertarordenado(int vec1[], int &len1, int valor1);
void mostrar(int vec2[], int len2);
void inicializar(int vec3[], int cantpos, int valorini);
int buscar(int vec4[], int len4, int valor4);
void eliminar(int vec5[], int &len5, int pos5);

int main(){
    //1-definimos el vector
    int array[5];
    int len=0;
    int n,m;
    int cont=0;
    //2-cargamos el vector
    inicializar(array, 5, 0);
    mostrar(array, 5);
    //3-cargamos el vector con insertar ordenado
    cout<<"Ingrese los valores a cargar o 0 para terminar: "<<endl;
    cin>>n;

    while(n!=0 && cont<5){
        insertarordenado(array, len, n);
        cont++;
        cout<<"Ingrese los valores a cargar o 0 para terminar: "<<endl;
        cin>>n;
    }
    mostrar(array, len);
    //4-buscar un valor y eliminarlo
    cout<<"Ingrese el numero que quiere buscar: "<<endl;
    cin>>n;
    m=buscar(array, len, n);
    if(m!=-1){
        eliminar(array, len, m);
    }
    //5-mostrar
    mostrar(array,len);

    return 0;

}

void insertar(int vec[], int &len, int valor, int pos){
    for(int i=len; i>pos; i--){
        vec[i]=vec[i-1];
    }
    vec[pos]=valor;
    len++;
}

void insertarordenado(int vec1[], int &len1, int valor1){
    int i=0;
    while(i<len1 && vec1[i]<=valor1){
        i++;
    }
    if(i==len1){
        vec1[len1]=valor1;
        len1++;
    }
    else{insertar(vec1, len1, valor1, i);}
}

void mostrar(int vec2[], int len2){
    for(int i=0; i<len2; i++){
        cout<<"La poscision: "<<i<<" tiene como valor: "<<vec2[i]<<endl;
    }
}

void inicializar(int vec3[], int cantpos, int valorini){
    for(int i=0; i<cantpos; i++){
        vec3[i]=valorini;
    }
}

int buscar(int vec4[], int len4, int valor4){
    int i=0;
    while(i<len4 && vec4[i]!=valor4){
        i++;
    }
    if(i==len4){
        return -1;
    }
    else return i;
}

void eliminar(int vec5[], int &len5, int pos5){
    for(int i=pos5; i<len5-1; i++){
        vec5[i]=vec5[i+1];
    }
    len5--;
}
