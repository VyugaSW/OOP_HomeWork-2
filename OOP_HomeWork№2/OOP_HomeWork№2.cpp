#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include "PhoneBook.h"
using namespace std;

PhoneBook* AddSubPlus(PhoneBook* arrPB, int& size); //+Элемент массива
PhoneBook* DeleteSubMinus(PhoneBook* arrPB, int& size, int index); //-Элемент массива
void AddSub(PhoneBook* arrPB, int size); //Добавить абонемента
int DeleteSub(PhoneBook* arrPB, int size); //Удаление абонемета
void PrintSubs(PhoneBook* arrPB, int size); //Вывод всех абонементов
void SearchSubOnName(PhoneBook* arrPB, int size); //Поиск абонемента по имени
void SearchSubOnSurname(PhoneBook* arrPB, int size); //Поиск абонемента по фамилии
void SearchSubOnMiddleName(PhoneBook* arrPB, int size); //Поиск абонемента по отчеству
void SaveDataInFile(PhoneBook* arrPB, int size); //Сохранить в файл
void LoadDataFromFile(PhoneBook* arrPB, int size); //Загузить из файла

//+Элемент массива
PhoneBook* AddSubPlus(PhoneBook* arrPB, int& size) {
    size++;
    PhoneBook* newArr = new PhoneBook[size];
    for (int i = 0; i < size - 1; i++) {
        newArr[i].copyData(arrPB[i].getName(), arrPB[i].getSurName(), arrPB[i].getMiddleName(), 
            arrPB[i].getHomeNumber(), arrPB[i].getWorkNumber(), arrPB[i].getMoreData());
    }
    delete[] arrPB;
    return newArr;
}
//-Элемент массива
PhoneBook* DeleteSubMinus(PhoneBook* arrPB, int& size, int index) {
    size--;
    PhoneBook* newArr = new PhoneBook[size];
    for (int i = 0, k = 0; i < size + 1; i++) {
        if (i != index) {
            newArr[k].copyData(arrPB[i].getName(), arrPB[i].getSurName(), arrPB[i].getMiddleName(), 
                arrPB[i].getHomeNumber(),arrPB[i].getWorkNumber(), arrPB[i].getMoreData());
            k++;
        }
    }
    delete[] arrPB;
    return newArr;
}
//Добавить абонемента
void AddSub(PhoneBook* arrPB, int size) {
    system("cls");
    char* buffN = new char[125];
    char* buffS = new char[125];
    char* buffM = new char[125];
    int hmp, wmp;
    char* buffD = new char[125];
    cout << "Enter a sub's name:\n";
    gets_s(buffN, 126);
    cout << "Enter a sub's surname:\n";
    gets_s(buffS, 126);
    cout << "Enter a sub's middle name:\n";
    gets_s(buffM, 126);
    cout << "Enter a sub's home phone number:\n";
    cin >> hmp;
    cout << "Enter a sub's work phone number:\n";
    cin >> wmp;
    cin.ignore(126, '\n');
    cout << "Enter a extra data:\n";
    gets_s(buffD, 126);
    arrPB[size - 1].copyData(buffN, buffS, buffM, hmp, wmp, buffD);
}
//Удаление абонемета
int DeleteSub(PhoneBook* arrPB, int size) {
    system("cls");
    int choice;
    cout << "Numbers of subs\n";
    for (int i = 0; i < size; i++) {
        cout << "|" << i + 1 << "|" << endl;
    }   
    cout << endl;
    cin >> choice;
    return choice-1; //возращаем индекс элемента, который необходимо удалить
    cin.ignore(126, '\n');
}
//Вывод всех абонементов
void PrintSubs(PhoneBook* arrPB, int size) {
    system("cls");
    for (int i = 0; i < size; i++) {
        cout << "||Number sub|| - " << i + 1 << endl;
        arrPB[i].printSub();
    }
    cout << "Press any key to continue\n";
    _getch();
}
//Поиск абонемента по имени
void SearchSubOnName(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    cout << "Enter a searching name\n";
    gets_s(buff, 126);
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }           
    }
    cout << "Press any key to continue\n";
    _getch();
}
//Поиск абонемента по фамилии
void SearchSubOnSurname(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    cout << "Enter a searching surname\n";
    gets_s(buff, 126);
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getSurName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }
    }
    cout << "Press any key to continue\n";
    _getch();
}
//Поиск абонемента по отчеству
void SearchSubOnMiddleName(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    cout << "Enter a searching middle name\n";
    gets_s(buff, 126);
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getMiddleName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }
    }
    cout << "Press any key to continue\n";
    _getch();
}
//Сохранить в файл
void SaveDataInFile(PhoneBook* arrPB, int size) {
    system("cls");
    cin.ignore(126, '\n');
    FILE* in;
    int us;
    char* path = new char[125]; //Стезя к файлу
    cout << "Enter file path (Example: \"C:\\Test\\test.txt\"):\n\n";
    gets_s(path, 126);

    if (!fopen_s(&in, path, "w")) {
        for (int i = 0; i < size; i++) {
            fprintf(in, "%s\n", arrPB[i].getName(), 126);
            fprintf(in, "%s\n", arrPB[i].getSurName(), 126);
            fprintf(in, "%s\n", arrPB[i].getMiddleName(), 126);
            fprintf(in, "%d\n", arrPB[i].getHomeNumber(), sizeof(int));
            fprintf(in, "%d\n", arrPB[i].getWorkNumber(), sizeof(int));
            fprintf(in, "%s\n", arrPB[i].getMiddleName(), 126);
            puts("\n");
        }
        fclose(in);
        cout << "Saved successfully!\n";
    }
    else {
        cout << "WRONG!\n";
    }
    Sleep(1000);
}
//Загузить из файла
void LoadDataFromFile(PhoneBook* arrPB, int size) {
    system("cls");
    cin.ignore(126, '\n');
    FILE* in;
    int us;
    char* path = new char[125];
    cout << "Enter file path (Example: \"C:\\Test\\test.txt\"):\n\n";
    gets_s(path, 126);

    char* buffN = new char[125];
    char* buffS = new char[125];
    char* buffM = new char[125];
    int hmp = NULL, wmp = NULL;
    char* buffD = new char[125];

    if (!fopen_s(&in, path, "r")) {
        while (!feof(in)) {
            arrPB = AddSubPlus(arrPB, size);
            fscanf_s(in, "%s", &buffN,126);
            fscanf_s(in, "%s", &buffS,126);         //Ну не могу я решить проблему со считываем строки из файла
            fscanf_s(in, "%s", &buffM,126);         //Что это за гнусный миазм????????????????
            fscanf_s(in, "%d", &hmp,sizeof(int));
            fscanf_s(in, "%d", &wmp, sizeof(int));
            fscanf_s(in, "%s", &buffD,126);
            arrPB[size - 1].copyData(buffN, buffS, buffM, hmp, wmp, buffD);
        }
        fclose(in);
        cout << "Load successfully!\n";
    }
    else {
        cout << "WRONG!\n";
    }
    Sleep(1000);
}

int main()
{  
    int size = 0;
    PhoneBook* arrPB = new PhoneBook[size];
    bool flag = true;
    int choice;
    while (flag) {
        system("cls");
        cout << "1 - Add new sub\n";
        cout << "2 - Delete sub\n";
        cout << "3 - Print all subs\n";
        cout << "4 - Search sub on name\n";
        cout << "5 - Search sub on surname\n";
        cout << "6 - Search sub on middle name\n";
        cout << "7 - Save data in file\n";
        cout << "8 - Load from file (only if size = 0)\n";
        cin >> choice;
        switch (choice) {
        case 1:
            arrPB = AddSubPlus(arrPB, size);
            cin.ignore(126, '\n');
            AddSub(arrPB, size);
            break;
        case 2:
            arrPB = DeleteSubMinus(arrPB, size, DeleteSub(arrPB, size));
            break;
        case 3:
            PrintSubs(arrPB, size);
            break;
        case 4:
            SearchSubOnName(arrPB, size);
            break;
        case 5:
            SearchSubOnSurname(arrPB, size);
            break;
        case 6:
            SearchSubOnMiddleName(arrPB, size);
            break;
        case 7:
            SaveDataInFile(arrPB, size);
            break;
        case 8:
            if (size != 0) {
                cout << "\nsize != 0\n";
                Sleep(1500);
                break;
            }
            LoadDataFromFile(arrPB, size);
            break;
        }
    }
}

