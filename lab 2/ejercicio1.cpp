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

long int sumaElementosIterativa(int*A,int n){       //suma los elementos de manera iterativa
    long int suma=0;
    for (int i=0;i<n;i++)       //avanza de uno en uno
        suma+=A[i];
    return suma;
}

long int sumaElementosRecursiva(int*A,int n){       //suma los elementos de manera recursiva
    //cout<<n<<endl;
    if (n==0){
        return 0;
    }
    return  A[n-1]+A[n-2]+A[n-3]+A[n-4]+A[n-5]+A[n-6]+A[n-7]+A[n-8]+A[n-9]+A[n-10]+
            A[n-11]+A[n-12]+A[n-13]+A[n-14]+A[n-15]+A[n-16]+A[n-17]+A[n-18]+A[n-19]+A[n-20]+
            A[n-21]+A[n-22]+A[n-23]+A[n-24]+A[n-25]+A[n-26]+A[n-27]+A[n-28]+A[n-29]+A[n-30]+
            A[n-31]+A[n-32]+A[n-33]+A[n-34]+A[n-35]+A[n-36]+A[n-37]+A[n-38]+A[n-39]+A[n-40]+
            A[n-41]+A[n-42]+A[n-43]+A[n-44]+A[n-45]+A[n-46]+A[n-47]+A[n-48]+A[n-49]+A[n-50]+
            sumaElementosRecursiva(A,n-50);
}

int main()
{
    int n=1000000;
    int*numeros=new int[n];
    iniciarArreglo(numeros,n);
    //mostrar(numeros,n);
    cout<<"la suma de elementos es: "<<sumaElementosIterativa(numeros,n)<<endl;
    cout<<"la suma de elementos es: "<<sumaElementosRecursiva(numeros,n)<<endl;
    delete [] numeros;

    return 0;
}
