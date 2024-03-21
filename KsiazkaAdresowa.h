#ifndef KSIAZKA_ADRESOWA_H
#define KSIAZKA_ADRESOWA_H

#include<vector>
#include "UzytkownikMenedzer.h"
#include "InterfejsUzytkownika.h"

class KsiazkaAdresowa {
private:
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    UzytkownikMenedzer uzytkownikMenedzer;
    InterfejsUzytkownika interfejsUzytkownika;
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
public:
    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami);
    ~KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void uruchomPetleGlownaProgramu();
};

#endif
