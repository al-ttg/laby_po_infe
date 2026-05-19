#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};
Complex create(double r = 0.0, double i = 0.0) {
    Complex c;
    c.real = r;
    c.imag = i;
    return c;
}
void print(Complex c) {
    cout << c.real;
    if (c.imag >= 0)
        cout << " + " << c.imag << "i";
    else
        cout << " - " << -c.imag << "i";
    cout << endl;
}
Complex add(Complex a, Complex b) {
    return create(a.real + b.real, a.imag + b.imag);
}
Complex add(Complex a, double b) {
    return create(a.real + b, a.imag);
}
Complex add(double a, Complex b) {
    return create(a + b.real, b.imag);
}
Complex sub(Complex a, Complex b) {
    return create(a.real - b.real, a.imag - b.imag);
}
Complex mul(Complex a, Complex b) {
    return create(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

int main() {
    Complex c1 = create(3, 4);
    Complex c2 = create(1, -2);

    cout << "Первое число: ";
    print(c1);
    cout << "Второе число: ";
    print(c2);
    cout << "\nСумма (Complex + Complex): ";
    print(add(c1, c2));
    cout << "Сумма (Complex + double): ";
    print(add(c1, 5.0));
    cout << "Сумма (double + Complex): ";
    print(add(5.0, c1));
    cout << "\nРазность: ";
    print(sub(c1, c2));
    cout << "\nПроизведение: ";
    print(mul(c1, c2));

    return 0;
}