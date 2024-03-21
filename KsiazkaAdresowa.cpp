#include<iostream>
#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
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
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
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

            //if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                //idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
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
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //wyswietlWszystkichAdresatow(adresaci);
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
                std::cout << "Funkcjonalnosc w trakcie realizacji" << std::endl;
                std::system("pause");
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                wylogujUzytkownika();
                //adresaci.clear();
                break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                std::system("pause");
                break;
            }
        }
    }
}
