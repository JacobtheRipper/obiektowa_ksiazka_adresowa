#ifndef ADRESAT_MENEDZER_H
#define ADRESAT_MENEDZER_H

#include<vector>
#include "Adresat.h"
#include "AdresaciPlikMenedzer.h"

class AdresatMenedzer {
private:
    int idOstatniegoAdresata;
    std::vector<Adresat> adresaci;
    AdresaciPlikMenedzer adresaciPlikMenedzer;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
public:
    AdresatMenedzer(std::string nazwaPlikuZAdresatami);
    ~AdresatMenedzer();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    bool czySaAdresaci();

    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstatniegoAdresata();
};

#endif
