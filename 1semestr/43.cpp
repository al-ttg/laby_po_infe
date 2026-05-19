#include <iostream>
using namespace std;

int proizvedenie(int arr[], int n) {
    int p = 1;
    bool estNulevie = false;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            p *= arr[i];
            estNulevie = true;
        }
    }
    
    if (!estNulevie) {
        return 0;
    }
    
    return p;
}

void vvodMassiva(int arr[], int n, char name) {
    cout << "Vvedite " << n << " elementov massiva " << name << ":" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void vivodRezultata(char name, int maxP) {
    cout << "Massiv " << name << " imeet naibolshee proizvedenie: " << maxP << endl;
}

int main() {
    int a, b, c;
    
    cout << "Vvedite dlinu massiva A: ";
    cin >> a;
    cout << "Vvedite dlinu massiva B: ";
    cin >> b;
    cout << "Vvedite dlinu massiva C: ";
    cin >> c;
    
    int *A = new int[a];
    int *B = new int[b];
    int *C = new int[c];
    
    vvodMassiva(A, a, 'A');
    vvodMassiva(B, b, 'B');
    vvodMassiva(C, c, 'C');
    
    int pA = proizvedenie(A, a);
    int pB = proizvedenie(B, b);
    int pC = proizvedenie(C, c);
    
    int maxP = pA;
    char maxName = 'A';
    
    if (pB > maxP) {
        maxP = pB;
        maxName = 'B';
    }
    if (pC > maxP) {
        maxP = pC;
        maxName = 'C';
    }
    
    vivodRezultata(maxName, maxP);
    
    delete[] A;
    delete[] B;
    delete[] C;
    
    return 0;
}