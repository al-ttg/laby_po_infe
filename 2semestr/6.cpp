/*Используя класс vect  и класс matr  написать глобальную дружественную функцию,
которая находит сумму элементов каждой строки матрицы и записывает результат в соответствующий
элемент одномерного массива, объекта класса vect.


Постановка задачи:

1. Создать класс vect с динамическим массивом и полями:
2. Реализовать в классе vect методы взаимодействия
3. Создать класс matr с динамической двумерной матрицей
4. Реализовать в классе matr ввод и вывод матрицы
5. Реализовать глобальную дружественную функцию
6. создать функцию ввода размеров, создания классов и способа заполнения
7. Выполнить проверки на адекватность пользователя, диапазона размера и обработку ошибок

Входные данные:
Размер матрицы N, элементы матрицы (вручную или случайным образом)

Выходные данные:
Исходная матрица
Массив сумм строк матрицы */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>


using namespace std;

class matr;

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

    void set(int i, int value)
    {
        if (i >= 0 && i < size)
            base[i] = value;
    }

    int get(int i)
    {
        if (i >= 0 && i < size)
            return base[i];
        return 0;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        cout << "\nСуммы строк:\n";
        for (int i = 0; i < size; i++)
            cout << base[i] << " ";
        cout << endl;
    }

    friend void sumRows(const matr &m, vect &v);
};

class matr
{
    int **a;
    int n;

public:
    matr(int size = 0)
    {
        n = size;

        a = new int *[n];
        for (int i = 0; i < n; i++)
            a[i] = new int[n];
    }

    ~matr()
    {
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
    }

    int getSize() const
    {
        return n;
    }

    void inputManual()
    {
        cout << "Введите матрицу:\n";

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                while (!(cin >> a[i][j]))
                {
                    cout << "Ошибка! Введите число: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
    }

    void inputRandom()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = rand() % 21 - 10;
    }

    void print() const
    {
        cout << "\nМатрица:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << setw(4) << a[i][j];
            cout << endl;
        }
    }

    friend void sumRows(const matr &m, vect &v);
};

void sumRows(const matr &m, vect &v)
{
    if (v.getSize() != m.getSize())
    {
        cout << "Ошибка размеров!\n";
        return;
    }

    for (int i = 0; i < m.getSize(); i++)
    {
        int sum = 0;

        for (int j = 0; j < m.getSize(); j++)
            sum += m.a[i][j];

        v.set(i, sum);
    }
}

int inputInt(string msg, int min, int max)
{
    int x;

    while (true)
    {
        cout << msg;
        cin >> x;

        if (cin.fail() || x < min || x > max)
        {
            cout << "Ошибка! Повторите ввод\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            return x;
    }
}

int main()
{
   
    srand(time(0));

    int repeat;

    do
    {

        int n = inputInt("Введите размер: ", 1, 200);

        matr m(n);
        vect v(n);

        int choice = inputInt("1 - ручной ввод, 2 - случайно: ", 1, 2);

        if (choice == 1)
            m.inputManual();
        else
            m.inputRandom();

        m.print();

        sumRows(m, v);

        v.print();

        repeat = inputInt("Повторить? (1/0): ", 0, 1);

    } while (repeat == 1);

    return 0;
}