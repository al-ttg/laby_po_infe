/*3.Решить индивидуальную задачу с использованием контейнера <list>
библиотеки STL.
Имеется информация по итогам экзаменов в институте всего в списке N человек. По
каждому из студентов имеются следующие сведения : фамилия , оценка по математике,
оценка по информатике и оценка по физике. Ввести информацию об экзаменах и
напечатать количество и фамилии студентов, которые сдали информатику с оценкой
отлично.*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
#include <list>     // Podklyuchaem konteyner list iz STL
#include <iterator> // Dlya raboty s iteratorami

using namespace std;

// --- FUNKCII VVODA (OSTAVLENY BEZ IZMENENIY, VYVOD NA TRANSLITE) ---

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

// --- STRUKTURA DLYA HRANENIYA DANNYH O STUDENTE ---

struct Student
{
    string fio; // Teper ispolzuem udobnyy std::string vmesto opasnyh char*
    int math;
    int info;
    int phys;
};

// --- OSNOVNAYA LOGIKA ZADACHI ---

void reshitZadachuListSTL()
{
    cout << "\n--- Zadacha s ispolzovaniem std::list ---\n";

    int n = vvediChislo("Vvedite kolichestvo studentov N (1-30): ", 1, 30);

    // Sozdaem spisok studentov s pomoshchyu STL list
    list<Student> studentList;

    // Vvod dannyh
    for (int i = 0; i < n; i++)
    {
        cout << "\nVvod dannyh dlya studenta #" << i + 1 << ":\n";
        Student s;
        
        cout << "Vvedite familiyu: ";
        getline(cin, s.fio);

        s.math = vvediChislo("Ocenka po matematike (2-5): ", 2, 5);
        s.info = vvediChislo("Ocenka po informatike (2-5): ", 2, 5);
        s.phys = vvediChislo("Ocenka po fizike (2-5): ", 2, 5);

        // Dobavlyaem element v konec STL-spiska
        studentList.push_back(s);
    }

    // Pechat polnogo spiska dlya proverki
    cout << "\nPolnyy spisok studentov:\n";
    // Ispolzuem sovremennyy cikl dlya prohoda po vsem elementam list
    for (const auto &s : studentList)
    {
        cout << "FIO: " << setw(15) << left << s.fio
             << " | Mat: " << s.math
             << " | Inf: " << s.info
             << " | Fiz: " << s.phys << "\n";
    }

    // Poisk i podschet otlichnikov po informatike
    cout << "\nStudenty, sdavshie informatiku na otlichno (ocenka 5):\n";
    int count = 0;

    // Prohodim po spisku s pomoshchyu iteratora (tak rabotaet svyazannyy spisok v STL)
    for (list<Student>::iterator it = studentList.begin(); it != studentList.end(); ++it)
    {
        if (it->info == 5)
        {
            cout << " - " << it->fio << "\n";
            count++;
        }
    }

    cout << "\nVsego otlichnikov po informatike: " << count << "\n";
}

// --- MENYU PROGRAMMY ---

int main()
{
    srand(time(0));

    int repeat;
    do
    {
        cout << "\nViberite deystvie:\n";
        cout << "1 - Zapustit reshenie zadachi s std::list\n";
        cout << "2 - Vyhod\n";

        int choice = vvediChislo("Vash vybor: ", 1, 2);

        if (choice == 1)
        {
            reshitZadachuListSTL();
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