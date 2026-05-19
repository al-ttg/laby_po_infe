#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("students.txt");
    ofstream fout("out.txt");
    if (!fin) {
        fout << "Ошибка открытия файла.\n";
        return 1;
    }

    string targetGroup;
    cout << "Введите группу для поиска: ";
    cin >> targetGroup;

    string line;
    int positiveCount = 0;

    fout << "\nСтуденты без стипендии:\n";

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string group, surname, name, patronymic;
        int birth, phys, math, inf;
        char gender;
        bool scholarship;

        ss >> group >> surname >> name >> patronymic
           >> birth >> gender >> phys >> math >> inf >> scholarship;

        if (group == targetGroup && !scholarship) {
            fout << surname << " " << name << " " << patronymic << endl;

            if (phys > 2 && math > 2 && inf > 2)
                positiveCount++;
        }
    }

    fout << "\nКоличество студентов без стипендии и с положительными оценками: "
         << positiveCount << endl;
    fin.close();    //
    fout.close();   //
    return 0;
}
