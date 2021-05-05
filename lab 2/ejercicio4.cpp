//ejercicio 4
#include <iostream>
#include <string>

using namespace std;

int longitudIterativa(string cadena){
    for (int i=0;;i++)
        if (cadena[i]=='\0')    //si llego al caracter nulo
            return i;               //devuelve el tamaño
}

int longitudRecursiva(string cadena){
    if (cadena[0]=='\0')        //si llego al caracter nulo
        return 0;               //añade 0
    return 1+longitudRecursiva(cadena.substr(1,cadena.size()-1));     //suma 1 por cada caracter de manera recursiva
}

int main()
{
    string cadena;
    getline(cin,cadena);
    cout<<longitudIterativa(cadena)<<endl;
    cout<<longitudRecursiva(cadena)<<endl;

    return 0;
}
