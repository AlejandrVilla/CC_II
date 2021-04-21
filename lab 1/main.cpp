#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
/*
//ejercicio 1
int sumaMultiplos(int x){
    int sum=0;      //acumulador
    for (int i=0;i<x;i++){
        if (i%3==0 || i%5==0){  //si es divisible entre 3 y 5
            sum+=i;
        }
    }
    return sum;
}

int main()
{
    int num;
    cout<<"ingrese un numero: ";
    cin>>num;
    cout<<"la suma de todos los multiplos de 3 y 5 menores que "<<num   <<" es: "<<sumaMultiplos(num)<<endl;
    return 0;
}*/

/*
//ejercicio 2
int sumaEnterosFibo(){
    int anterior=1;     // n-1
    int num=1;          //n
    int aux;            //auxiliar guarda num
    int sum=0;

    for (int i=0;num<4000000;i++){
        if (num%2==0){  //es par
            sum+=num;   //se agrega a la suma
        }
        aux=num;
        num+=anterior;
        anterior=aux;
    }
    return sum;
}

int main(){

    cout<<"la suma de los pares es: "<<sumaEnterosFibo()<<endl;


    return 0;
}*/

//ejercicio 3
bool esPrimo(long long int x){
    for (long long int i=2 ; i<x/2 ; i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

long long int mayorFacPrimo(long long int num){
    long long int mayor=0;
    for (long long int i=2;i<=num/2;i++){
        if (esPrimo(i))
            if (num%i==0)
                mayor=i;
    }
    return mayor;
}

int main(){
    long long int num;
    cout<<"ingrese el numero: ";
    cin>>num;

    cout<<endl<<"el mayor factor primo de "<<num<<" es: "<<mayorFacPrimo(num); //6857

    return 0;
}

/*
//ejercicio 4

string invertir(string num){    //numero se ingresa como cadena
    string invertido;           //nueva cadena, guarda la cadena invertida
    for (int i= num.size()-1;i>=0;i--)
        invertido+=num[i];
    return invertido;
}

bool esPalindromo(string num){
    string numInv=invertir(num);
    if (num==numInv)    //si es igual a su invertido
        return true;
    return false;
}

void mayorPalindromo(){
    int producto;       //guarda el producto de numeros de tres digitos
    int mayor=0;        //guarda el mayor producto
    int maxI,maxJ;      //guarda los numeros que generan el mayor producto
    for (int i=100;i<1000;i++){
        for (int j=100;j<i;j++){
            producto=i*j;
            if ( esPalindromo(to_string(producto)) )    //si es palindromo
                if (producto>mayor){
                    mayor=producto;     //guarda el producto mayor
                    maxI=i;
                    maxJ=j;
                }
        }
    }
    cout<<mayor<<" "<<maxI<<" "<<maxJ<<endl;
}

int main(){
    mayorPalindromo();  //906609 913 993

    return 0;
}*/


//ejercicio 5
/*
long int multiploMasPeque(int inf, int sup){
    int cont=0;
    for (long int i=1;;i++){
        cout<<i<<endl;
        for (long int j=inf;j<=sup;j++){
            if (i%j==0)
                cont++;
        }
        if (cont==sup)
            return i;
        else
            cont=0;
    }
}*/
/*
int multiploMasPeque(int inf, int sup){
    for (int i=1;;i++)
        if (i%1==0 && i%2==0 && i%3==0 && i%4==0 && i%5==0)
            if (i%6==0 && i%7==0 && i%8==0 && i%9==0 && i%10==0)
                if (i%11==0 && i%12==0 && i%13==0 && i%14==0 && i%15==0)
                    if (i%16==0 && i%17==0 && i%18==0 && i%19==0 && i%20==0)
                        return i;
}

int main(){
    cout<<multiploMasPeque(1,20);   //232792560

    return 0;
}*/

/*
//ejercicio 6

int sumaNaturales(int x){
    int sum=x*(x+1)/2;  //calcula la suma de x numeros
    return sum;
}

int sumaCuadrados(int x){
    int sum=x*(x+1)*(2*x+1)/6;      //calcula la suma de los cuadrados de x numeros
    return sum;
}

int main(){
    int x=100;
    int resultado=pow(sumaNaturales(x),2)-sumaCuadrados(x); //eleva al cuadrado y realiza la resta
    cout<<resultado<<endl;      //25164150

    return 0;
}*/

/*
//ejercicio 7

bool esPrimo(int num){      //determina si un numero es primo
    for (int i=2;i<num;i++)
        if (num%i==0)
            return false;
    return true;
}

int encuentraPrimo(int n){
    int num=2;      //empieza con el primer numero primo
    int i=0;        //indice de los numeros primos
    while(true){
        if (esPrimo(num))
            i++;    //aumenta el indice para indicar la posicion de num
        if (i==n)   //si se llego a la posicion n
            return num; //devuelve el numero primo en la posicion i
        num++;      //incrementa el numero
    }
}

int main(){
    cout<<encuentraPrimo(10001);     //104743

    return 0;
}*/

//ejercicio 8

/*
int numero[1000];       //vector que guarda los 1000 digitos

void llenar(string dir){    //lee los digitos de un archivo txt
    ifstream f;
    f.open(dir);
        for (int i=0;i<1000;i++)
            f>>numero[i];   //guarda cada digito en el vector
    f.close();
}

void mostrar(){         //muestra el numero
    for (int i=0;i<1000;i++)
        cout<<numero[i];
}
long long int productoAdyacentes(int largo){    //realiza el producto de los adyacentes
    long long int prodMayor=0;          //guarda el mayor producto encontrado
    long long int prod;                 //guarda el producto de adyacentes
    for (int i=0;i<=1000-largo;i++){
        prod=1;
        for (int j=0;j<largo;j++){
                prod*=numero[j+i];      //acumumla el producto
        }
        if (prod>prodMayor)
            //cout<<prodMayor<<endl;
            prodMayor=prod;
    }
    return prodMayor;
}

int main(){
    llenar("D:\\archivos personales\\documentos\\C++\\CC II\\semana 2\\sesion 1\\lab 1\\numero.txt");
    mostrar();
    cout<<endl<<productoAdyacentes(13)<<endl;   //23514624000

    return 0;
}*/

//ejercicio 9
/*
int triplePitagorico(int x){
    for (int a=1;a<1000;a++){       //a va de 1 a 999
        for (int b=1;b<1000;b++){       //b va de 1 a 999
            for (int c=1;c<1000;c++){       //c va de 1 a 999
                if (a<b && b<c){
                    if (a+b+c==1000 && pow(c,2)==pow(a,2)+pow(b,2))
                        return a*b*c;
                }
            }
        }
    }
}

int main(){
    cout<<triplePitagorico(1000);   //31875000

    return 0;
}*/

/*
//ejercicio 10

bool esPrimo(long int num){     //determina si un numero es primo
    for (long int i=2;i<num;i++)
        if (num%i==0)
            return false;
    return true;
}

long long int encuentraPrimo(long int n){
    long int num=2;                 //empieza con el primero numero primo
    long long int suma=0;           //acumula la suma de primos
    while(num<n){                   //mientras sea menor que el numero especificado
        if (esPrimo(num)){
            suma+=num;              //acumula la suma
            //cout<<suma<<endl;
        }
        num++;                      //num aumenta
    }
    return suma;
}

int main(){
    cout<<encuentraPrimo(2000000);  //142913828922

    return 0;
}*/
/*
//ejercicio 11

void leer(int **M,string dir){  //lee la matriz desde un archivo
    ifstream f;
    f.open(dir);
        for (int i=0;i<20;i++)
            for (int j=0;j<20;j++)
                f>>M[i][j];
    f.close();
}

void mostrar(int **M,int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<M[i][j]<<'\t';
        cout<<endl;
    }
}

long long int mayorProducto(int **M){
    int submatriz[4][4];
    //int*submatriz;
    long long int producto1;    //halla el producto de arribo hacia abajo
    long long int producto2;    //halla el producto de derecha a izquierda
    long long int producto3;    //halla el producto en la diagonal principal
    long long int producto4;    //halla el producto en la diagonal secundaria
    long long int mayorProd=0;  //halla el mayor producto
    for (int i=0;i<=16;i++){
        for (int j=0;j<=16;j++){
            producto1=1;
            producto2=1;
            producto3=1;
            producto4=1;
            for (int k=0;k<4;k++){
                producto1*=M[i][j+k];       //acumula el producto en vertical desde la esquina superior izquierda
                producto2*=M[i+k][j+k];     //acumula el producto en horizontal desde la esquina superior izquierda
                producto3*=M[i+k][j];       //acumula el producto en la diagonal principal
                producto4*=M[i+3-k][j+k];   //acumula el producto en la diagonal secundaria
            }
            if (producto1>producto2 && producto1>producto3  && producto1>producto4 && producto1>mayorProd)
                mayorProd=producto1;

            else if (producto2>producto1 && producto2>producto3  && producto2>producto4 && producto2>mayorProd)
                mayorProd=producto2;

            else if (producto3>producto2 && producto3>producto1  && producto3>producto4 && producto3>mayorProd)
                mayorProd=producto3;

            else if (producto4>producto1 && producto4>producto2  && producto4>producto3 && producto4>mayorProd)
                mayorProd=producto4;
        }
    }
    return mayorProd;
}

int main(){
    int **matriz=new int*[20];
    for (int i=0;i<20;i++)
        matriz[i]=new int[20];

    leer(matriz,"D:\\archivos de programa\\github\\CC_II\\lab 1\\matrizProducto.txt");
    //mostrar(matriz,20);
    cout<<mayorProducto(matriz);        //70600674

    for (int i=0;i<20;i++)
        delete [] matriz[i];
    delete [] matriz;

    return 0;
}*/

//ejercicio 12
/*
int cantDivisores(int num){     //devuelve la cantidad de divisores de cada numero

    //int contador=0;
    //for(int i=1;i<=num;i++){
    //    if (num%i==0)
    //       contador++;
    //}
    //return contador;

    int contador=1;         //cuenta las veces que se dividio por un mismo numero
    int acumulador=1;       //acumula la cantidad de divisores
    int i=2;

    while(true){
        if (num%i==0){      //si es divisible por i
            num/=i;         //se divide entre i
            contador++;     //aumenta el contador
        }
        else{
            acumulador*=contador;   //multiplica el contador
            i++;                    //aumenta i
            contador=1;             //contador se reinicia
        }
        if(num==1){                 //si numero se descompuso hasta 1
            acumulador*=contador;   //acumula una vez mas
            break;
        }
    }
    return acumulador;
}

int numeroTriagulo(int n){
    return n*(n+1)/2;           //realiza la suma de n numeros
}

int primeroConMasDivisores(int n){
    int num;            //numero triangular
    int i=1;            //indice de cada numero triangular
    while(true){
        num=numeroTriagulo(i);          //halla el numero triangular en la posicion i
        //cout<<num<<endl;
        if (cantDivisores(num)>n)       //paso el limite n
            return num;
        i++;                            //aumenta el indice
    }
}

int main(){
    cout<<primeroConMasDivisores(500);      //76576500
    return 0;
}*/

/*
//ejercicio 13

string numeros[100]={       //arreglo de 100 cadenas que representan a los numeros
            "37107287533902102798.797998220837590246510135740250",
            "46376937677490009712.648124896970078050417018260538",
            "74324986199524741059.474233309513058123726617309629",
            "91942213363574161572.522430563301811072406154908250",
            "23067588207539346171.171980310421047513778063246676",
            "89261670696623633820.136378418383684178734361726757",
            "28112879812849979408.065481931592621691275889832738",
            "44274228917432520321.923589422876796487670272189318",
            "47451445736001306439.091167216856844588711603153276",
            "70386486105843025439.939619828917593665686757934951",
            "62176457141856560629.502157223196586755079324193331",
            "64906352462741904929.101432445813822663347944758178",
            "92575867718337217661.963751590579239728245598838407",
            "58203565325359399008.402633568948830189458628227828",
            "80181199384826282014.278194139940567587151170094390",
            "35398664372827112653.829987240784473053190104293586",
            "86515506006295864861.532075273371959191420517255829",
            "71693888707715466499.115593487603532921714970056938",
            "54370070576826684624.621495650076471787294438377604",
            "53282654108756828443.191190634694037855217779295145",
            "36123272525000296071.075082563815656710885258350721",
            "45876576172410976447.339110607218265236877223636045",
            "17423706905851860660.448207621209813287860733969412",
            "81142660418086830619.328460811191061556940512689692",
            "51934325451728388641.918047049293215058642563049483",
            "62467221648435076201.727918039944693004732956340691",
            "15732444386908125794.514089057706229429197107928209",
            "55037687525678773091.862540744969844508330393682126",
            "18336384825330154686.196124348767681297534375946515",
            "80386287592878490201.521685554828717201219257766954",
            "78182833757993103614.740356856449095527097864797581",
            "16726320100436897842.553539920931837441497806860984",
            "48403098129077791799.088218795327364475675590848030",
            "87086987551392711854.517078544161852424320693150332",
            "59959406895756536782.107074926966537676326235447210",
            "69793950679652694742.597709739166693763042633987085",
            "41052684708299085211.399427365734116182760315001271",
            "65378607361501080857.009149939512557028198746004375",
            "35829035317434717326.932123578154982629742552737307",
            "94953759765105305946.966067683156574377167401875275",
            "88902802571733229619.176668713819931811048770190271",
            "25267680276078003013.678680992525463401061632866526",
            "36270218540497705585.629946580636237993140746255962",
            "24074486908231174977.792365466257246923322810917141",
            "91430288197103288597.806669760892938638285025333403",
            "34413065578016127815.921815005561868836468420090470",
            "23053081172816430487.623791969842487255036638784583",
            "11487696932154902810.424020138335124462181441773470",
            "63783299490636259666.498587618221225225512486764533",
            "67720186971698544312.419572409913959008952310058822",
            "95548255300263520781.532296796249481641953868218774",
            "76085327132285723110.424803456124867697064507995236",
            "37774242535411291684.276865538926205024910326572967",
            "23701913275725675285.653248258265463092207058596522",
            "29798860272258331913.126375147341994889534765745501",
            "18495701454879288984.856827726077713721403798879715",
            "38298203783031473527.721580348144513491373226651381",
            "34829543829199918180.278916522431027392251122869539",
            "40957953066405232632.538044100059654939159879593635",
            "29746152185502371307.642255121183693803580388584903",
            "41698116222072977186.158236678424689157993532961922",
            "62467957194401269043.877107275048102390895523597457",
            "23189706772547915061.505504953922979530901129967519",
            "86188088225875314529.584099251203829009407770775672",
            "11306739708304724483.816533873502340845647058077308",
            "82959174767140363198.008187129011875491310547126581",
            "97623331044818386269.515456334926366572897563400500",
            "42846280183517070527.831839425882145521227251250327",
            "55121603546981200581.762165212827652751691296897789",
            "32238195734329339946.437501907836945765883352399886",
            "75506164965184775180.738168837861091527357929701337",
            "62177842752192623401.942399639168044983993173312731",
            "32924185707147349566.916674687634660915035914677504",
            "99518671430235219628.894890102423325116913619626622",
            "73267460800591547471.830798392868535206946944540724",
            "76841822524674417161.514036427982273348055556214818",
            "97142617910342598647.204516893989422179826088076852",
            "87783646182799346313.767754307809363333018982642090",
            "10848802521674670883.215120185883543223812876952786",
            "71329612474782464538.636993009049310363619763878039",
            "62184073572399794223.406235393808339651327408011116",
            "66627891981488087797.941876876144230030984490851411",
            "60661826293682836764.744779239180335110989069790714",
            "85786944089552990653.640447425576083659976645795096",
            "66024396409905389607.120198219976047599490197230297",
            "64913982680032973156.037120041377903785566085089252",
            "16730939319872750275.468906903707539413042652315011",
            "94809377245048795150.954100921645863754710598436791",
            "78639167021187492431.995700641917969777599028300699",
            "15368713711936614952.811305876380278410754449733078",
            "40789923115535562561.142322423255033685442488917353",
            "44889911501440648020.369068063960672322193204149535",
            "41503128880339536053.299340368006977710650566631954",
            "81234880673210146739.058568557934581403627822703280",
            "82616570773948327592.232845941706525094512325230608",
            "22918802058777319719.839450180888072429661980811197",
            "77158542502016545090.413245809786882778948721859617",
            "72107838435069186155.435662884062257473692284509516",
            "20849603980134001723.930671666823555245252804609722",
            "53503534226472524250.874054075591789781264330331690"};

string suma10PrimerosDigitos(){
    long double suma=0;
    string num;
    for (int i=0;i<100;i++){
        suma+=stold(numeros[i]);    //lee cada elemento del arreglo y lo convierte en long double
    }                               //acumula la suma
    num=to_string(suma);            //convierte a string la suma
    return num.substr(0,10);        //devuelve los 10 primeros digitos
}

int main(){
    cout<<suma10PrimerosDigitos();  //5537376230

    return 0;
}*/

/*
//ejercicio 14

long int collatzMasLarga(){
    long int contador;  //acumula la cantidad de terminos hasta llegar a 1
    long int mayor=0;   //guarda el mayor contador
    long long int num;  //num a operar
    long int may;       //numero que genera la cola mas larga

    for (long long int i=1;i<1000000;i++){
        contador=1;         //contador se inicializa en 1
        num=i;              //num se reescribe
        while (num!=1){         //mientras num diferente de 1
            if (num%2==0){      //si es par
                num=num/2;
                contador++;     //aumenta contador
            }
            else{               //si es impar
                num=3*num+1;
                contador++;     //aumenta contador
            }
        }
        //cout<<i<<" = "<<contador<<endl;
        if (contador>mayor){
            mayor=contador;     //guarda el numero contador mayor
            may=i;              //guarda el numero que genera la cola mas larga
        }
    }
    return may;
}

int main(){
    cout<<collatzMasLarga();    //837799

    return 0;
}*/

/*
//ejercicio 15

void crear(long long int **&M,int n){   //crea una matriz de (n+1)*(n+1)
    M=new long long int*[n+1];
    for (int i=0;i<n+1;i++)
        M[i]=new long long int[n+1];
}

long long int cantRecorridos(long long int **M,int n){
    for (int i=0;i<n+1;i++){        //rellena la primera fila y primera columna con 1
        M[0][i]=1;
        M[i][0]=1;
    }
    for (int i=1;i<n+1;i++){                //calcula el resto de celdas de la matriz
        for (int j=1;j<n+1;j++){
            M[i][j]=M[i][j-1]+M[i-1][j];     //suma el de arriba y el de atras
        }
    }
    return M[n][n];         //devuelve el valor de la ultima celda
}

void mostrar(long long int **M,int n){      //muestra la matriz
    for (int i=0;i<n+1;i++){
        for (int j=0;j<n+1;j++){
            cout<<M[i][j]<<'\t';
        }
        cout<<'\n';
    }
}

void destruir(long long int **&M,int n){
    for (int i=0;i<n;i++)
        delete [] M[i];
    delete [] M;
}

int main(){
    long long int **matriz;
    int n=20;
    crear(matriz,n);                // separa el espacio en memoria para la matriz
    cout<<cantRecorridos(matriz,n)<<endl;   //137846528820
    //mostrar(matriz,n);
    destruir(matriz,n);
    //mostrar(matriz,n);

    return 0;
}*/



