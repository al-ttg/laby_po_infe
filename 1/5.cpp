/*5.  Составить подпрограмму, вычисляющую значение true, если все элементы одномерного массива 
упорядочены по убыванию их значений, и false в противном случае.
 Используя эту подпрограмму, вывести тот из заданных массивов A и B, в котором элементы не упорядочены по убыванию их значений. 
 Если оба массива упорядочены или не упорядочены, вывести сообщение.*/

#include <iostream>
using namespace std;

bool tr(int *A, int n){
    int ct =0;
    bool fl = true;
    for (int i =0; i<n; i++){
        if (i=0){
            continue;
        } else if (A[i]<=A[i-1]){
            fl = true;
        } else {
            fl = false;
            break;
        }
    }
    return fl;
}

int main(){
    int n =0;
    int m = 0;
    cin >> n;
    cin >> m;
    int *A = new int[n];
    int *B = new int[m];
    bool art = tr(A,n);
    bool brt = tr(A,m);
    if (art && !brt){
        cout << A;
    } else if (brt && !art){
        cout << B;
    } else if (art == brt){
        cout << "same";
    } else {return -1;}
    delete[] A;
    delete[] B;
    return 0;
    
}