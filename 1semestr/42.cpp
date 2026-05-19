#include <iostream>
using namespace std;

int summaPoloj(int stroka[], int n) {
    int sum = 0;
    bool est = false;
    
    for (int i = 0; i < n; i++) {
        if (stroka[i] > 0) {
            sum += stroka[i];
            est = true;
        }
    }
    
    if (!est) {
        return -1;
    }
    
    return sum;
}

void vvodRazmer(int &m, int &n) {
    cout << "Vvedite kolichestvo strok m: ";
    cin >> m;
    cout << "Vvedite kolichestvo stolbcov n: ";
    cin >> n;
}

void vvodMass(int **A, int m, int n) {
    cout << "Vvedite elementy massiva A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
}

void vivodRez(int nomer, int summa) {
    if (nomer == -1) {
        cout << "V massive net polojitelnih elementov" << endl;
    } else {
        cout << "Nomer stroki s maksimalnoj summoi polojitelnih: " << nomer + 1 << endl;
        cout << "Summa polojitelnih elementov: " << summa << endl;
    }
}

int main() {
    int m, n;
    
    vvodRazmer(m, n);
    
    int **A = new int*[m];
    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }
    
    vvodMass(A, m, n);
    
    int maxSum = -1;
    int nomerStr = -1;
    
    for (int i = 0; i < m; i++) {
        int tekSum = summaPoloj(A[i], n);
        
        if (tekSum != -1) {
            if (tekSum > maxSum || maxSum == -1) {
                maxSum = tekSum;
                nomerStr = i;
            }
        }
    }
    
    vivodRez(nomerStr, maxSum);
    
    for (int i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    
    return 0;
}