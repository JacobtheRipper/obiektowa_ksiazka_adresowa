#ifndef KSIAZKA_ADRESOWA_H
#define KSIAZKA_ADRESOWA_H

#include<vector>
#include "UzytkownikMenedzer.h"

class KsiazkaAdresowa {
private:
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    UzytkownikMenedzer uzytkownikMenedzer;
public:
    KsiazkaAdresowa();
    ~KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
