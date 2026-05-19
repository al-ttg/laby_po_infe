#include <iostream>
#include <cmath>
using namespace std;

bool checkFirstCol(int** A, int m, int n, double val) {
    for (int i = 0; i < m; i++) {
        if (abs(A[i][0]) <= val) {
            return false;
        }
    }
    return true;
}

double avgCol(int** A, int m, int j) {
    double sum = 0;
    for (int i = 0; i < m; i++) {
        sum += A[i][j];
    }
    return sum / m;
}

int findMaxAvgCol(int** A, int m, int n) {
    int maxCol = 0;
    double maxAvg = avgCol(A, m, 0);
    
    for (int j = 1; j < n; j++) {
        double curAvg = avgCol(A, m, j);
        if (curAvg > maxAvg) {
            maxAvg = curAvg;
            maxCol = j;
        }
    }
    return maxCol;
}

void divideColByFirst(int** A, int m, int col) {
    for (int i = 0; i < m; i++) {
        A[i][col] = A[i][col] / A[i][0];
    }
}

void inputArray(int** A, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
}

void outputArray(int** A, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    double val;
    
    cout << "Enter rows m: ";
    cin >> m;
    cout << "Enter cols n: ";
    cin >> n;
    cout << "Enter value: ";
    cin >> val;
    
    int** A = new int*[m];
    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }
    
    inputArray(A, m, n);
    
    if (checkFirstCol(A, m, n, val)) {
        int maxCol = findMaxAvgCol(A, m, n);
        divideColByFirst(A, m, maxCol);
        cout << "Modified array:" << endl;
        outputArray(A, m, n);
    } else {
        cout << "First column condition not satisfied" << endl;
    }
    
    for (int i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    
    return 0;
}