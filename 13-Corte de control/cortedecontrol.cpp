#include<iostream>
#include<stdio.h>

using namespace std;
struct multa{
    int dominio;
    int tipo;
    int imp;
};

int main(){
    FILE * mul;
    mul=fopen("multas.dat","rb");

    multa raux;
    int anterior;
    int sumaMultas;

    fread(&raux,sizeof(struct multa),1,mul);
    while(!feof(mul)){
        anterior=raux.dominio;
        sumaMultas=0;

        while((!feof(mul)) && (anterior==raux.dominio)){
            sumaMultas = sumaMultas + raux.imp;
            fread(&raux,sizeof(struct multa),1,mul);
        }
        cout<<"El dominio: "<<anterior<<" Tiene un total de multas de: "<<sumaMultas<<endl;
    }
    
    fclose(mul);
    return 0;

}
