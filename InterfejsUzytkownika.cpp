#include <iostream>
#include "InterfejsUzytkownika.h"

InterfejsUzytkownika::InterfejsUzytkownika() {
}

InterfejsUzytkownika::~InterfejsUzytkownika() {
}

char InterfejsUzytkownika::wczytajZnak() {
    std::string wejscie = "";
    char znak  = {0};

    while (true) {
        std::getline(std::cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
    }
    return znak;
}

char InterfejsUzytkownika::wybierzOpcjeZMenuGlownego() {
    char wybor;

    std::system("cls");
    std::cout << "    >>> MENU  GLOWNE <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Rejestracja" << std::endl;
    std::cout << "2. Logowanie" << std::endl;
    std::cout << "9. Koniec programu" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char InterfejsUzytkownika::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    std::system("cls");
    std::cout << " >>> MENU UZYTKOWNIKA <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Dodaj adresata" << std::endl;
    std::cout << "2. Wyszukaj po imieniu" << std::endl;
    std::cout << "3. Wyszukaj po nazwisku" << std::endl;
    std::cout << "4. Wyswietl adresatow" << std::endl;
    std::cout << "5. Usun adresata" << std::endl;
    std::cout << "6. Edytuj adresata" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "7. Zmien haslo" << std::endl;
    std::cout << "8. Wyloguj sie" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}
