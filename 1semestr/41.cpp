/**/
#include <iostream>
#include <cmath>
using namespace std;

int znamenit(int arr[], int n, int prog){
    int count = 0;
    
    for (int i = 0; i < n; i++){
        if (arr[i] < prog){
            arr[i] = 0;
            count++;
        }
    }
    return count;
}

void vuv(int va[], int vb[], int d, int e, int za, int zb){
    cout << "mass a  " << endl;
    for (int i = 0; i < d; i++){
        cout << va[i] << "";
    }
    cout << endl;

    cout << "mass b  " << endl;
    for (int i = 0; i < e; i++){
        cout << vb[i] << "";
    }
    cout << endl;

    cout << "kolvo zamen v A  " << za << endl;
    cout << "kolvo zamen v B  " << zb << endl;

    if (za > zb){
        cout << "zamen v A bolshe  " << endl;
    } else if (za < zb){
        cout << "zamen v B bolshe  " << endl;
    } else {
        cout << "zamen porovnu  " << endl;
    }
    
}
int vv(int d){
    switch (d){
        case 0:
            int f = 0;
            cout << "razm mass a  " << endl;
            cin >> f;
            return f;
        break;

        case 1:
            int f = 0;
            cout << "razm mass b  " << endl;
            cin >> f;
            return f;
        break;
    }
}
void run(){
int n, m;
    n = vv(0);
    m = vv(1);
    int *A = new int[n];
    int *B = new int[m];
    
    cout << "mass a  " << endl;
    for (int i = 0; i < m; i++){
        cin >> A[i];
    }
    cout << "mass b  " << endl;
    for (int i = 0; i < m; i++){
        cin >> B[i];
    }

    int zamenA = znamenit(A, n, 0);
    int zamenB = znamenit(B, m, -10);
    vuv(A, B, n, m, zamenA, zamenB);
    delete[] A;
    delete[] B;
    
}


int main(){
    run();
    return 0;
}