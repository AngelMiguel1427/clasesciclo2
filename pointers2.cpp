#include iostream>
using namespace std;
int main(){

    int numeros [3] = {1, 2, 3};
    int *p = numeros;//puntero al primer elemento del arreglo

    for ( int i = 0 ; i < 3; i++){
        cout <<"Elemento: " << *(p+i) << endl;
    }
    return 0;
}