/*1.  Найти среднее арифметическое отрицательных элементов двумерного массива, лежащих ниже главной диагонали, и среднее арифметическое всех элементов главной диагонали.
*/
#include <iostream>
using namespace std;

double nij (int **A, int m, int n){
    double sum =0.0;
    double srar =0.0;
    int ct =0;
    for (int i =0; i<n; i++){
        for (int j=0; j<i; j++){
            if (A[i][j] <0){
                ct++;
                sum += A[i][j];
            }
        }
    }
    srar = sum/(ct*1.0);
}


double dig (int **A, int n, int m){
    double sum =0.0;
    double srar =0.0;
    int ct =0;
    int e =0;
    if (n<=m){
        e= n;
    } else {
        e = m;
    }

    for (int i =0; i<e; i++){
        sum += A[i][i];
        ct++;
    }
    srar = sum/(ct*1.0);
}

int main(){
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int **A = new int*[n];
    for (int i = 0; i<n; i++){
        A[i]= new int[m]; 
    }
    double otr = nij(A,m,n);
    double diag = dig(A,n, m);
    cout<< otr << diag;
    for (int i = 0; i<n; i++){
        delete[] A[i]; 
    }
    delete [] A;
    return 0;

}