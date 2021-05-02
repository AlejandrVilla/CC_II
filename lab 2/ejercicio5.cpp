//ejercicio 5
#include <iostream>

using namespace std;

void concatena(char cadena1[],char cadena2[]){
    int j=0;            //indice para cadena 2
    for (int i=0;;i++){
        if(cadena1[i]=='\0'){           //si llego al caracter nulo de cadena1
            cadena1[i]=cadena2[j];       //añade un caracter de cadena2 al final de cadena1
            cadena1[i+1]='\0';            //añade el caracter nulo a cadena1
            j++;                        //aumenta el contador para cadena2
        }
        if(cadena2[j]=='\0')        //llego al caracter nulo de cadena2
            break;                  //termina

    }
}

int main()
{
    char cadenaA[100];
    char cadenaB[100];
    cout<<"ingrese la primera palabra: ";gets(cadenaA);
    cout<<"ingrese la segunda palabra: ";gets(cadenaB);
    cout<<cadenaA<<endl;
    cout<<cadenaB<<endl;
    concatena(cadenaA,cadenaB);
    cout<<cadenaA;

    return 0;
}
