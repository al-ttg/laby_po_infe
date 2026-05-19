#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() {
        real = 0.0;
        imag = 0.0;
    }
    Complex(double r, double i) {
        real = r;
        imag = i;
    }
    void assign(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }
    void input() {
        cout << "Введите действительную часть: ";
        cin >> real;
        cout << "Введите мнимую часть: ";
        cin >> imag;
    }
    void print() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }
    Complex add(const Complex& b) const {
        return Complex(real + b.real, imag + b.imag);
    }
    Complex sub(const Complex& b) const {
        return Complex(real - b.real, imag - b.imag);
    }
    Complex mul(const Complex& b) const {
        return Complex(
            real * b.real - imag * b.imag,
            real * b.imag + imag * b.real
        );
    }
    double modulus() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex c1(3, 4);   
    Complex c2;   

    c2.input();
    cout << "\nПервое число: ";
    c1.print();
    cout << "Второе число: ";
    c2.print();

    Complex sum = c1.add(c2);
    Complex diff = c1.sub(c2);
    cout << "\nСумма: ";
    sum.print();
    cout << "Разность: ";
    diff.print();
    cout << "\nМодуль первого числа: " << c1.modulus() << endl;
    cout << "Модуль второго числа: " << c2.modulus() << endl;

    return 0;
}