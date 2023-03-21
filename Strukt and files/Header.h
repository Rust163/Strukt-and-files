#pragma once
namespace progLib {
    struct Library {
        char title[50]{ 0 };
        char author[50]{ 0 };
        char publishing[50]{ 0 };
        char genre[50]{ 0 };
    };
    void printOneBook(Library book[], const char* pathLib);
	void inputOfInformationAboutBooks(Library book[], const char* pathLib);
	void outputOfInformationAboutBooks(Library book[], const char* pathLib);
    void findBookByTitle(Library book[], const char* pathLib);
}