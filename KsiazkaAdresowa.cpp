#include<iostream>
#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami) {
}

KsiazkaAdresowa::~KsiazkaAdresowa() {
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return interfejsUzytkownika.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return interfejsUzytkownika.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() != 0) {
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
    adresatMenedzer.usunAdresatowPrzyWylogowaniu();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::uruchomPetleGlownaProgramu() {
    char wybor;

    while (true) {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                std::system("pause");
                break;
            }
        }
        else {
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                adresatMenedzer.dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
                break;
            case '2':
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                adresatMenedzer.wypiszWszystkichAdresatow();
                break;
            case '5':
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //edytujAdresata(adresaci);
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogujUzytkownika();
                break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                std::system("pause");
                break;
            }
        }
    }
}
