/*24.	Создать в main два массива комплексных чисел a  и    b, напечатать комплексные числа массива a,
 для которых модуль числа a[i]   равен  удвоенному значению модуля  b[i]. */

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }
    void input() {
        while (!(cin >> real)) {
            cout << "Ошибка ввода! Повторите ввод";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        while (!(cin >> imag)) {
            cout << "Ошибка ввода! Повторите ввод";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    void print() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
    }
    double modulus() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    char choice;
    do {
        int n;
        cout << "Введите размер массивов: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Ошибка! Необходимо положительное число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        Complex* a = new Complex[n];
        Complex* b = new Complex[n];

        cout << "\nВвод массива a:\n";
        for (int i = 0; i < n; i++) {
            cout << "a[" << i << "] (real imag): ";
            a[i].input();
        }

        cout << "\nВвод массива b:\n";
        for (int i = 0; i < n; i++) {
            cout << "b[" << i << "] (real imag): ";
            b[i].input();
        }

        cout << "\nЭлементы массива a, для которых |a[i]| = 2 * |b[i]|:\n";
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (fabs(a[i].modulus() - 2 * b[i].modulus()) < 1e-9) {
                cout << "a[" << i << "] = ";
                a[i].print();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Таких элементов нет.\n";
        }

        delete[] a;
        delete[] b;

        cout << "\nПродолжить? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Программа завершена.\n";
    return 0;
}