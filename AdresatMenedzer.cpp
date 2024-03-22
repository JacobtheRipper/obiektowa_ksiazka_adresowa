#include <iostream>
#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"

AdresatMenedzer::AdresatMenedzer() {
    idOstatniegoAdresata = 0;
}

AdresatMenedzer::~AdresatMenedzer() {
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;

    adresat.ustawId(idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    std::cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    std::cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    std::cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    std::cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    std::cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    std::cout << std::endl << "Id:                 " << adresat.pobierzId() << std::endl;
    std::cout << "Imie:               " << adresat.pobierzImie() << std::endl;
    std::cout << "Nazwisko:           " << adresat.pobierzNazwisko() << std::endl;
    std::cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << std::endl;
    std::cout << "Email:              " << adresat.pobierzEmail() << std::endl;
    std::cout << "Adres:              " << adresat.pobierzAdres() << std::endl;
}

void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;

    std::system("cls");
    std::cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << std::endl << std::endl;
    ++idOstatniegoAdresata;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    //dopiszAdresataDoPliku(adresat);
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    std::system("cls");
    if (!adresaci.empty()) {
        std::cout << "             >>> ADRESACI <<<" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::vector<Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        std::cout << std::endl;
    }
    else {
        std::cout << std::endl << "Ksiazka adresowa jest pusta." << std::endl << std::endl;
    }
    std::system("pause");
}

bool AdresatMenedzer::czySaAdresaci() {
    return !adresaci.empty();
}

void AdresatMenedzer::ustawIdOstatniegoAdresata (int noweId) {
    if (noweId >= 0) {
        idOstatniegoAdresata = noweId;
    }
}

int AdresatMenedzer::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}
