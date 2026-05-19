/*Дана целочисленная квадратная матрица N <=20 (вводится). Если  минимальный элемент всей матрицы 
  лежит  в заштрихованной области, то определить среднее арифметическое положительных элементов в 
  каждом четном столбце всей матрицы, если это условие не выполняется, то  переписать строку с  
  минимальным элементом  в обратном порядке.
  */


#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Matrix {
private:
    int n;
    int a[20][20];

public:
    void setSize(int size) {
        n = size;
    }

    int getSize() {
        return n;
    }

    int get(int i, int j) {
        return a[i][j];
    }

    void set(int i, int j, int value) {
        a[i][j] = value;
    }

    void inputManual() {
        cout << "Введите элементы матрицы:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
    }

    void inputRandom() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = rand() % 51 - 25;
    }

    void print() {
        cout << "\nМатрица:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(5) << a[i][j];
            cout << endl;
        }
    }

    bool inShaded(int i, int j) {
    bool sqr = (i >= n / 2) && (j >= n / 2);
    bool tri = (i < n / 2) && (j >= n / 2) && (i + j >= n - 1);
    return sqr || tri;
    }

   
    void solve() {
    int minVal = a[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] < minVal)
                minVal = a[i][j];

    int countMin = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == minVal)
                countMin++;

    int** positions = new int*[countMin];
    for (int k = 0; k < countMin; k++)
        positions[k] = new int[2]; 

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == minVal) {
                positions[idx][0] = i;
                positions[idx][1] = j;
                idx++;
            }

    
    int minI, minJ;
    if (countMin > 1) {
        cout << "\nНайдено несколько минимальных элементов (" << minVal << "):\n";
        for (int k = 0; k < countMin; k++)
            cout << k + 1 << " - строка " << positions[k][0]
                 << ", столбец " << positions[k][1] << endl;

        int choice;
        do {
            cout << "Выберите, какой минимальный элемент использовать (1-" 
                 << countMin << "): ";
            cin >> choice;
        } while (choice < 1 || choice > countMin);

        minI = positions[choice - 1][0];
        minJ = positions[choice - 1][1];
    } else {
        minI = positions[0][0];
        minJ = positions[0][1];
    }

    cout << "\nВыбранный минимальный элемент: " << minVal
         << " (строка " << minI << ", столбец " << minJ << ")\n";

    for (int k = 0; k < countMin; k++)
        delete[] positions[k];
    delete[] positions;

    if (inShaded(minI, minJ)) {
        cout << "\nМинимум в заштрихованной области\n";

        for (int j = 0; j < n; j += 2) {
            int sum = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (a[i][j] > 0) {
                    sum += a[i][j];
                    count++;
                }
            }
            if (count > 0)
                cout << "Среднее в столбце " << j << " = "
                     << (double)sum / count << endl;
            else
                cout << "В столбце " << j << " нет положительных элементов\n";
        }
    } else {
        cout << "\nМинимум НЕ в заштрихованной области\n";

        for (int j = 0; j < n / 2; j++)
            swap(a[minI][j], a[minI][n - 1 - j]);

        cout << "Строка с минимумом перевернута:\n";
        print();
    }
}
};

int main() {
    srand(time(0));
    int repeat;
    do {
        Matrix m;
        int n;
        cout << "Введите размер матрицы (<=20): ";
        cin >> n;
        m.setSize(n);

        int fillChoice;
        cout << "\nВыберите способ заполнения:\n";
        cout << "1 - Ручной ввод\n";
        cout << "2 - Случайно\n";
        cout << "Ваш выбор: ";
        cin >> fillChoice;

        if (fillChoice == 1)
            m.inputManual();
        else
            m.inputRandom();

        m.print();

        int solveChoice;
        cout << "\nВыберите способ решения:\n";
        cout << "1 - Метод класса\n";
        cout << "2 - Через main\n";
        cout << "Ваш выбор: ";
        cin >> solveChoice;

        if (solveChoice == 1) {
            m.solve();
        } else {
            int minVal = m.get(0, 0);
            int minI = 0, minJ = 0;

            for (int i = 0; i < m.getSize(); i++)
                for (int j = 0; j < m.getSize(); j++)
                    if (m.get(i, j) < minVal) {
                        minVal = m.get(i, j);
                        minI = i;
                        minJ = j;
                    }

            cout << "\nМинимальный элемент: " << minVal
                 << " (строка " << minI << ", столбец " << minJ << ")\n";

            if (minI <= minJ) {
                cout << "\nМинимум в заштрихованной области\n";

                for (int j = 0; j < m.getSize(); j += 2) {
                    int sum = 0, count = 0;

                    for (int i = 0; i < m.getSize(); i++) {
                        if (m.get(i, j) > 0) {
                            sum += m.get(i, j);
                            count++;
                        }
                    }

                    if (count > 0)
                        cout << "Среднее в столбце " << j << " = "
                             << (double)sum / count << endl;
                    else
                        cout << "В столбце " << j << " нет положительных элементов\n";
                }
            } else {
                cout << "\nМинимум НЕ в заштрихованной области\n";

                for (int j = 0; j < m.getSize() / 2; j++) {
                    int temp = m.get(minI, j);
                    m.set(minI, j, m.get(minI, m.getSize() - 1 - j));
                    m.set(minI, m.getSize() - 1 - j, temp);
                }

                cout << "Строка с минимумом перевернута:\n";
                m.print();
            }
        }

        cout << "\nПовторить? (1 - да, 0 - нет): ";
        cin >> repeat;

    } while (repeat == 1);

    return 0;
}