#include "header.h"

int amountOfWords;          //количество слов в тексте
double Time;
//создание слов
string* SeparateWords(string text) {
    string* result;
    list<string> listofwords;
    text += " ";
    string word = "", s;
    bool IsWord = false;
    for (int i = 0; i < text.length(); i++) {
        s = tolower(text[i]);           //перевод первой буквы слова к нижнему регистру
            //выборка слов в список
        if ((s >= "а" && s <= "я") || s == "ё") {     //если буква подходит
            word += text[i];
            IsWord = true;
        }
        else {                                          //в противном случае
            if (IsWord)listofwords.push_back(word);     //заносим слово в список
            IsWord = false;
            word = "";
        }
    }
    amountOfWords = listofwords.size();     //определяем количество слов

    //формируем динамический массив слов для последующей сортировки
    result = new string[amountOfWords];
    for (int i = 0; i < amountOfWords; i++) {
        result[i] = listofwords.front();
        listofwords.pop_front();
    }
    return result;
}

//сортировка расчёской
string* CombSort(string* wordArr) {
    string FirstLetterOfwordNow, FirstLetterOfwordNext, wordNow, wordNext;
    unsigned int startTime = clock();       //начальное время
    int jump = amountOfWords;
    bool swapped = true;                    //флаг перестановки элементов

    while (jump > 1 || swapped)
    {
        if (jump > 1)
            jump -= 1;
        swapped = false;
        for (int i = 0; i + jump < amountOfWords; i++) {
            wordNow = wordArr[i];                       //передаем слова из массива строк в переменные строк
            wordNext = wordArr[i + jump];
            FirstLetterOfwordNow = tolower(wordNow[0]); //"вытаскиваем" первые буквы слов для сравнения
            FirstLetterOfwordNext = tolower(wordNext[0]);
            if (FirstLetterOfwordNow[0] > FirstLetterOfwordNext[0])
                swap(wordArr[i], wordArr[i + jump]), swapped = true;
        }
    }
    unsigned int endTime = clock();            //конечное время
    Time=(double)(endTime-startTime)/(double)CLOCKS_PER_SEC;
    return wordArr;
}



//формирование файла output.txt и analysis.txt
void CreateOutput(string* textArr, string first_text) {
    string text = "", word, s;
    string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    int* array_count = new int[alphabet.size()]; //массив количества слов по каждой первой букве встречающиеся в тексте

    //подсчет кол-во слов в тексте по каждому символу алфавита и формирование в строки слов в алфавитном порядке
    for (int i = 0; i < alphabet.size(); i++) {
        int count = 0;
        for (int j = 0; j < amountOfWords; j++) {
            word = textArr[j];
            s = tolower(word[0]);
            if (s[0] == alphabet[i]) {

                //формирование текста через новую строку слов по алфавиту
                if (count == 0)
                    text += word;
                else
                    text += " " + word;
                count++;    //подсчет кол-во слов в тексте по каждому символу алфавита
            }
        }
        if (count > 0)
            text += "\n";
        array_count[i] = count;
    }

    //формируем файл output.txt
    text = text.substr(0, text.length() - 1);
    ofstream out("output.txt");
    out << text;
    out.close();

    //формируем файл analysis.txt
    text = "Введенный текст:\n" + first_text + "\n\nВариант 8: кириллица, по алфавиту, по возрастанию, игнорировать числа, сортировка расчёской\n";
    text += "Количество слов: " + to_string(amountOfWords) + "\n";
    stringstream stream;
    stream << fixed << setprecision(2) << Time;   //время сортировки формируем с двумя цифрами после запятой
    text += "Время сортировки: " + stream.str() + " секунд\n";
    text += "Статистика (количество слов на каждую букву алфавита):\n";

    //формирование текста кол-ва слов по алфавиту
    for (int i = 0; i < alphabet.size(); i++) {
        text += alphabet[i]; text += " - "; text += to_string(array_count[i]);
        if (i < alphabet.size() - 1)
            text += "\n";
    }
    out.open("analysis.txt"); out << text; out.close();
}