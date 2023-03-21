#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    progLib::Library book[2];
    const char* pathLib = "Books in library.txt";
    cout << "\n==============================MENU===================================\n";
    int value = 0;
    cout << "\n1.) Заполнение каталога книг.(При выборе этого пункта вся предыдущая информация будет уничтоженна!!!)";
    cout << "\n2.) Вывод каталога на экран.";
    cout << "\n3.) Поиск книги по названию.";
    cout << "\n4.) Печать одной книги.";
    cout << "\nВыберите пункт меню для работы с файлом библиотеки: ";
    cin >> value;
    cout << endl;
    
    if (value == 1) {
        progLib::inputOfInformationAboutBooks(book, pathLib);
    }
   
    if (value == 2) {
        progLib::outputOfInformationAboutBooks(book, pathLib);
    }
    if (value == 3) {
        progLib::findBookByTitle(book, pathLib);
    }
    if (value == 4) {
        progLib::printOneBook(book, pathLib);
    }
}
