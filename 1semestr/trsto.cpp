/*#include <iostream>
using namespace std;
проверить, все ли строки двумерного массива имеют 
хотя бы один элемент, больший заданного числа. если не все
то найти номер первоц строки, где нет данных элементов

int pois(int **A, int c, int a, int b){
    bool fl = false;
    for(int i = 0; i<a; i++){
        for (int j = 0; j<b; j++){
            if (A[i][j]>c){
                fl = true;
                break;
            }
        }
        if (!fl){
            return i;
        }
        fl = false;
    }
    return 0;

}

int main(){
    int e = 0;
    cin >> e;
    int a;
    cin >> a;
    int b;
    cin >> b;
    int **A = new int*[a];
    for (int i = 0; i<a; i++){
        A[i] = new int[a];
    }
    for (int i = 0; i<a; i++){
        for (int j = 0; j<b; j++){
            cin >> A[i][j];
        }
    }
    int r = pois(A,e,a,b);
    if (r!=0){
        cout << r;
    } else {
        cout << "0";
    }
    return 0;
    
}
*/
/*для двумерного массива A из m строк и n столбцов определить номер той строки
в которой среднее арифметическое значений максимально (считаем что она единственная)
для поиска среднего арифметического использовать подпрограмму */
#include <iostream>
using namespace std;

int srar(int **A, int n, int m){
    int sum = 0;
    double flt = 0.0;
    double lstfl = 0.0;
    int vu = 0;
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            sum += A[i][j];
        }
        flt = sum/n;
        if (flt >= lstfl){
            vu = i;
            lstfl = flt;
        }
    }
    if(vu!=0){return vu;}else{return -1;}
}

int main(){
    int n =0;
    int m = 0;
    cin >> n;
    cin >> m;
    int **A = new int*[m];
    for (int i = 0; i<n; i++){
        A[i] = new int [n];

    }
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> A[i][j];
        }
    }
    int res = 0;
    res = srar(A,n,m);
    cout << res;
}