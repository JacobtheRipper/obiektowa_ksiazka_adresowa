#include <iostream>
#include "UzytkownikMenedzer.h"

UzytkownikMenedzer::UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    idZalogowanegoUzytkownika = 0;
}

UzytkownikMenedzer::~UzytkownikMenedzer() {
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do {
        std::cout << std::endl << "Podaj login: ";
        uzytkownik.ustawLogin(wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    std::cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(std::string login) {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }

    return false;
}

std::string UzytkownikMenedzer::wczytajLinie() {
    std::string wejscie = "";
    std::getline(std::cin, wejscie);
    return wejscie;
}

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");
}

int UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    std::string login = "", haslo = "";

    std::cout << std::endl << "Podaj login: ";
    login = wczytajLinie();

    std::vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                std::cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    std::cout << std::endl << "Zalogowales sie." << std::endl << std::endl;
                    std::system("pause");
                    return itr -> pobierzId();
                }
            }
            std::cout << "Wprowadzono 3 razy bledne haslo." << std::endl;
            std::system("pause");
            return 0;
        }
        itr++;
    }
    std::cout << "Nie ma uzytkownika z takim loginem" << std::endl << std::endl;
    std::system("pause");
    return 0;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        std::cout << uzytkownicy[i].pobierzId() << std::endl;
        std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
        std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweId) {
    if (noweId >= 0) {
        idZalogowanegoUzytkownika = noweId;
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
