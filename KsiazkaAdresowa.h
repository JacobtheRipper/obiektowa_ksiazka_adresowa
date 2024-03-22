#ifndef KSIAZKA_ADRESOWA_H
#define KSIAZKA_ADRESOWA_H

#include<vector>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "InterfejsUzytkownika.h"

class KsiazkaAdresowa {
private:
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    InterfejsUzytkownika interfejsUzytkownika;
    
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
public:
    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami);
    ~KsiazkaAdresowa();
    void uruchomPetleGlownaProgramu();
};

#endif
