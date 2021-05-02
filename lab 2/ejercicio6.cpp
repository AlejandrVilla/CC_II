//ejercicio 6
#include <iostream>
#include <fstream>

using namespace std;

void llenar(string*&A,int n,string dir){    //funcion llena el arreglo leyendo un archivo
    ifstream f;
    f.open(dir);
        for (int i=0;i<n;i++)
            f>>A[i];
    f.close();
}

void quickSort(string*&A,int a,int n){      //ordena el arreglo, no funciona con elementos repetidos
    string pivote=A[((a+n)/2)-1];
    int i=a;
    int j=n-1;
    string temp;

    if (j==i)
        return;
    else{
        while(i!=j && j>i){     //mientras j e i no se hallan cruzado
            if (A[i]<pivote)        // si es menor
                i++;                //aumenta el indice
            else if (A[i]>=pivote){     //si es mayor
                while (true){
                    if (A[j]>pivote)    //si es mayor
                        j--;            //disminuye el indice
                    else if (A[j]<=pivote){     //si es menor hace el cambio
                        temp=A[i];
                        A[i]=A[j];
                        A[j]=temp;
                        break;
                    }
                }
            }
        }
        quickSort(A,a,int((a+n)/2));        //llamada recursiva
        quickSort(A,int((a+n)/2),n);        //llamada recursiva
    }
}


void bubbleSort(string*&A,int n){       //funcion ordena arreglo, funciona con elementos repetidos
    string temp;
    for (int i=n-1;i>0;i--){        //toma la ultima posicion
        for (int j=0;j<i;j++){      //recorre todos los elementos hasta i
            if (A[j]>A[j+1]){       //compara el actual con el siguiente
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

void mostrar (string*A,int n){
    for (int i=0;i<n;i++)
        cout<<A[i]<<'\t';
    cout<<'\n';
}

int main()
{
    int n=1000000;
    string* arreglo=new string[n];
    //lee un archivo txt y saca las primeras n palabras
    llenar(arreglo,n,"D:\\archivos personales\\documentos\\C++\\CC II\\semana 3\\lab 2\\ejercicia 6\\texto.txt");
/*
    for (int i=0;i<n;i++){
        cout<<"palabra: ";getline(cin,arreglo[i]);
    }*/

    mostrar(arreglo,n);
    //quickSort(arreglo,0,n);   //
    bubbleSort(arreglo,n);
    mostrar(arreglo,n);
    //cout<<arreglo[0];

    delete [] arreglo;

    return 0;
}
