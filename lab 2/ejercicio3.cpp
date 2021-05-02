//ejercicio 3
#include <iostream>
#include <ctime>

using namespace std;

int *countingSort(int *arreglo,int longitud){       //devuelve un puntero hacia el arreglo ordenado
    int rango=0;
    for (int i=0;i<longitud;i++)        //encuentra el numero mayor en el arreglo
        if (arreglo[i]>rango)
            rango=arreglo[i];           //guarda el numero mayor en "rango"

    int arregloIndices[rango+1];          //creo un vector de tama�o "rango"
    int contador;                       //guarda las incidencias

    for (int i=0;i<rango+1;i++){
        contador=0;
        for (int j=0;j<longitud;j++){
            if (i==arreglo[j])
                contador++;             //cuenta las veces que aparece un numero en arreglo
        }
        arregloIndices[i]=contador;     //llena arregloindices con la cantidad de incidencias
    }

    for (int i=1;i<rango+1;i++)
        arregloIndices[i]+=arregloIndices[i-1]; //reescribe el valor en la posicion i actual + anterior

    int *arregloSalida=new int[longitud];       //nuevo arreglo ordenado

    for (int i=0;i<longitud;i++){       //recorre el arreglo original
        for (int j=0;j<rango+1;j++){      //recorre el arreglo de indices
            if (arreglo[i]==j){           //busca el valor de arreglo en los indices de arregloIndices
                arregloSalida[arregloIndices[j]-1]=arreglo[i];      //copia el valor de arreglo en arreglo salida
                                                                    //usando como indice el valor de arregloIndices
                                                                    //en la posicion j (que es el valor de arreglo[i])
                arregloIndices[j]--;        //disminuye el valor para evitar reescribir un valor
            }
        }
    }
    return arregloSalida;
}

void iniciarArreglo(int*&A,int n){
    int aleatorio, DESDE=1, HASTA=10;
    srand(time(NULL));          //fija el punto de comienzo
    for (int i=0;i<n;i++){
        aleatorio = rand()%(HASTA-DESDE+1)+DESDE;   //ejemplo, empieza en 20 hasta (30-20+1=31) -> 20 - 30
        //aleatorio = rand()%HASTA+DESDE;     //ejemplo, empieza en 20 hasta (20+30=50) -> 20 - 49
        A[i]=aleatorio;
    }
}

void mostrar(int*A,int longitud){
    for (int i=0;i<longitud;i++)
        cout<<A[i]<<'\t';
    cout<<'\n';
}

int main()
{
    int n=10;
    int *arreglo=new int[n];
    int *arregloOrdenado{nullptr};
    iniciarArreglo(arreglo,n);
    arregloOrdenado=countingSort(arreglo,n);

    mostrar(arreglo,n);
    mostrar(arregloOrdenado,n);

    delete [] arreglo;
    delete [] arregloOrdenado;

    return 0;
}
