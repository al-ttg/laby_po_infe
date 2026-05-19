/*Используя шаблоны функций написать программу
для обработки двумерного массива.

Общая задача:
Дан двумерный массив A размером N?M. Проверить,
все ли строки массива упорядочены по убыванию.
Если не все строки упорядочены, определить номер
последней строки, в которой нарушен порядок убывания.
При проверке использовать досрочный выход из цикла.

Решение реализовать с использованием шаблонной функции,
что позволяет работать с различными типами данных,
включая стандартные (int, double) и пользовательский
тип Complex.

Для пользовательского типа Complex сравнение элементов
выполняется по модулю комплексного числа с использованием
перегруженного оператора сравнения.

Входные данные:
Размер массива N и M (1?10),
элементы массива (вводятся вручную или генерируются случайно).

Выходные данные:
Исходный массив A,
результат проверки:
- если все строки упорядочены по убыванию ? соответствующее сообщение;
- иначе номер последней неупорядоченной строки.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>

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

class Complex
{
    double r, i;

public:
    Complex(double rr = 0, double ii = 0) : r(rr), i(ii) {}

    void input()
    {
        cout << "  Re = "; cin >> r;
        cout << "  Im = "; cin >> i;
    }

    void random()
    {
        r = rand() % 20 - 10;
        i = rand() % 20 - 10;
    }

    void print() const
    {
        cout << r;
        if (i >= 0) cout << "+" << i << "i ";
        else cout << i << "i ";
    }

    double modul() const
    {
        return sqrt(r*r + i*i);
    }

    bool operator<(const Complex& b) const
    {
        return modul() < b.modul();
    }
};

template <typename T>
int lastNotSorted(T** a, int n, int m)
{
    int last = -1;

    for (int i = 0; i < n; i++)
    {
        bool sorted = true;

        for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j] < a[i][j + 1])
            {
                sorted = false;
                break; 
            }
        }

        if (!sorted)
            last = i;
    }

    return last;
}

template <typename T>
T** create(int n, int m)
{
    T** a = new T*[n];
    for (int i = 0; i < n; i++)
        a[i] = new T[m];
    return a;
}

template <typename T>
void del(T** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

template <typename T>
void print(T** a, int n, int m)
{
    cout << "\nMassiv:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

template <>
void print<Complex>(Complex** a, int n, int m)
{
    cout << "\nMassiv:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            a[i][j].print();
        cout << "\n";
    }
}

template <typename T>
void fillManual(T** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Stroka " << i + 1 << ":\n";
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i << "][" << j << "] :";
            cin >> a[i][j];
        }
    }
}

template <typename T>
void fillRandom(T** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 20;
}

void fillManual(Complex** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Stroka " << i + 1 << ":\n";
        for (int j = 0; j < m; j++)
            a[i][j].input();
    }
}

void fillRandom(Complex** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j].random();
}

template <typename T>
void runTest()
{
    int n = vvediChislo("Vvedi kolichestvo strok: ", 1, 10);
    int m = vvediChislo("Vvedi kolichestvo stolbcov: ", 1, 10);

    T** a = create<T>(n, m);

    int ch = vvediChislo("1 - vvod, 2 - sluchayno: ", 1, 2);

    if (ch == 1) fillManual(a, n, m);
    else fillRandom(a, n, m);

    print(a, n, m);

    int res = lastNotSorted(a, n, m);

    if (res == -1)
        cout << "\nVse stroki uporyadocheny po ubivaniyu\n";
    else
        cout << "\nPoslednyaya neuporyadochennaya stroka: " << res + 1 << "\n";

    del(a, n);
}

int main()
{
    srand(time(0));

    int repeat;

    do
    {   
        cout << "\nzadacha 9: reshit s pomoschu: \n";
        cout << "1 - int\n";
        cout << "2 - double\n";
        cout << "3 - Complex\n";

        int ch = vvediChislo("Vybor: ", 1, 3);

        if (ch == 1) runTest<int>();
        if (ch == 2) runTest<double>();
        if (ch == 3) runTest<Complex>();

        repeat = vvediChislo("\nPovtorit? (1/0): ", 0, 1);

    } while (repeat == 1);

    return 0;
}