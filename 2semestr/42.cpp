/* 
Разработать программу для обработки двумерного массива. Исполь-
зовать досрочный выход из цикла при реализации. Предусмотреть случай,
когда в исходном массиве искомых значений нет. Для проверки работо-
способности программы разработать тесты, охватывающие все возмож-
ные случаи для стандартных типов и пользовательского типа complex
Проверить, есть ли в двумерном массиве хотя бы одна строка,
которая не содержит элементов, попадающих в заданный диапазон, и
найти её номер*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// --- Функции валидации ввода ---

int vvediChislo(const string &msg, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max())
{
    string line;
    while (true)
    {
        cout << msg;
        if (getline(cin, line))
        {
            try
            {
                size_t pos;
                int x = stoi(line, &pos);
                if (pos == line.size() && x >= min && x <= max)
                    return x;
            }
            catch (...) {}
        }
        cout << "Ошибка! Введите целое число от " << min << " до " << max << ".\n";
    }
}

double vvediDrobnoye(const string &msg)
{
    double x;
    string line;
    while (true)
    {
        cout << msg;
        if (getline(cin, line))
        {
            bool ok = true;
            for (char c : line)
                if (c == ',') { ok = false; break; }
            if (ok)
            {
                try
                {
                    size_t pos;
                    x = stod(line, &pos);
                    if (pos == line.size())
                        return x;
                }
                catch (...) {}
            }
        }
        cout << "Ошибка! Введите вещественное число (разделитель — точка).\n";
    }
}

// --- Пользовательский класс Complex ---

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
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
    }

    // Для комплексных чисел диапазон проверяется по их модулю (абсолютной величине)
    double modul() const { return sqrt(real * real + imag * imag); }

    // Операторы сравнения для проверки диапазонов по модулю
    bool operator>=(double val) const { return this->modul() >= val; }
    bool operator<=(double val) const { return this->modul() <= val; }
};

// Перегрузка оператора вывода для Complex, чтобы использовать в шаблонах печати матриц
ostream& operator<<(ostream& os, const Complex& c)
{
    os << fixed << setprecision(2);
    double r = static_cast<double>(int(c.modul() * 100)) / 100; // для красоты вывода модуля
    // Выведем и само число, и его модуль в скобках для наглядности проверки диапазона
    // Чтобы не перегружать вывод матрицы, вернем компактную строку
    return os;
}

// --- Шаблонные функции для работы с двумерным массивом (vector <vector<T>>) ---

// Функция генерации случайного элемента (перегрузка для базовых типов и Complex)
template <typename T>
T sgenerirovatElement() { return static_cast<T>((rand() % 201 - 100) / 10.0); }

template <>
Complex sgenerirovatElement<Complex>()
{
    Complex c;
    c.zapolnitSluchayno();
    return c;
}

// Функция ввода элемента (перегрузка для базовых типов и Complex)
template <typename T>
T vvestiElement() { return static_cast<T>(vvediDrobnoye(" Введите число: ")); }

template <>
Complex vvestiElement<Complex>()
{
    Complex c;
    c.input();
    return c;
}

// Вывод матрицы на экран
template <typename T>
void pechatMatricy(const vector<vector<T>> &matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        cout << "Строка " << i << ": ";
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if constexpr (is_same_v<T, Complex>)
            {
                matrix[i][j].print();
                cout << " (mod:" << fixed << setprecision(2) << matrix[i][j].modul() << ")   ";
            }
            else
            {
                cout << setw(6) << fixed << setprecision(2) << matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

// --- Основной алгоритм решения задачи ---
/* 
  Ищет строку, которая НЕ содержит элементов из диапазона [minVal, maxVal].
  Возвращает индекс строки, либо -1, если такой строки нет.
*/
template <typename T, typename BoundsType>
int naitiStrokuBezDiapazona(const vector<vector<T>> &matrix, BoundsType minVal, BoundsType maxVal)
{
    int naidennyIndex = -1;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        bool estPopadanie = false;
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            // Если элемент попал в диапазон
            if (matrix[i][j] >= minVal && matrix[i][j] <= maxVal)
            {
                estPopadanie = true;
                break; // Досрочный выход из цикла текущей строки (она нам не подходит)
            }
        }

        // Если вся строка проверена и в ней НЕ нашлось ни одного попадания
        if (!estPopadanie)
        {
            naidennyIndex = static_cast<int>(i);
            break; // Досрочный выход из внешнего цикла (первая подходящая строка найдена!)
        }
    }

    return naidennyIndex;
}

// --- Функция-тестер для запуска под разные типы ---
template <typename T>
void zapuskZadachi(const string &typeName)
{
    cout << "\n=== Тестирование типа: " << typeName << " ===\n";

    int rows = vvediChislo("Введите количество строк (1-10): ", 1, 10);
    int cols = vvediChislo("Введите количество столбцов (1-10): ", 1, 10);

    // Создаем двумерный вектор с помощью STL
    vector<vector<T>> matrix(rows, vector<T>(cols));

    int ch = vvediChislo("Выберите способ заполнения (1 - вручную, 2 - случайно): ", 1, 2);
    if (ch == 1)
    {
        for (int i = 0; i < rows; ++i)
        {
            cout << "Заполнение строки " << i << ":\n";
            for (int j = 0; j < cols; ++j)
            {
                cout << "  Элемент [" << i << "][" << j << "]:\n";
                matrix[i][j] = vvestiElement<T>();
            }
        }
    }
    else
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = sgenerirovatElement<T>();
        cout << "Матрица успешно заполнена случайными значениями.\n";
    }

    cout << "\nИсходная матрица:\n";
    pechatMatricy(matrix);

    // Ввод границ диапазона
    cout << "\nЗадайте диапазон проверки [минимум, максимум]\n";
    if constexpr (is_same_v<T, Complex>)
    {
        cout << "(Внимание: для комплексных чисел проверка идет по их модулю)\n";
    }
    double minBound = vvediDrobnoye("Введите левую границу (минимум): ");
    double maxBound = vvediDrobnoye("Введите правую границу (максимум): ");

    if (minBound > maxBound)
    {
        cout << "Вы ввели минимум больше максимума. Поменяю их местами.\n";
        swap(minBound, maxBound);
    }

    // Решение
    int resultIndex = naitiStrokuBezDiapazona(matrix, minBound, maxBound);

    cout << "\n--- РЕЗУЛЬТАТ ---\n";
    if (resultIndex != -1)
    {
        cout << "Найдена строка, не содержащая элементов в диапазоне [" << minBound << "; " << maxBound << "].\n";
        cout << "Номер строки (индекс): " << resultIndex << "\n";
    }
    else
    {
        cout << "В исходном массиве искомых строк НЕТ (в каждой строке есть хоть один элемент из диапазона).\n";
    }
}

int main()
{
    // Настройка локали для корректного вывода на русском языке
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int repeat;
    do
    {
        cout << "\nВыберите тип данных для тестирования программы:\n";
        cout << "1 - Стандартный тип (double)\n";
        cout << "2 - Пользовательский тип (Complex)\n";

        int choice = vvediChislo("Ваш выбор: ", 1, 2);

        if (choice == 1)
            zapuskZadachi<double>("double (стандартный)");
        else
            zapuskZadachi<Complex>("Complex (пользовательский)");

        repeat = vvediChislo("\nХотите протестировать программу снова? (1 - да / 0 - нет): ", 0, 1);

    } while (repeat == 1);

    cout << "Программа завершена";
    return 0;
}