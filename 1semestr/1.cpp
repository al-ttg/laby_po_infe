#include <iostream>
#include <cmath>
using namespace std;

int n = 0;
double a = 0;
double b = 0;

/*****************************/
double mn = 0;
double x = 0;
double y = 0;
int nc = 0;
double step = 0;
/****************************/

int main() {
    printf("n?\n");
    cin >> n;
    printf("a?\n");
    cin >> a;
    printf("b?\n");
    cin >> b;
    
    if (a>b){
        step = (a-b)/(n-1);
        mn = b;
    } else if (a<b){
        step = (b-a)/(n-1);
        mn = a;
    } else {
        step = 0;
    }
    printf("n         x           y\n");
    while(n!=0){
        x = mn + step * nc;
        nc+=1;
        if (x<0){
            printf("%f   %f   -\n", nc, x);
        }else{
            y = (pow(pow(log(x),2), 1.0/3.0) + tan(cos(M_PI * x))) * (fabs(log(x / 10.5)));
            printf("%d   %f   %f\n", nc, x, y);
        }
        
        n-=1;
    }
    printf("done");
    return 0;
}
