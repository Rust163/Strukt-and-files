#include <iostream>
#include <stdio.h>
#include <string.h>
#include "windows.h"
#include "Header.h"
using namespace std;

namespace progLib {
    void printOneBook(Library book[], const char* pathLib) {
        
    }

    void inputOfInformationAboutBooks(Library book[], const char* pathLib) {
        cout << "�� ����������� ������������� ��� �������������� ����, ��� ������ ����� �������!!!" << endl;
        cout << "������� ��� �������: ";
        int warning;
        cin >> warning;
        cout << endl;
        FILE* booksFileSave;
        fopen_s(&booksFileSave, pathLib, "w");
        if (warning == 1010) {
            SetConsoleCP(1251);
            for (int i = 0; i < 2; i++) {
                cout << "������� �������� �����: ";
                cin >> ws;
                gets_s(book[i].title, 50);
                cout << "������� ��� ������: ";
                cin >> ws;
                gets_s(book[i].author, 50);
                cout << "������� �������� ������������: ";
                cin >> ws;
                gets_s(book[i].publishing, 50);
                cout << "������� ���� �����: ";
                cin >> ws;
                gets_s(book[i].genre, 50);
                fprintf(booksFileSave, "%s\n", book[i].title);
                fprintf(booksFileSave, "%s\n", book[i].author);
                fprintf(booksFileSave, "%s\n", book[i].publishing);
                fprintf(booksFileSave, "%s\n", book[i].genre);
                cout << "\n***********************************************************\n";
            }
            SetConsoleCP(866);
        }
        else {
            cout << "�� ������ ��� �������! � �������������� ��������!";
        }
        fclose(booksFileSave);
    }

    void outputOfInformationAboutBooks(Library book[], const char* pathLib) {
        FILE* booksUploadFile;
        fopen_s(&booksUploadFile, pathLib, "r");
        SetConsoleCP(1251);
        for (int i = 0; i < 2; i++) {
            fgets(book[i].title, 50, booksUploadFile);
            fgets(book[i].author, 50, booksUploadFile);
            fgets(book[i].publishing, 50, booksUploadFile);
            fgets(book[i].genre, 50, booksUploadFile);
            cout << "�������� �����: " << book[i].title <<
                "\n����� �����: " << book[i].author <<
                "\n������������ �����: " << book[i].publishing <<
                "\n���� �����: " << book[i].genre << endl;
            cout << "\n--------------------------------------------------\n";
        }
        SetConsoleCP(866);
    }

    void findBookByTitle(Library book[], const char* pathLib) {
        FILE* booksUploadFile;
        fopen_s(&booksUploadFile, pathLib, "r");
        char findTitle[50];
        cout << "������� �������� �����: ";
        cin >> findTitle, 50; 
        for (int i = 0; i < 2; i++) {
            fgets(book[i].title, 50, booksUploadFile);
            if (strncmp(book[i].title, findTitle, 50) == 0) {
                fgets(book[i].title, 50, booksUploadFile);
                fgets(book[i].author, 50, booksUploadFile);
                fgets(book[i].publishing, 50, booksUploadFile);
                fgets(book[i].genre, 50, booksUploadFile);
                cout << "�������� �����: " << book[i].title <<
                    "\n����� �����: " << book[i].author <<
                    "\n������������ �����: " << book[i].publishing <<
                    "\n���� �����: " << book[i].genre << endl;
            }
            else {
                cout << "������ ����� ��� � ��������";
            }
        }
    }

    void findBookByAuthor() {

    }

    void findBookByGenre() {

    }

    void findBookByPublish() {

    }
}