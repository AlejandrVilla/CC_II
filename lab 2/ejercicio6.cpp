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

void quickSort(string*&A,int a,int n){      //ordena el arreglo, funciona con elementos repetidos
    string pivote=A[(a+n)/2];
    int i=a;                //ubica i al comienzo
    int j=n-1;              //ubica j al final
    int k=(a+n)/2;          //guarda la posicion de pivote
    string temp;

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

void escribir(string dir,string*A,int n){       //crea un archivo txt con el arreglo de cadenas ordenado
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
    string* arreglo=new string[n];
    //lee un archivo txt y saca las primeras n palabras
    llenar(arreglo,n,"texto.txt");
/*
    for (int i=0;i<n;i++){      //ingresar cadenas por teclado
        cout<<"palabra: ";getline(cin,arreglo[i]);
    }*/

    //mostrar(arreglo,n);
    quickSort(arreglo,0,n);             
    //bubbleSort(arreglo,n);              
    //mostrar(arreglo,n);
    escribir("textoOrdenado.txt",arreglo,n);

    delete [] arreglo;

    return 0;
}
