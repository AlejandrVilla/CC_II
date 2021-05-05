//ejercicio 3
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//demora demasiado
unsigned long int *countingSort(unsigned long int *arreglo,int longitud){       //devuelve un puntero hacia el arreglo ordenado
    unsigned long int rango=0;
    for (int i=0;i<longitud;i++)        //encuentra el numero mayor en el arreglo
        if (arreglo[i]>rango)
            rango=arreglo[i];           //guarda el numero mayor en "rango"

    int *arregloIndices = new int[rango+1];          //creo un vector de tama�o "rango"
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

    unsigned long int *arregloSalida=new unsigned long int[longitud];       //nuevo arreglo ordenado

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
    delete [] arregloIndices;
    return arregloSalida;
}
//demora poco, casi nada
void quickSort(unsigned long int *&A,int a,int n){     //funciona con elementos repetidos
    unsigned long int pivote=A[((a+n)/2)];
    int i=a;                //ubica i al comienzo
    int j=n-1;              //ubica j al final
    int k=(a+n)/2;          //guarda la posicion de pivote
    unsigned long int temp;

    if (i==j)
        return;
    else{
        while(i!=j && i<j){     //mientras j e i no se hallan cruzado
            if (A[i]<pivote)        // si es menor
                i++;                //aumenta el indice
            else if (A[i]>=pivote){     //si es mayor
                while (i!=j){
                    if (A[j]>pivote)    //si es mayor
                        j--;            //disminuye el indice
                    else if (A[j]<=pivote){     //si es menor hace el cambio
                        temp=A[i];
                        A[i]=A[j];
                        A[j]=temp;
                        if (i==k){      //si i esta en la posicion de pivote
                            k=j;        //guarda la nueva posicion del pivote
                            i++;        //i aumenta
                            break;
                        }
                        else if(j==k){      //si j esta en la posicion de pivote
                            k=i;        //guarda la nueva posicion del pivote
                            j--;        //j disminuye
                            break;
                        }
                        else{   
                            i++;        //i aumenta
                            j--;        //j disminuye
                            break;
                        }
                    }
                }
            }
        }
        if (k==a)                //si pivote esta en la primera posicion, todos a su derecha son mayores
            quickSort(A,k+1,n); //ordena a la derecha de pivote
        else if(k==n-1)             //si pivote esta en la ultima posicion, todos a su izquierda son menores
            quickSort(A,a,n-1);     //ordena a la izquierda de pivote
        else{                       //si pivote esta en alguna posicion entre el primer y ultimo elemento
            quickSort(A,a,k);        //ordena a la izquierda de pivote
            quickSort(A,k,n);        //ordena a la derecha de pivote
        }
    }
}

void iniciarArreglo(unsigned long int*&A,int n){
    unsigned long int aleatorio, DESDE=10000000, HASTA=99999999;
    srand(time(NULL));          //fija el punto de comienzo
    for (int i=0;i<n;i++){
        aleatorio = rand()%(HASTA-DESDE+1)+DESDE;   //ejemplo, empieza en 20 hasta (30-20+1=31) -> 20 - 30
        //aleatorio = rand()%HASTA+DESDE;     //ejemplo, empieza en 20 hasta (20+30=50) -> 20 - 49
        A[i]=aleatorio;
    }
}

void mostrar(unsigned long int*A,int longitud){
    for (int i=0;i<longitud;i++)
        cout<<A[i]<<'\t';
    cout<<'\n';
}

void escribir(string dir,unsigned long int*A,int n){
    ofstream f;
    f.open(dir);
        for (int i=1;i<=n;i++){
            f<<A[i-1]<<" ";
            if (i%50==0)
                f<<'\n';
        }
    f.close();
}

int main()
{
    int n=1000000;
    unsigned long int *arreglo=new unsigned long int[n];
    unsigned long int *arregloOrdenado{nullptr};
    iniciarArreglo(arreglo,n);
    //mostrar(arreglo,n);
    quickSort(arreglo,0,n);
    escribir("arregloOrenado.txt",arreglo,n);
    //arregloOrdenado=countingSort(arreglo,n);
    //mostrar(arreglo,n);
    //mostrar(arregloOrdenado,n);

    delete [] arreglo;
    delete [] arregloOrdenado;

    return 0;
}
