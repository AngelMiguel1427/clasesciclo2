#include <iostream>
using namespace std;
void adjust_price(double *precios, int cantidad) {
 for(int i=0;   i<cantidad; i++){
    //Aumenta 10% de cada elemento 
        *(precios + i) += 1.10;
    }
}
    



int main() {
    //100,200,75,500,120
    double precios[]= {100,250,75,500,120};
    int cantidad= 5;
    adjust_price(precios, cantidad);
    cout << "Precios ajustados: ";
    cout << precios[0] << ", " << precios[1] << ", " << precios[2] << ", " << precios[3] << ", " << precios[4] << endl;





    return 0;
}