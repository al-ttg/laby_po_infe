#include <iostream>
#include <string>
using namespace std;

struct Student {
    string group;
    string surname, name, patronymic;
    int birth;
    char gender;
    int phys, math, inf;
    bool scholarship;
};

int main() {
    
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    // динамический массив
    Student* arr = new Student[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nСтудент " << i + 1 << ":\n";
        cout << "Группа: "; cin >> arr[i].group;
        cout << "Фамилия: "; cin >> arr[i].surname;
        cout << "Имя: "; cin >> arr[i].name;
        cout << "Отчество: "; cin >> arr[i].patronymic;
        cout << "Год рождения: "; cin >> arr[i].birth;
        cout << "Пол (M/F): "; cin >> arr[i].gender;
        cout << "Оценка по физике: "; cin >> arr[i].phys;
        cout << "Оценка по математике: "; cin >> arr[i].math;
        cout << "Оценка по информатике: "; cin >> arr[i].inf;
        cout << "Стипендия (1 — есть, 0 — нет): "; cin >> arr[i].scholarship;
    }

    string targetGroup;
    cout << "\nВведите группу для поиска: ";
    cin >> targetGroup;

    cout << "\nСтуденты без стипендии:\n";

    int positiveCount = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i].group == targetGroup && !arr[i].scholarship) {
            cout << arr[i].surname << " " << arr[i].name << " " << arr[i].patronymic << "\n";

            if (arr[i].phys > 2 && arr[i].math > 2 && arr[i].inf > 2)
                positiveCount++;
        }
    }

    cout << "\nКоличество студентов без стипендии и с положительными оценками: "
         << positiveCount << endl;

    delete[] arr; // освобождение памяти

    return 0;
}
