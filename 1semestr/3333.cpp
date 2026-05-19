/*#include<iostream>
using namespace std;
#define STR 7
#define STB 3
int main()
{
    float A[STR][STB], a, b, t, avg, min, sum;
    int n=0;
    bool fl = true;
    for(int i = 0; i < STR; i++)
    {
        for(int j = 0; j < STB; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "input T" << endl;
    cin >> t;
    while (fl)
    {
        for(int i = 0;i<STR;i++)
        {
            sum = 0;
            for(int j = 0; j < STB; j++)
            {
                sum += A[i][j];
            }
            avg = sum / STB;
            min = A[i][0];
            for(int j = 1; j < STB; j++)
            {
                if(A[i][j] < min)
                {
                    min = A[i][j];
                }
            }
            cout << "num"<<i+1 << "avg" <<avg<<endl;
            cout << "min"<<min<<endl;
            cout << "dif" << (avg - min) << endl;
            if((avg - min) > t)
            {
                fl = false;
            }
        }
    }
   return 0;
}*/
#include <iostream>
using namespace std;

void inputA(int n, int **A) { //vvedem a
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
}

void inputC(int n, int *arr) { //vvedem c
    for (int i = 0; i < n; i++) {
        cout << "C[" << i << "] = ";
        cin >> arr[i];
    }
}


bool inRange(int value, int P, int T) { //v t i p?
    return (value >= P && value <= T);
}

int sum(int n, int **A, int j) { //summa
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i][j];
    return sum;
}


void computeX(int n, int **A, int *C, int *X, int P, int T) { //naydem x esli
    for (int i = 0; i < n; i++) {
        if (inRange(C[i], P, T)) //v diapazone?
            X[i] = sum(n, A, i);
        else
            X[i] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << "X[" << i << "] = " << X[i] << endl;
}



int main() {
    int n;
    cout << "vvedite n: ";
    cin >> n;

    //pamyat
    int **A = new int*[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];

    //esche
    int *C = new int[n];
    int *X = new int[n];

    int P, T;
    cout << "vvedite p i t: ";
    cin >> P >> T;

    inputA(n, A);
    inputC(n, C);
    computeX(n, A, C, X, P, T);

    //chistka
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
    delete[] C;
    delete[] X;

    return 0;
}
