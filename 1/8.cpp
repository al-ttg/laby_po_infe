/*8.  Задан целочисленный одномерный массив A из n элементов. 
Найти максимальный элемент среди отрицательных элементов, расположенных до последнего элемента, равного t. 
Если нет элементов со значением, равным t, искать до конца массива.*/
#include <iostream>
using namespace std;

int findlastt(int *A, int n, int t){
    int lst = 0;
    int ft = 0;
    bool fl = false;
    for (int i = 0; i<n; i++){
        if (A[i]==t){
            lst = i;
            fl = true;
        }
    }
    if (fl){
        return lst;
    } else {return n-1;}
}

int lastm(int *A, int lst){
    int mi = 0;
    bool fl = false;
    for (int i = 0; i<(lst+1); i++){
        if(A[i]<0){
            if (!fl){
                mi = A[i];
            }
            if (mi<A[i]){
                mi = A[i];
            }
        }
    }
    return mi;
}


int main(){
    int n = 0;
    int t = 0;
    cin >> n;
    cin >> t;
    int *A = new int[n];
    int lst = findlastt(A, n,t);
    int mi = lastm(A,lst);
    cout << mi;
    delete[] A;
    return 0;
}