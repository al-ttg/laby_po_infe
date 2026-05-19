#include <iostream>
#include <cmath>
using namespace std;
/*int main() {
    double arr[2][10];
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int j = 0; j < 10; j++) {
        double x = arr[0][j];
        double y = arr[1][j];
        
        if (x == 0 || y == 0) {
            break;
        }
        
        double ras = sqrt(x * x + y * y);
        cout << ras << endl;
    }
    
    return 0;
}
*/

int main() {
    int strok = 2;
    int stolb = 10;
    
    double** arr = new double*[strok];
    for (int i = 0; i < strok; i++) {
        arr[i] = new double[stolb];
    }
    
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int j = 0; j < stolb; j++) {
        double x = arr[0][j];
        double y = arr[1][j];
        
        if (x == 0 || y == 0) {
            break;
        }
        
        double ras = sqrt(x * x + y * y);
        cout << ras << endl;
    }
    
    for (int i = 0; i < strok; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}