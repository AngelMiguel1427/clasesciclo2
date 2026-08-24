//crear un array bidimensional 
#include <iostream>
using namespace std;
int main(){
    int n = 5 ;
    int matriz[n][n];
    for (int i = 0; i< n; i++){//llenar la matriz
        for (int j= 0; j < n; j++){
            matriz [i][j] = (i +1 ) * (j +1); 
        }
        cout << endl;
    }

    for (int i = 0; i< n; i++){//llenar la matriz
        for (int j= 0; j < n; j++){
            cout << matriz [i][j] << "\t";
        }
        cout << endl;
    }
  
}