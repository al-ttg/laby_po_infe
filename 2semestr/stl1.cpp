/*1.Решить индивидуальную задачу с использованием контейнера vector
библиотеки STL.
22.Дан массив А(N) , где N-<=15 и вводится. Записать все элементы массива, начиная с минимального
в обратном порядке.*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
#include <vector>    // Podklyuchaem konteyner vector
#include <algorithm> // Podklyuchaem algoritmy STL (dlya min_element)

using namespace std;

// --- FUNKCII VVODA (OSTAVLENY BEZ IZMENENIY LOGIKI, NO VYVOD NA TRANSLITE) ---

int vvediChislo(const string &msg, int min, int max)
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
            catch (...)
            {
            }
        }
        cout << "Oshibka! Vvedite celoe chislo ot " << min << " do " << max << ".\n";
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
                if (c == ',')
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                try
                {
                    size_t pos;
                    x = stod(line, &pos);
                    if (pos == line.size())
                        return x;
                }
                catch (...)
                {
                }
            }
        }
        cout << "Oshibka! Vvedite veshchestvennoe chislo (razdelitel — tochka).\n";
    }
}

// --- OSNOVNAYA LOGIKA ZADACHI ---

void reshitZadachuSTL()
{
    cout << "\n--- Individualnaya zadacha (STL Vector) ---\n";

    // Vvodim razmer N (po usloviyu N <= 15)
    int n = vvediChislo("Vvedite razmer massiva N (1-15): ", 1, 15);

    // Sozdaem STL-konteyner vector na N elementov tipa double
    vector<double> A(n);

    // Vybor sposoba zapolneniya
    int ch = vvediChislo("1 - ruchnoy vvod, 2 - sluchayno: ", 1, 2);
    if (ch == 1)
    {
        cout << "\nZapolnenie massiva vruchnuyu:\n";
        for (int i = 0; i < n; i++)
        {
            string msg = "Element [" + to_string(i) + "]: ";
            A[i] = vvediDrobnoye(msg);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            // Sluchaynye veshchestvennye chisla ot -10.0 do 10.0
            A[i] = (rand() % 201 - 100) / 10.0;
        }
        cout << "Massiv zapolnen sluchaynymi chislami.\n";
    }

    // Vyvodim iskhodnyy massiv
    cout << "\nIskhodnyy massiv A:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  [" << i << "] = " << fixed << setprecision(2) << A[i] << "\n";
    }

    // 1. Poisk minimalnogo elementa s pomoshchyu STL algoritma std::min_element.
    auto minIt = min_element(A.begin(), A.end());
    
    // Poluchaem indeks minimalnogo elementa cherez rasstoyanie ot nachala vektora
    int minIndex = distance(A.begin(), minIt);

    cout << "\nMinimalnyy element: " << *minIt << " (indeks: " << minIndex << ")\n";

    // 2. Vyvod elementov, nachinaya s minimalnogo, v obratnom poryadke.
    cout << "Elementy ot minimalnogo do nachala v obratnom poryadke:\n";
    for (int i = minIndex; i >= 0; i--)
    {
        cout << "  [" << i << "] = " << fixed << setprecision(2) << A[i] << "\n";
    }
}

// --- MENYU PROGRAMMY ---

int main()
{
    srand(time(0));

    int repeat;
    do
    {
        cout << "\nВыберите действие (Viberite deystvie):\n";
        cout << "1 - Zapustit reshenie zadachi s std::vector\n";
        cout << "2 - Vyhod\n";

        int choice = vvediChislo("Vash vybor: ", 1, 2);

        if (choice == 1)
        {
            reshitZadachuSTL();
        }
        if (choice == 2)
        {
            break;
        }

        repeat = vvediChislo("\nPovtorit programmu? (1/0): ", 0, 1);

    } while (repeat == 1);

    cout << "\nProgramma uspeshno zavershena!\n";
    return 0;
}