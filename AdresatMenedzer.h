#ifndef ADRESAT_MENEDZER_H
#define ADRESAT_MENEDZER_H

#include<vector>
#include "Adresat.h"

class AdresatMenedzer {
private:
    int idOstatniegoAdresata;
    std::vector<Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
public:
    AdresatMenedzer();
    ~AdresatMenedzer();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();

    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstatniegoAdresata();
};

#endif
