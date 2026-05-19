/*25. Средняя урожайность пшеницы – P ц/га, урожайность ржи – T ц/га.
Общая площадь угодий составляет C га. В первый год эта площадь делится
поровну между пшеницей и рожью. В последующие годы площадь, засевае-
мая рожью, увеличивается на р% (за счет пшеницы). Определить ежегодные
урожай пшеницы и урожай ржи в первые N лет.*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double Psch, rj, s, p;
    int N;
    
    while (true) {
        cout << "Urojay pschenitcy? ";
        cin >> Psch;
        cout << "Urojay rji? ";
        cin >> rj;
        cout << "S? ";
        cin >> s;
        cout << "%? ";
        cin >> p;
        cout << "Time? (years) ";
        cin >> t;
        
        if (Psch <= 0 || rj <= 0 || s <= 0 || p < 0 || t <= 0) {
            cout << "Fail\n";
            continue;
        }
        
        double psch = s / 2.0;
        double roj = s / 2.0;
        
        cout << fixed << setprecision(2);
        cout << "\nГод  Пшеница(га)  Рожь(га)  Урожай пшеницы(ц)  Урожай ржи(ц)\n";
        cout << string(60, '-') << endl;
        
        for (int year = 1; year <= N; year++) {
            double wheatYield = psch * p;
            double ryeYield = ryeArea * T;
            
            cout << setw(3) << year << setw(12) << wheatArea 
                 << setw(10) << ryeArea << setw(18) << wheatYield 
                 << setw(16) << ryeYield << endl;
            
            if (year < N) {
                double newRyeArea = ryeArea * (1.0 + p/100.0);
                if (newRyeArea > C) {
                    newRyeArea = C;
                }
                wheatArea = C - newRyeArea;
                ryeArea = newRyeArea;
            }
        }
        
        cout << "\nПродолжить? (1 - да, 0 - нет): ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
        cout << endl;
    }
    
    return 0;
}