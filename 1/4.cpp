/*4.  Изменить двумерный массив, вычитая из каждого положительного элемента значение предыдущего элемента той же строки.
Если положителен первый элемент строки, вычесть из него значение последнего элемента строки. Подсчитать число строк,
в которых были изменены элементы.*/
#include <iostream>
using namespace std;

int ch(int **A, int n, int m)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0 && A[i][j] > 0)
            {
                A[i][j] -= A[i][m - 1];
                ct++;
            }
            else if (A[i][j] > 0)
            {
                A[i][j] -= A[i][j - 1];
                ct++;
            }
        }
    }
    return ct;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int **A = new int*[n];
    for (int i = 0; i<n; i++){
        A[i] = new int[m];
    }
    int vuv = ch(A,n,m);
    cout << vuv;
    for (int i = 0; i<n; i++){
        delete[] A[i]; 
    }
    delete [] A;
    return 0;
}