/*Используя класс vect и класс Complex написать программу
с перегрузкой операций.

Общая задача:
Даны два массива X, Y (элементы класса vect). Массивы состоят
из комплексных чисел. Подсчитать, есть ли равные элементы
на соответствующих местах, то есть есть ли xi == yi, и сколько их.
Использовать перегрузку оператора == в классе Complex.

Индивидуальная задача:
Создать в main массив mas комплексных чисел и решить следующую задачу,
используя при решении перегрузку операций в классе Complex:
Найти в массиве mas номер числа с максимальным значением модуля,
напечатать его значение и значение модуля.
Использовать перегрузку оператора > в классе Complex.

Входные данные:
Размер массивов N, элементы массивов (вручную или случайным образом)

Выходные данные:
Исходные массивы X и Y
Результат поэлементного сравнения и количество совпадений
Массив mas, индекс и значение элемента с максимальным модулем
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

int vvediChislo(const string& msg, int min, int max)
{
    int x;
    while (true)
    {
        cout << msg;
        if (cin >> x && x >= min && x <= max)
            return x;
        cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double vvediDrobnoye(const string& msg)
{
    double x;
    while (true)
    {
        cout << msg;
        if (cin >> x)
            return x;
        cout << "Ошибка! Введите вещественное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

class Complex
{
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void zapolnitSluchayno()
    {
        real = (rand() % 201 - 100) / 10.0;
        imag = (rand() % 201 - 100) / 10.0;
    }

    void input()
    {
        real = vvediDrobnoye("  Действительная часть: ");
        imag = vvediDrobnoye("  Мнимая часть: ");
    }

    void print() const
    {
        cout << fixed << setprecision(2) << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
    }

    double modul() const { return sqrt(real * real + imag * imag); }

    bool operator==(const Complex& b) const
    {
        return fabs(real - b.real) < 1e-9 && fabs(imag - b.imag) < 1e-9;
    }

    bool operator>(const Complex& b) const
    {
        return modul() > b.modul();
    }
};

class vect
{
    Complex* base;
    int size;

public:
    vect(int n = 0) : size(n)
    {
        base = new Complex[size];
    }

    vect(const vect& other) : size(other.size)
    {
        base = new Complex[size];
        for (int i = 0; i < size; i++)
            base[i] = other.base[i];
    }

    ~vect() { delete[] base; }

    void set(int i, const Complex& value)
    {
        if (i >= 0 && i < size) base[i] = value;
    }

    Complex& get(int i) { return base[i]; }

    int getSize() const { return size; }

    void zapolnitVruchnuyu(const string& name)
    {
        cout << "\nЗаполнение массива " << name << ":\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Элемент [" << i << "]:\n";
            base[i].input();
        }
    }

    void zapolnitSluchayno(const string& name)
    {
        for (int i = 0; i < size; i++)
            base[i].zapolnitSluchayno();
        cout << "Массив " << name << " заполнен случайно.\n";
    }

    void print(const string& name) const
    {
        cout << "\nМассив " << name << ":\n";
        for (int i = 0; i < size; i++)
        {
            cout << "  [" << i << "] = ";
            base[i].print();
            cout << "   |z| = " << fixed << setprecision(2) << base[i].modul() << "\n";
        }
    }
};

vect* reshitObshchuyu()
{
    cout << "\n--- Общая задача: сравнение массивов ---\n";

    int n = vvediChislo("Введите размер массивов (1-20): ", 1, 20);

    vect* X = new vect(n);
    vect  Y(n);

    cout << "\nМассив X:\n";
    int ch = vvediChislo("1 - ручной ввод, 2 - случайно: ", 1, 2);
    if (ch == 1) X->zapolnitVruchnuyu("X");
    else         X->zapolnitSluchayno("X");

    cout << "\nМассив Y:\n";
    ch = vvediChislo("1 - ручной ввод, 2 - случайно: ", 1, 2);
    if (ch == 1) Y.zapolnitVruchnuyu("Y");
    else         Y.zapolnitSluchayno("Y");

    X->print("X");
    Y.print("Y");

    cout << "\nСравнение X[i] == Y[i]:\n";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool eq = (X->get(i) == Y.get(i));
        cout << "  [" << i << "] X=";
        X->get(i).print();
        cout << "  Y=";
        Y.get(i).print();
        cout << "  " << (eq ? "равны" : "не равны") << "\n";
        if (eq) count++;
    }

    cout << "\nРезультат: ";
    if (count == 0)
        cout << "совпадающих элементов нет.\n";
    else
        cout << "совпадений: " << count << " из " << n << ".\n";

    return X;
}

void reshitIndividualnuyu(vect* gotovyMas = nullptr)
{
    cout << "\n--- Индивидуальная задача: максимальный модуль ---\n";

    vect* mas = nullptr;
    bool  nasNovyy = true;

    if (gotovyMas != nullptr)
    {
        cout << "Использовать массив X из общей задачи или задать новый?\n";
        int ch = vvediChislo("1 - использовать X, 2 - задать новый: ", 1, 2);
        if (ch == 1)
        {
            mas = gotovyMas;
            nasNovyy = false;
            mas->print("X (используется как mas)");
        }
    }

    if (nasNovyy)
    {
        int n = vvediChislo("Введите размер массива mas (1-20): ", 1, 20);
        mas = new vect(n);
        int ch = vvediChislo("1 - ручной ввод, 2 - случайно: ", 1, 2);
        if (ch == 1) mas->zapolnitVruchnuyu("mas");
        else         mas->zapolnitSluchayno("mas");
        mas->print("mas");
    }

    int maxIdx = 0;
    for (int i = 1; i < mas->getSize(); i++)
        if (mas->get(i) > mas->get(maxIdx))
            maxIdx = i;

    cout << "\nРезультат:\n";
    cout << "  Индекс: " << maxIdx << "\n";
    cout << "  Значение: ";
    mas->get(maxIdx).print();
    cout << "\n";
    cout << fixed << setprecision(4);
    cout << "  Модуль: " << mas->get(maxIdx).modul() << "\n";

    if (nasNovyy)
        delete mas;
}

int main()
{
    srand(time(0));

    int repeat;
    do
    {
        cout << "\nВыберите задачу:\n";
        cout << "1 - общая (сравнение массивов)\n";
        cout << "2 - индивидуальная (максимальный модуль)\n";
        cout << "3 - обе задачи\n";

        int choice = vvediChislo("Ваш выбор: ", 1, 3);

        if (choice == 1)
        {
            vect* x = reshitObshchuyu();
            delete x;
        }
        if (choice == 2) reshitIndividualnuyu();
        if (choice == 3)
        {
            vect* x = reshitObshchuyu();
            reshitIndividualnuyu(x);
            delete x;
        }

        repeat = vvediChislo("\nПовторить? (1/0): ", 0, 1);

    } while (repeat == 1);

    return 0;
}