
#include <iostream>
#include <iomanip>
#include "PhoneBook.h"
using namespace std;

PhoneBook* AddSub(PhoneBook* arrPB, int& size) {
    size++;
    PhoneBook* newArr = new PhoneBook[size];
    for (int i = 0; i < size - 1; i++) {
        newArr[i].copyData(arrPB[i].getName(), arrPB[i].getSurName(), arrPB[i].getMiddleName(), 
            arrPB[i].getHomeNumber(), arrPB[i].getWorkNumber(), arrPB[i].getMoreData());
    }
    delete[] arrPB;
    return newArr;
}
PhoneBook* DeleteSub(PhoneBook* arrPB, int& size, int index) {
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
void PrintSubs(PhoneBook* arrPB, int size) {
    for (int i = 0; i < size; i++) {
        cout << "||Number sub|| - " << i + 1 << endl;
        arrPB[i].printSub();
    }
}
void SearhSubOnName(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }           
    }
}
void SearhSubOnSurname(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getSurName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }
    }
}
void SearhSubOnMiddleName(PhoneBook* arrPB, int size) {
    char* buff = new char[125];
    for (int i = 0; i < size; i++) {
        if (strcmp(buff, arrPB[i].getMiddleName()) == 0) {
            cout << "||Number sub|| - " << i + 1 << endl;
            arrPB[i].printSub();
        }
    }
}
void SaveDataInFile(PhoneBook* arrPB, int size) {
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
}


int main()
{  
    int size = 0;
    PhoneBook* arrPB = new PhoneBook[size];
    
}

