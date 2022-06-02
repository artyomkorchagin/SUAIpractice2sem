#include "header.h"

int main()
{
    setlocale(0, "");  //установка кодировки для ввода и вывода кириллицы в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double Time = 0;   //время работы сортировки
    string file_name;
    system("cls");
    cout << "Введите название файла или путь к файлу: ";
    char str[1024];
    cin.getline(str, 1024);
    file_name = string(str);
    ifstream file(file_name);
    if (file.is_open()) {
        string first_text, str;
        cout << "Cортируем\n";

        //читаем текст из файла
        while (getline(file, str)) {
            if (!file.eof())
                first_text += str + "\n";
            else
                first_text += str;
        }
        string* words = SeparateWords(first_text);       //формируем слова в массив
        words = CombSort(words, Time);                         //сортировка
        CreateOutput(words, first_text, Time);                 //формирование файла output.txt и analysis.txt
        cout << "Сортировка прошла успешно.";
    }
    else {
        cout << "Файл " + file_name + " не найден.";
    }
}
