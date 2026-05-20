/*
Используя класс list, созданный ранее, и добавив к нему необходи-
мые методы, решить следующую задачу
Имеется информация по итогам экзаменов в институте, всего в
списке N человек. По каждому из студентов имеются следующие сведе-
ния: фамилия, оценка по математике, оценка по информатике и оценка по
физике. Ввести информацию об экзаменах и напечатать количество и фа-
милии студентов, которые сдали информатику с оценкой отлично*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <string>
#include <cstring>

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
        cout << "Oshibka! Vvedite celoe chislo ot "
             << min << " do " << max << ".\n";
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

        cout << "Oshibka! Vvedite veshchestvennoe chislo "
             << "(razdelitel — tochka).\n";
    }
}

struct student
{
    char *fio;
    int math;
    int info;
    int phys;
    student *next;
};

class list
{
    int size;
    student *h;

public:
    list()
    {
        h = 0;
        size = 0;
    }

    ~list()
    {
        relase();
    }

    void pred()
    {
        student *temp = new student;
        string str;

        cout << "Vvedite familiyu studenta: ";
        getline(cin, str);

        temp->fio = new char[str.length() + 1];
        strcpy(temp->fio, str.c_str());

        temp->math = vvediChislo(
            "Ocenka po matematike (2-5): ", 2, 5);

        temp->info = vvediChislo(
            "Ocenka po informatike (2-5): ", 2, 5);

        temp->phys = vvediChislo(
            "Ocenka po fizike (2-5): ", 2, 5);

        temp->next = h;
        h = temp;
        size++;
    }

    void print();
    void relase();

    void del()
    {
        if (h == 0)
            return;

        student *temp = h;
        h = h->next;

        delete[] temp->fio;
        delete temp;
    }

    int g_size()
    {
        return size;
    }

    student *elem(int i);

    int printExcellentInfoStudents()
    {
        student *temp = h;
        int count = 0;

        cout << "\nStudenty, sdavshie informatiku "
             << "na otlichno (ocenka 5):\n";

        while (temp != 0)
        {
            if (temp->info == 5)
            {
                cout << " - " << temp->fio << "\n";
                count++;
            }

            temp = temp->next;
        }

        return count;
    }
};

void list::relase()
{
    while (h != 0)
        del();

    size = 0;
}

void list::print()
{
    student *temp = h;

    cout << "\nPolnyy spisok studentov:\n";

    while (temp != 0)
    {
        cout << "FIO: " << setw(15) << left << temp->fio
             << " | Mat: " << temp->math
             << " | Inf: " << temp->info
             << " | Fiz: " << temp->phys << endl;

        temp = temp->next;
    }
}

student *list::elem(int i)
{
    student *temp = h;

    for (int j = 0; j < i && temp != 0; j++)
        temp = temp->next;

    return temp;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");

    int repeat;

    do
    {
        cout << "\nVyberite zadachu:\n";
        cout << "1 - Vvod dannyh sessii studentov "
             << "i poisk otlichnikov po informatike\n";

        cout << "2 - Vyhod iz programmy\n";

        int choice = vvediChislo(
            "Vash vybor: ", 1, 2);

        if (choice == 1)
        {
            list studentList;

            int n = vvediChislo(
                "Vvedite kolichestvo studentov N (1-30): ",
                1, 30);

            for (int i = 0; i < n; i++)
            {
                cout << "\nVvod dannyh dlya studenta №"
                     << i + 1 << ":\n";

                studentList.pred();
            }

            studentList.print();

            int count =
                studentList.printExcellentInfoStudents();

            cout << "\nVsego studentov s otlichnoy "
                 << "ocenkoy po informatike: "
                 << count << "\n";
        }

        if (choice == 2)
        {
            break;
        }

        repeat = vvediChislo(
            "\nPovtorit programmu? (1/0): ",
            0, 1);

    } while (repeat == 1);

    cout << "\nProgramma zavershena.\n";

    return 0;
}