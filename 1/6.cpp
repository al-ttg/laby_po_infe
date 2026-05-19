/*6.  Составить подпрограмму для замены всех отрицательных элементов одномерного массива их модулями и подсчёта числа таких замен. 
Применяя эту подпрограмму, изменить каждый из двух заданных массивов A и B. 
Если окажется, что число замен в массиве A больше 5, вы вести этот массив с заменёнными элементами, иначе – массив B.*/

#include <iostream>
using namespace std;

double mod(double inpt){
    if (inpt <0){
        return -inpt;
    } else {
        return inpt;
    }
}

int zm(int *A, int n){
    int cnt = 0;
    for (int i =0; i<n; i++){
        if (A[i]<0){
            cnt++;
            A[i]=mod(A[i]);
        }
    }
    return cnt;
}

int main(){
    int n=0;
    int m=0;
    cin >> n;
    cin >> m;
    int *A = new int[n];
    int *B = new int[m];
    int ca = zm(A, n);
    int cb = zm(B,m);
    if (ca>5){
        cout << A;
    } else {cout<<B;}
    delete[] A;
    delete[] B;
    return 0;
}