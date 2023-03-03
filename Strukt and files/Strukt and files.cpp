#include <iostream>
#include "windows.h"
using namespace std;
struct Library {
    char title[20];
    char author[20];
    char publishing[20];
    char genre[20];
    void showBooks() {
        cout << "Название книги: " << title <<
            "\nАвтор книги: " << author <<
            "\nИздательство книги: " << publishing <<
            "\nЖанр книги: " << genre << endl;
        cout << "\n--------------------------------------------------\n";
    }
};

void outputBooks(Library book[], errno_t err) {
    cout << "Вы собираетесь редактировать или перезаписывать файл, все данные будут удалены!!!" << endl;
    cout << "Введите КОД ДОСТУПА: ";
    int warning;
    cin >> warning;
    cout << endl;
    FILE* out{};
    if (warning == 1001) {
        if (err == NULL) {
            for (int i = 0; i < 2; i++) {
                SetConsoleCP(1251);
                cout << "Введите название книги: " << gets_s(book[i].title);
                cin.get();
                cout << "Введите автора книги: " << gets_s(book[i].author);
                cin.get();
                cout << "Введите издательство книги: " << gets_s(book[i].publishing);
                cin.get();
                cout << "Введите жанр книги: " << gets_s(book[i].genre);
                cin.get();
                fprintf(out, "%20s ", book[i].title);
                fprintf(out, "%20s ", book[i].author);
                fprintf(out, "%20s ", book[i].publishing);
                fprintf(out, "%20s ", book[i].genre);
                SetConsoleCP(866);
                cout << "\n***********************************************\n";
            }
            fclose(out);
        }
    }
    else {
        cout << "Не верно указан КОД ДОСТУПА в доступе редакирования и записи отказано!!!";
    }
}

void inputBooks(Library book[], const char* pathLibrary) {
    FILE* in;
    errno_t err2 = fopen_s(&in, pathLibrary, "r");
    if (err2 == NULL) {
        for (int i = 0; i < 2; i++) {
            fscanf_s(in, "%20s ", book[i].title, 21);
            fscanf_s(in, "%20s ", book[i].author, 21);
            fscanf_s(in, "%20s ", book[i].publishing, 21);
            fscanf_s(in, "%20s ", book[i].genre, 21);
        }
    }
    book->showBooks();
}

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "\n=====================================МЕНЮ==================================\n";
    cout << "Выберите пункт меню для совершения действий со списком книг:" << endl;
    cout << "1. Заполнить каталог или дополнить(если файл уже создан и заполнялся ранее)." << endl;
    cout << "2. Вывести полный список книг." << endl;
    int value = 0;
    cin >> value;
    FILE* out;
    Library book[10];
    const char* pathLibrary = "books.txt";
    errno_t err = fopen_s(&out, pathLibrary, "w");
    if (value == 1) {
        outputBooks(book, err);
    }
    FILE* in{};
    Library bookIn[10];
    if (value == 2) {
        inputBooks(book, pathLibrary);
    }




    /*book[0]->title = "Оно";
    book[0]->author = "Кинг Стивен";
    book[0]->publishing = "Питер";
    book[0]->genre = "ужасы";

    book[1]->title = "Сияние";
    book[1]->author = "Кинг Стивен";
    book[1]->publishing = "Питер";
    book[1]->genre = "ужасы";

    book[2]->title = "Пролетая над гнездом кукушки";
    book[2]->author = "Кизи Кен";
    book[2]->publishing = "Питер";
    book[2]->genre = "трагедия";

    book[3]->title = "Война и мир";
    book[3]->author = "Толстой Лев Николаевич";
    book[3]->publishing = "АСТ";
    book[3]->genre = "эпопея";

    book[4]->title = "Анна Каренина";
    book[4]->author = "Толстой Лев Николаевич";
    book[4]->publishing = "АСТ";
    book[4]->genre = "трагедия";

    book[5]->title = "Хранители";
    book[5]->author = "Мур Алан";
    book[5]->publishing = "Азбука";
    book[5]->genre = "графический роман";

    book[6]->title = "Из ада";
    book[6]->author = "Мур Алан";
    book[6]->publishing = "Азбука";
    book[6]->genre = "графический роман";

    book[7]->title = "Бойцовский клуб";
    book[7]->author = "Паланик Чак";
    book[7]->publishing = "МИФ";
    book[7]->genre = "роман";

    book[8]->title = "Колыбельная";
    book[8]->author = "Паланик Чак";
    book[8]->publishing = "МИФ";
    book[8]->genre = "роман";

    book[9]->title = "Конан-варвар";
    book[9]->author = "Говард Роберт Ирвин";
    book[9]->publishing = "Слово";
    book[9]->genre = "фентези";*/





}