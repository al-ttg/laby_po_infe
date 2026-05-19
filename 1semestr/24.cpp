#include <iostream>
#include <cmath>

using namespace std;
/*
int main() {
    int a;
    double mass[200];
    double b;
    
    cout << "skolko" << endl;
    cin >> a;
    
    cout << "vvedi" << endl;
    for (int i = 0; i < a; i++) {
        cin >> mass[i];
    }
    
    cout << "vvedi x" << endl;
    cin >> b;
    
    int no = -1;
    for (int i = 0; i < a; i++) {
        if (abs(mass[i]) < b) {
            no = i;
            break;
        }
    }
    
    if (no != -1) {
        cout << "nomer" << no << endl;
    } else {
        cout << "netu" << endl;
    }
    
    return 0;
}*/

int main() {
    int n;
    double x;
    
    cout << "skolko chisel?" << endl;
    cin >> n;
    
    double* mas = new double[n];
    
    cout << "vvedi chisla:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    
    cout << "vvedi chislo X:" << endl;
    cin >> x;
    
    int nomer = -1;
    for (int i = 0; i < n; i++) {
        if (abs(mas[i]) < x) {
            nomer = i;
            break;
        }
    }
    
    if (nomer != -1) {
        cout << "nashel! nomer: " << nomer << endl;
    } else {
        cout << "ne nashel" << endl;
    }
    
    delete[] mas;
    return 0;
}