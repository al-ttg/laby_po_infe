//3.  Найти номер первой строки, все элементы которой равны заданному числу.
#include <iostream>
using namespace std;

int nah (int **A, int n, int m, int t){
    int ct =0;
    for (int i = 0; i<n; i++){
        for (int j=0; j<m; j++){
            if (A[i][j] == t){
                ct++;
            } else {
                break;
            }
            if (ct == m){
                return i;
            } else {
                ct =0;
            }
        }
    }
}
int main(){
    int n =0;
    int m =0;
    int t =0;
    cin>> n;
    cin >>m;
    cin >> t;
    int **A = new int*[n];
    for (int i =0; i<n; i++){
        A[i] = new int[m];
    }
    int out = nah(A,n,m,t);
    cout<<out;
    for (int i = 0; i<n; i++){
        delete[] A[i]; 
    }
    delete [] A;
    return 0;
}