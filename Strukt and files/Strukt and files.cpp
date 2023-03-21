//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;
struct Library {
    char title[50]{ 0 };
    char author[50]{ 0 };
    char publishing[50]{ 0 };
    char genre[50]{ 0 };
    
};

void inputOfInformationAboutBooks(Library book[], const char* pathLib) {
    cout << "Вы собираетесь редактировать или перезаписывать файл, все данные будут удалены!!!" << endl;
    cout << "Введите КОД ДОСТУПА: ";
    int warning;
    cin >> warning;
    cout << endl;
    FILE* booksFileSave;
    fopen_s(&booksFileSave, pathLib, "w");
    if (warning == 1010) {
        for (int i = 0; i < 2; i++) {
            SetConsoleCP(1251);
            cout << "Введите название книги: ";
            cin >> ws;
            gets_s(book[i].title, 50);
            cout << "Введите имя автора: ";
            cin >> ws;
            gets_s(book[i].author, 50);
            cout << "Введите название издательства: ";
            cin >> ws;
            gets_s(book[i].publishing, 50);
            cout << "Введите жанр книги: ";
            cin >> ws;
            gets_s(book[i].genre, 50);
            fprintf(booksFileSave, "%s\n", book[i].title);
            fprintf(booksFileSave, "%s\n", book[i].author);
            fprintf(booksFileSave, "%s\n", book[i].publishing);
            fprintf(booksFileSave, "%s\n", book[i].genre);
            cout << "\n***********************************************************\n";
            SetConsoleCP(866);
        }
    }
    else {
        cout << "Не верный код доступа! В редактировании отказано!";
    }
    fclose(booksFileSave);
}

void outputOfInformationAboutBooks(Library book[], const char* pathLib) {
    FILE* booksUploadFile;
    fopen_s(&booksUploadFile, pathLib, "r");
    for (int i = 0; i < 2; i++) {
        SetConsoleCP(1251);
        fgets(book[i].title, 50, booksUploadFile);
        fgets(book[i].author, 50, booksUploadFile);
        fgets(book[i].publishing, 50, booksUploadFile);
        fgets(book[i].genre, 50, booksUploadFile);
        cout << "Название книги: " << book[i].title <<
            "\nАвтор книги: " << book[i].author <<
            "\nИздательство книги: " << book[i].publishing <<
            "\nЖанр книги: " << book[i].genre << endl;
        SetConsoleCP(866);
        cout << "\n--------------------------------------------------\n";
    }
}

void findBookByTitle() {
    char findTitle;
    for (int i = 0; i < 2; i++) {

    }
}

void findBookByAuthor() {

}

void findBookByGenre() {

}

void findBookByPublish() {

}

int main() {
    setlocale(LC_ALL, "RUS");
    Library book[10];
    const char* pathLib = "Books in library.txt";
    cout << "\n==============================MENU===================================\n";
    int value = 0;
    cout << "\n1.) Заполнение каталога книг.(При выборе этого пункта вся предыдущая информация будет уничтоженна!!!)";
    cout << "\n2.) Вывод каталога на экран.";
    cout << "\nВыберите пункт меню для работы с файлом библиотеки: ";
    cin >> value;
    cout << endl;
    
    if (value == 1) {
        inputOfInformationAboutBooks(book, pathLib);
    }
   
    if (value == 2) {
        outputOfInformationAboutBooks(book, pathLib);
    }
}
