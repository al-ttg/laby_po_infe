#include <iostream>
#include <cmath>
using namespace std;


/*int main() {
    int mas[6][3];
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "pos" << i << j <<"?";
            cin >> mas[i][j];
        }
    }
    
    int zad;
    cout << "zadano?";
    cin >> zad;
    
    int kol = 0;
    
    for (int i = 0; i < 6; i++) {
        int s = 0;
        for (int j = 0; j < 3; j++) {
            s += mas[i][j];
        }
        
        if (abs(s) > zad) {
            cout << "stroka" << i + 1 << endl;
            kol++;
        }
    }
    
    cout << "vsego" << kol << endl;
    
    return 0;
}*/

int main() {
    int strok = 6;
    int stolb = 3;
    
    int** mas = new int*[strok];
    for (int i = 0; i < strok; i++) {
     mas[i] = new int[stolb];
    }
    
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            cout << "yach" << i << j << "?";
            cin >> mas[i][j];
        }
    }
    
    int zad;
    cout << "zadano?";
    cin >> zad;
    
    int kol = 0;
    
    for (int i = 0; i < strok; i++) {
        int s = 0;
        for (int j = 0; j < stolb; j++) {
            s += mas[i][j];
        }
        
        if (abs(s) > zad) {
            cout << "stroka" << i + 1 << endl;
            kol++;
        }
    }
    
    cout << "vsego" << kol << endl;
    
    for (int i = 0; i < strok; i++) {
        delete[] mas[i];
    }
    delete[] mas;
    
    return 0;
}