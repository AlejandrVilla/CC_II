//ejercicio 2
#include <iostream>
#include <ctime>

using namespace std;

void iniciarArreglo(int*&A,int n){
    int aleatorio, DESDE=1, HASTA=10;
    srand(time(NULL));          //fija el punto de comienzo
    for (int i=0;i<n;i++){
        aleatorio = rand()%(HASTA-DESDE+1)+DESDE;   //ejemplo, empieza en 20 hasta (30-20+1=31) -> 20 - 30
        //aleatorio = rand()%HASTA+DESDE;     //ejemplo, empieza en 20 hasta (20+30=50) -> 20 - 49
        A[i]=aleatorio;
    }
}

void mostrar(int*A,int n){
    for (int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int* invertirIterativa(int* A,long int n){   //crea otro arreglo y devuelve su direccion de memoria
    int* invertido=new int[n];
    for (int i=0;i<=n/2;i++){
        invertido[i]=A[n-1-i];
        invertido[n-1-i]=A[i];
    }
    return invertido;
}

void invertirRecursiva(int *A,long int a,long int b){
    if (a==b)
        return;
    else{
        for (int i=0;i<50;i++){         // intercambia de 50 en 50
            int temp=A[a+i];
            A[a+i]=A[b-i-1];
            A[b-i-1]=temp; 
        }
        invertirRecursiva(A,a+50,b-50);
    }
}

bool comprobar(int* A1,int* A2,long int n){     //comprueba si los arreglos son iguales
    for (int i=0;i<=n/2;i++)
        if (A1[i]!=A2[i] && A1[n-1-i]!=A2[n-1-i])
            return false;
    return true;
}


int main()
{
    int n=1000000;
    int*numeros=new int[n];
    iniciarArreglo(numeros,n);
    int*numerosInvertidos1{nullptr};

    //mostrar(numeros,n);
    numerosInvertidos1=invertirIterativa(numeros,n);
    invertirRecursiva(numeros,0,n);
    //mostrar(numerosInvertidos1,n);
    //mostrar(numeros,n);

    if (comprobar(numeros,numerosInvertidos1,n))
        cout<<"los dos arreglos son iguales"<<endl;
    else
        cout<<"los dos arreglos son diferentes"<<endl;

    delete [] numerosInvertidos1;
    delete [] numeros;

    return 0;
}
