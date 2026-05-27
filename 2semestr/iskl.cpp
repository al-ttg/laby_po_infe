/* В программе, использующей разработанный класс, написать код для перехвата генерируемых исключений
22.	Необходимо генерировать исключения в следующих ситуациях: попытка доступа к элементу массива  
с неверным индексом; попытка добавить элемент больше запрещенного значения. (значение вводится)*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
#include <stdexcept> 

using namespace std;

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

class SafeArray
{
    int *arr;
    int size;
    int maxLimit;

public:
    SafeArray(int n, int limit)
    {
        size = n;
        maxLimit = limit;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    ~SafeArray()
    {
        delete[] arr;
    }

    void setElement(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Oshibka: Nevernyy indeks massiva!");
        }
        if (value > maxLimit)
        {
            throw invalid_argument("Oshibka: Znachenie " + to_string(value) + " bolshe zapreshchennogo poroga " + to_string(maxLimit) + "!");
        }
        arr[index] = value;
    }

    int getElement(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Target out of range!");
        }
        return arr[index];
    }

    void print()
    {
        cout << "\nTekushchiy massiv:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "  [" << i << "] = " << arr[i] << "\n";
        }
    }
};

void reshitZadachuExceptions()
{
    int n = vvediChislo("Vvedite razmer massiva N (1-15): ", 1, 15);
    int limit = vvediChislo("Vvedite zapreshchennyy porog znacheniya: ", -1000, 1000);

    SafeArray myArray(n, limit);

    int mode = vvediChislo("Vyberite sposob zapolneniya (1 - ruchnoy, 2 - sluchayno): ", 1, 2);

    if (mode == 1)
    {
        for (int i = 0; i < n; i++)
        {
            string msg = "Vvedite element [" + to_string(i) + "]: ";
            int val = vvediChislo(msg, -2000, 2000);
            
            try
            {
                myArray.setElement(i, val);
            }
            catch (const invalid_argument &e)
            {
                cout << "\n>>> Perehvacheno isklyuchenie: " << e.what() << "\n";
                cout << ">>> Element ne byl dobavlen! Vmesto nego zapisan 0.\n\n";
            }
        }
    }
    else
    {
        cout << "\nZapolnenie sluchaynymi chislami ot 1 do 10:\n";
        for (int i = 0; i < n; i++)
        {
            int val = rand() % 10 + 1;
            cout << "Generaciya elementa [" << i << "] = " << val << "... ";
            
            try
            {
                myArray.setElement(i, val);
                cout << "Uspeshno.\n";
            }
            catch (const invalid_argument &e)
            {
                cout << "\n>>> Perehvacheno isklyuchenie pri generacii: " << e.what() << "\n";
                cout << ">>> Element [" << i << "] ostalsya raven 0.\n\n";
            }
        }
    }

    myArray.print();

    cout << "\n--- Demonstraciya perehvata oshibki indeksa ---\n";
    int badIndex = vvediChislo("Vvedite indeks, kotoryy hotite proverit (specialno vvedite vne granic): ", -5, 20);

    try
    {
        int res = myArray.getElement(badIndex);
        cout << "Uspeshnyy dostup! Element [" << badIndex << "] = " << res << "\n";
    }
    catch (const out_of_range &e)
    {
        cout << "\n>>> Perehvacheno isklyuchenie: " << e.what() << "\n";
        cout << ">>> Programma ne vyletela, a bezopasno obrabotala etu oshibku!\n";
    }
}

int main()
{
    srand(time(0));

    int repeat;
    do
    {
        cout << "\nViberite deystvie:\n";
        cout << "1 - Zapustit reshenie zadachi s isklyucheniyami\n";
        cout << "2 - Vyhod\n";

        int choice = vvediChislo("Vash vybor: ", 1, 2);

        if (choice == 1)
        {
            reshitZadachuExceptions();
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