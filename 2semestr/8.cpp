/*Используя абстрактные базовые классы и виртуальные функции
написать программу для работы с геометрическими фигурами.

Общая задача:
Дан прямоугольник и две геометрические фигуры.
Необходимо вычислить площадь остатка прямоугольника после
вычитания площадей двух заданных фигур.

Реализовать абстрактный базовый класс geom с чистой
виртуальной функцией вычисления площади.
На его основе создать производные классы (например,
прямоугольник, круг, треугольник), реализующие вычисление
площади конкретной фигуры.

Выбор фигур осуществляется пользователем.
Вычислить площадь прямоугольника, площади двух фигур и
найти остаток.

Индивидуальная задача (вариант 17):
Используя абстрактный базовый класс geom3D с чистыми
виртуальными функциями вычисления объёма и площади поверхности,
реализовать работу с пространственными фигурами:

- Фигура 1: цилиндр — вычислить объём;
- Фигура 2: куб — вычислить площадь поверхности.

Создать соответствующие производные классы и реализовать
необходимые вычисления.

Входные данные:
Параметры прямоугольника (стороны),
параметры выбранных фигур (в зависимости от типа),
параметры цилиндра (радиус, высота),
параметр куба (длина ребра).

Выходные данные:
Параметры и площади всех фигур,
площадь прямоугольника,
площади выбранных фигур,
остаток площади,
объём цилиндра,
площадь поверхности куба.
*/

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int vvediChislo(const string &msg, int min, int max)
{
    while (true)
    {
        cout << msg;
        string s;
        cin >> s;

        bool valid = !s.empty();
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 && s[i] == '-') continue;
            if (!isdigit(s[i])) { valid = false; break; }
        }

        if (valid)
        {
            int x = stoi(s);
            if (x >= min && x <= max)
                return x;
        }

        cout << "Oshibka, vvedite tseloye chislo ot " << min << " do " << max << "\n";
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
                cout << "Oshibka, vvedite chislo\n";
            }
            else
            {
                cout << "Oshiibka, vvedite desyatichnoe chislo\n";
            }
            fl = true;
        }
    }
}


class geom
{
public:
    virtual double area() = 0;
    virtual void input() = 0;
    virtual void print() = 0;
    virtual ~geom() {}
};

// pryamougolnik
class Rectangle : public geom
{
    double a, b;

public:
    void input()
    {
        a = vvediDrobnoye("Storona a: ");
        b = vvediDrobnoye("Storona b: ");
    }

    double area()
    {
        return a * b;
    }

    void print()
    {
        cout << "Pryamougolnik: " << a << " x " << b
             << "  S=" << area() << "\n";
    }
};

class Circle : public geom
{
    double r;

public:
    void input()
    {
        r = vvediDrobnoye("Radius kruga: ");
    }

    double area()
    {
        return M_PI * r * r;
    }

    void print()
    {
        cout << "Krug: r=" << r
             << "  S=" << area() << "\n";
    }
};

class Triangle : public geom
{
    double a, h;

public:
    void input()
    {
        a = vvediDrobnoye("Osnovaniye: ");
        h = vvediDrobnoye("Vysota: ");
    }

    double area()
    {
        return 0.5 * a * h;
    }

    void print()
    {
        cout << "Treugolnik: S=" << area() << "\n";
    }
};

void reshitObshchuyu()
{
    cout << "\n--- OBSHCHAYA ZADACHA ---\n";

    Rectangle R;
    R.input();
    R.print();

    geom* f1;
    geom* f2;

    cout << "\nVyberite figuru 1:\n1 - krug\n2 - treugolnik\n";
    int ch = vvediChislo("Vash vybor: ", 1, 2);

    if (ch == 1) f1 = new Circle();
    else         f1 = new Triangle();

    f1->input();
    f1->print();

    cout << "\nVyberite figuru 2:\n1 - krug\n2 - treugolnik\n";
    ch = vvediChislo("Vash vybor: ", 1, 2);

    if (ch == 1) f2 = new Circle();
    else         f2 = new Triangle();

    f2->input();
    f2->print();

    double result = R.area() - f1->area() - f2->area();

    cout << "\nOstatok ploshchadi = " << result << "\n";

    delete f1;
    delete f2;
}

class geom3D
{
public:
    virtual double volume() = 0;
    virtual double area() = 0;
    virtual void input() = 0;
    virtual void print() = 0;
    virtual ~geom3D() {}
};


class Cylinder : public geom3D
{
    double r, h;

public:
    void input()
    {
        r = vvediDrobnoye("Radius: ");
        h = vvediDrobnoye("Vysota: ");
    }

    double volume()
    {
        return M_PI * r * r * h;
    }

    double area()
    {
        return 2 * M_PI * r * (r + h);
    }

    void print()
    {
        cout << "Tsilindr:\n";
        cout << "  V=" << volume() << "\n";
        cout << "  S=" << area() << "\n";
    }
};


class Cube : public geom3D
{
    double a;

public:
    void input()
    {
        a = vvediDrobnoye("Rebro: ");
    }

    double volume()
    {
        return a * a * a;
    }
    double area()
    {
        return 6 * a * a;
    }

    void print()
    {
        cout << "Kub:\n";
        cout << "  V=" << volume() << "\n";
        cout << "  S=" << area() << "\n";
    }
};

void reshitIndividualnuyu()
{
    cout << "\n--- INDIVIDUALNAYA ZADACHA ---\n";

    Cylinder c;
    c.input();
    c.print();

    Cube k;
    k.input();
    k.print();
}

int main()
{
    
    int repeat;

    do
    {
        cout << "\n1 - Obshchaya zadacha\n";
        cout << "2 - Individualnaya\n";
        cout << "3 - Obe\n";

        int ch = vvediChislo("Vybor: ", 1, 3);

        if (ch == 1) reshitObshchuyu();
        if (ch == 2) reshitIndividualnuyu();
        if (ch == 3)
        {
            reshitObshchuyu();
            reshitIndividualnuyu();
        }

        repeat = vvediChislo("\nPovtorit? (1/0): ", 0, 1);

    } while (repeat == 1);

    return 0;
}