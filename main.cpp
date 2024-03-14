#include <iostream>
#include "KsiazkaAdresowa.h"

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Users.txt");

    std::cout << "\nWitaj uzytkowniku!" << std::endl;
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
