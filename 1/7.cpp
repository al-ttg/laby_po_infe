/*7.  Задан целочисленный одномерный массив A из n элементов. 
Найти минимальный элемент среди элементов, больших b, расположенных до последнего элемента, большего t. 
Если элемент, больший t, не найден, искать до конца массива.*/
#include <iostream>
using namespace std;

int findlastt(int *A, int n, int t){
    int fd = 0;
    bool fl = false;
    for (int i =0; i<n; i++){
        if (A[i]>t){
            fd = i;
            fl = true;
        }
    }
    if (!fl){
        return n-1;
    } else {
        return fd;
    }
}

int find(int *A, int lastt, int b){
    int mn = 0;
    bool fl = true;
    for (int i = 0; i<(lastt+1); i++){
        if (A[i]>b){
            if (fl){
                mn = A[i];
            }
            if (A[i]<mn){
                mn = A[i];
            }
        }
    }
    return mn;
}

int main(){
    int n = 0;
    int t = 0;
    int b = 0;
    cin >> n;
    cin >> t;
    cin >> b;
    int *A = new int[n];
    int tt = findlastt(A, n, t);
    int mnn = find(A,tt,b);
    cout << mnn;
    delete[] A;
    return 0;

}