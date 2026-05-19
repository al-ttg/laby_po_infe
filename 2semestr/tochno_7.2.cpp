/*Используя класс matr написать программу с использованием
наследования (private и protected).

Общая задача:
Дана матрица A с двумя столбцами. Каждый элемент строки
представляет параметры цилиндра: радиус основания и высоту.
Определить номера тех цилиндров, объём которых меньше
заданного значения CV.

Реализовать решение двумя способами:
1) с использованием класса matr с закрытыми (private) полями
   и доступом к элементам через методы;
2) с использованием класса matr с защищёнными (protected) полями
   и прямым доступом к элементам в производном классе.
В каждом случае вычислить объёмы цилиндров и вывести номера
тех, которые удовлетворяют условию.

Входные данные:
Количество цилиндров N (1–65),
элементы матрицы (радиус и высота для каждого цилиндра —
вводятся вручную или генерируются случайно),
значение объёма CV.

Выходные данные:
Исходная матрица A,
номера цилиндров, объём которых меньше CV, и их объёмы,
либо сообщение об отсутствии таких цилиндров.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <ctime>
using namespace std;

int vvediChislo(const string &msg, int min, int max)
{
    int x;
    while (true)
    {
        cout << msg;
        if (cin >> x && x >= min && x <= max)
            return x;

        cout << "Ошибка! Введите число от " << min << " до " << max << "\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double vvediDrobnoye(const string &msg)
{
    double x;
    bool fl = true;
    bool ms = false;
    string line;

    while (true)
    {
        cout << msg;
        if (getline(cin, line))
        {
            bool ok = true;
            for (char c : line)
                if (c == ',')
                {
                    ms = true;
                    ok = false;
                    break;
                }
            if (ok)
            {
                try
                {
                    size_t pos;
                    x = stod(line, &pos);
                    ms = true;
                    if (pos == line.size() && x > 0)
                    {
                        return x;
                    }
                    else
                    {
                        fl = false;
                    }
                }
                catch (...)
                {
                }
            }
        }
        if (ms)
        {
            if (fl)
            {
                cout << "Ошибка! Введите вещественное число (разделитель — точка).\n";
            }
            else
            {
                cout << "Ошибка, размер должен быть натуральным числом\n";
            }
            fl = true;
        }
    }
}

class matr_private
{
private:
    double **base;
    int rows, cols;

public:
    matr_private(int r, int c) : rows(r), cols(c)
    {
        base = new double *[rows];
        for (int i = 0; i < rows; i++)
            base[i] = new double[cols];
    }

    ~matr_private()
    {
        for (int i = 0; i < rows; i++)
            delete[] base[i];
        delete[] base;
    }

    double &elem(int i, int j) { return base[i][j]; }
    int getRows() const { return rows; }

    void zapolnitVruchnuyu()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < rows; i++)
        {
            cout << "Цилиндр " << i + 1 << ":\n";
            base[i][0] = vvediDrobnoye("  Радиус: ");
            base[i][1] = vvediDrobnoye("  Высота: ");
        }
    }

    void zapolnitSluchayno()
    {
        for (int i = 0; i < rows; i++)
        {
            base[i][0] = (rand() % 100 + 1) / 10.0;
            base[i][1] = (rand() % 100 + 1) / 10.0;
        }
        cout << "Заполнено случайно\n";
    }

    void print()
    {
        cout << "\nМатрица:\n";
        for (int i = 0; i < rows; i++)
            cout << i + 1 << ": r=" << base[i][0]
                 << " h=" << base[i][1] << "\n";
    }
};

class Cylinder_private : protected matr_private
{
public:
    Cylinder_private(int n) : matr_private(n, 2) {}

    void run()
    {
        int ch = vvediChislo("1 - вручную, 2 - случайно: ", 1, 2);

        if (ch == 1)
            zapolnitVruchnuyu();
        else
            zapolnitSluchayno();

        print();

        double CV = vvediDrobnoye("\nВведите объем CV: ");

        bool found = false;
        cout << "\nПодходящие цилиндры:\n";

        for (int i = 0; i < getRows(); i++)
        {
            double r = elem(i, 0);
            double h = elem(i, 1);
            double V = M_PI * r * r * h;

            if (V < CV)
            {
                cout << "№" << i << "  V=" << V << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "Нет подходящих цилиндров\n";
    }
};

class matr_protected
{
protected:
    double **base;
    int rows, cols;

public:
    matr_protected(int r, int c) : rows(r), cols(c)
    {
        base = new double *[rows];
        for (int i = 0; i < rows; i++)
            base[i] = new double[cols];
    }

    ~matr_protected()
    {
        for (int i = 0; i < rows; i++)
            delete[] base[i];
        delete[] base;
    }

    void zapolnitVruchnuyu()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < rows; i++)
        {
            cout << "Цилиндр " << i << ":\n";
            base[i][0] = vvediDrobnoye("  Радиус: ");
            base[i][1] = vvediDrobnoye("  Высота: ");
        }
    }

    void zapolnitSluchayno()
    {
        for (int i = 0; i < rows; i++)
        {
            base[i][0] = (rand() % 100 + 1) / 10.0;
            base[i][1] = (rand() % 100 + 1) / 10.0;
        }
        cout << "Заполнено случайно\n";
    }

    void print()
    {
        cout << "\nМатрица:\n";
        for (int i = 0; i < rows; i++)
            cout << i << ": r=" << base[i][0]
                 << " h=" << base[i][1] << "\n";
    }
};

class Cylinder_protected : protected matr_protected
{
public:
    Cylinder_protected(int n) : matr_protected(n, 2) {}

    void run()
    {
        int ch = vvediChislo("1 - вручную, 2 - случайно: ", 1, 2);

        if (ch == 1)
            zapolnitVruchnuyu();
        else
            zapolnitSluchayno();

        print();

        double CV = vvediDrobnoye("\nВведите объем CV: ");

        bool found = false;
        cout << "\nПодходящие цилиндры:\n";

        for (int i = 0; i < rows; i++)
        {
            double r = base[i][0];
            double h = base[i][1];
            double V = M_PI * r * r * h;

            if (V < CV)
            {
                cout << "№" << i << "  V=" << V << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "Нет подходящих цилиндров\n";
    }
};

int main()
{
    srand(time(0));
    int repeat;

    do
    {
        cout << "\nРешить способом\n";
        cout << "1 - private\n";
        cout << "2 - protected\n";

        int choice = vvediChislo("Ваш выбор: ", 1, 2);
        int n = vvediChislo("Введите количество цилиндров (1-65): ", 1, 65);

        if (choice == 1)
        {
            cout << "\n--- PRIVATE ---\n";
            Cylinder_private obj(n);
            obj.run();
        }
        else
        {
            cout << "\n--- PROTECTED ---\n";
            Cylinder_protected obj(n);
            obj.run();
        }

        repeat = vvediChislo("\nПовторить? (1 - да /0 - нет): ", 0, 1);

    } while (repeat == 1);

    return 0;
}