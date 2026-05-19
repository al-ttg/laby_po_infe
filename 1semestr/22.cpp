#include <iostream>
using namespace std;
/*
int main() {
    int a = 0;
    double ms[200];
    cout << "kolvo znach?" << endl;
    cin >> a;
    cout << "znach?" << endl;
    for (int b = 0; b < a; b++) {
        cin >> ms[b];
    }
    int otr = 0;
    for (int c = 0; c < a; c++) {
        if (ms[c] < 0) {
            otr++;
        }
    }
    for (int d = 0; d < a - 1; d++) {
        if (ms[d] > 0) {
            ms[d] = ms[d] / ms[d + 1];
        }
    }
    cout << "otritcatelnyh" << otr << endl;
    cout << "mass" << endl;
    for (int e = 0; e < a; e++) {
        cout << ms[e] << " ";
    }
    return 0;
}*/





int main() {
    int a;
    cout << "kolvo el ";
    cin >> a;

    int* ukaz = new int[200];

    cout << "vved " << a << " el-tov \n";
    for (int b = 0; b < a; b++) {
        cin >> ukaz[b];
    }
    
    int c = 0;
    for (int d = 0; d < a; d++) {
        if (ukaz[d] < 0) {
            c++;
        }
    }
 
    for (int e = 0; e < a - 1; e++) {
        if (ukaz[e] > 0) {
            ukaz[e] = ukaz[e] / ukaz[e + 1];
        }
    }
    
    cout << "otric " << c << endl;

    cout << "rez \n";
    for (int f = 0; f < a; f++) {
        cout << ukaz[f] << " ";
    }
    cout << endl;
    
    delete[] ukaz;
    
    return 0;
}