/*
•	Решить задачу как метод класса.
•	Решить задачу в main c использованием методов класса доступа к полям класса.
24. Дан массив X(20) найти сумму  четных элементов массива,
 индексы которых находятся между индексами минимального и максимального элементов массива.*/


#include <iostream>
using namespace std;

class vect
{
    int *base;
    int size;

public:
    vect(int n = 0)
    {
        size = n;
        base = new int[size];
    }

    ~vect()
    {
        delete[] base;
    }

    void input();
    void print();
    int sumMethod();
    int get(int i);
    int getSize();
};

void vect::input()
{
    cout << "Введите элементы массива:\n";

    for (int i = 0; i < size; i++)
    {
        while (!(cin >> base[i]))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void vect::print()
{
    cout << "Массив:\n";

    for (int i = 0; i < size; i++)
        cout << base[i] << " ";

    cout << endl;
}

int vect::get(int i)
{
    if (i >= 0 && i < size)
        return base[i];

    return 0;
}

int vect::getSize()
{
    return size;
}

int vect::sumMethod()
{
    int min = base[0];
    int max = base[0];
    int imin = 0;
    int imax = 0;

    for (int i = 1; i < size; i++)
    {
        if (base[i] < min)
        {
            min = base[i];
            imin = i;
        }

        if (base[i] > max)
        {
            max = base[i];
            imax = i;
        }
    }

    int start = imin < imax ? imin : imax;
    int end = imin > imax ? imin : imax;

    int sum = 0;

    for (int i = start + 1; i < end; i++)
    {
        if (base[i] % 2 == 0)
            sum += base[i];
    }

    return sum;
}

int main()
{
    char choice;

    do
    {
        vect x(20);

        x.input();
        x.print();

        cout << "\nРешение методом класса:\n";
        cout << "Сумма = " << x.sumMethod() << endl;

        cout << "\nРешение в main:\n";

        int size = x.getSize();

        int min = x.get(0);
        int max = x.get(0);
        int imin = 0;
        int imax = 0;

        for (int i = 1; i < size; i++)
        {
            if (x.get(i) < min)
            {
                min = x.get(i);
                imin = i;
            }

            if (x.get(i) > max)
            {
                max = x.get(i);
                imax = i;
            }
        }

        int start = imin < imax ? imin : imax;
        int end = imin > imax ? imin : imax;

        int sum = 0;

        for (int i = start + 1; i < end; i++)
        {
            if (x.get(i) % 2 == 0)
                sum += x.get(i);
        }

        cout << "Сумма = " << sum << endl;

        cout << "\nВыполнить программу ещё раз? (y/n): ";

        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N'))
        {
            cout << "Ошибка! Введите y или n: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Программа завершена.\n";

    return 0;
}