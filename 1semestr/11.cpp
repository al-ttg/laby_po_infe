#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double whet, rye, s, perc;
    int years;
    
    
        cout << "Urozhainost pshenicy: ";
        cin >> whet;
        cout << "Urozhainost rji: ";
        cin >> rye;
        cout << "Ploshad: ";
        cin >> s;
        cout << "Procent: ";
        cin >> perc;
        cout << "Time: ";
        cin >> years;
        
        if (whet <= 0 || rye <= 0 || s <= 0 || perc < 0 || years <= 0) {
            cout << "Fail, retry\n";
        } else {
        
        double swht = s / 2.0;
        double srye = s / 2.0;
        
        cout << fixed << setprecision(2);
        cout << "\nGod  Pshenica(ga)  Roj(ga)  Urozhay pshenicy(c)  Urozhay rji(c)\n";
        cout << string(60, '-') << endl;
        
        for (int year = 1; year <= years; year++) {
            double ywht = swht * whet;
            double yrye = srye * rye;
            
            cout << setw(3) << year << setw(13) << swht 
                 << setw(11) << srye << setw(19) << ywht 
                 << setw(17) << yrye << endl;
            
            if (year < years) {
                double nsry = srye * (1.0 + perc/100.0);
                if (nsry > s) {
                    nsry = s;
                }
                swht = s - nsry;
                srye = nsry;
            }
        }
    }
   
    return 0;
}