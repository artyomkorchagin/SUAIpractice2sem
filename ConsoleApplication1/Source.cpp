#include "header.h"

int amountOfWords;          //���������� ���� � ������

//�������� ����
string* SeparateWords(string text) {
    string* result;
    list<string> listofwords;
    text += " ";
    string word = "", s;
    bool IsWord = false;
    for (int i = 0; i < text.length(); i++) {
        s = tolower(text[i]);           //������� ������ ����� ����� � ������� ��������
            //������� ���� � ������
        if ((s >= "�" && s <= "�") || s == "�") {     //���� ����� ��������
            word += text[i];
            IsWord = true;
        }
        else {                                          //� ��������� ������
            if (IsWord)listofwords.push_back(word);     //������� ����� � ������
            IsWord = false;
            word = "";
        }
    }
    amountOfWords = listofwords.size();     //���������� ���������� ����

    //��������� ������������ ������ ���� ��� ����������� ����������
    result = new string[amountOfWords];
    for (int i = 0; i < amountOfWords; i++) {
        result[i] = listofwords.front();
        listofwords.pop_front();
    }
    return result;
}

//���������� ���������
string* CombSort(string* wordArr, double &Time) {
    string FirstLetterOfwordNow, FirstLetterOfwordNext, wordNow, wordNext;
    unsigned int startTime = clock();       //��������� �����
    int jump = amountOfWords;
    bool swapped = true;                    //���� ������������ ���������

    while (swapped)
    {
        if (jump > 1)
            jump -= 1;
        swapped = false;
        for (int i = 0; i + jump < amountOfWords; i++) {
            wordNow = wordArr[i];                       //�������� ����� �� ������� ����� � ���������� �����
            wordNext = wordArr[i + jump];
            FirstLetterOfwordNow = tolower(wordNow[0]); //"�����������" ������ ����� ���� ��� ���������
            FirstLetterOfwordNext = tolower(wordNext[0]);
            if (FirstLetterOfwordNow[0] > FirstLetterOfwordNext[0])
                swap(wordArr[i], wordArr[i + jump]), swapped = true;
        }
    }
    unsigned int endTime = clock();            //�������� �����
    Time = (endTime - startTime) / 1000.0;      //������� �����
    return wordArr;
}



//������������ ����� output.txt � analysis.txt
void CreateOutput(string* textArr, string first_text, double Time) {
    string text = "", word, s;
    string alphabet = "��������������������������������";
    int* array_count = new int[alphabet.size()]; //������ ���������� ���� �� ������ ������ ����� ������������� � ������

    //������� ���-�� ���� � ������ �� ������� ������� �������� � ������������ � ������ ���� � ���������� �������
    for (int i = 0; i < alphabet.size(); i++) {
        int count = 0;
        for (int j = 0; j < amountOfWords; j++) {
            word = textArr[j];
            s = tolower(word[0]);
            if (s[0] == alphabet[i]) {

                //������������ ������ ����� ����� ������ ���� �� ��������
                if (count == 0)
                    text += word;
                else
                    text += " " + word;
                count++;    //������� ���-�� ���� � ������ �� ������� ������� ��������
            }
        }
        if (count > 0)
            text += "\n";
        array_count[i] = count;
    }

    //��������� ���� output.txt
    text = text.substr(0, text.length() - 1);
    ofstream out("output.txt");
    out << text;
    out.close();

    //��������� ���� analysis.txt
    text = "��������� �����:\n" + first_text + "\n\n������� 8: ���������, �� ��������, �� �����������, ������������ �����, ���������� ���������\n";
    text += "���������� ����: " + to_string(amountOfWords) + "\n";
    stringstream stream;
    stream << fixed << setprecision(2) << Time;   //����� ���������� ��������� � ����� ������� ����� �������
    text += "����� ����������: " + stream.str() + " ������\n";
    text += "���������� (���������� ���� �� ������ ����� ��������):\n";

    //������������ ������ ���-�� ���� �� ��������
    for (int i = 0; i < alphabet.size(); i++) {
        text += alphabet[i]; text += " - "; text += to_string(array_count[i]);
        if (i < alphabet.size() - 1)
            text += "\n";
    }
    out.open("analysis.txt"); out << text; out.close();
}