#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Ошибка открытия файлов.\n";
        return 1;
    }

    string line;

    while (getline(fin, line)) {
        string result;

        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == ',') {
                // убрать пробел перед запятой
                if (!result.empty() && result.back() == ' ')
                    result.pop_back();

                result += ','; // сама запятая

                // добавить пробел после запятой, если его нет
                if (i + 1 < line.size() && line[i + 1] != ' ')
                    result += ' ';
            } else {
                result += line[i];
            }
        }

        fout << result << "\n";
    }

    cout << "Готово. output.txt\n";
    fin.close();    //
    fout.close();   //
    return 0;
}
