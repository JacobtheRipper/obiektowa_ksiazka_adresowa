#ifndef ADRESACI_PLIK_MENEDZER_H
#define ADRESACI_PLIK_MENEDZER_H

#include <string>
#include <vector>
#include <fstream>
#include "Adresat.h"

class AdresaciPlikMenedzer {
private:
    const std::string nazwaPlikuZAdresatami;
    
    bool czyPlikJestPusty(std::fstream &plikTekstowy);
    std::string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(std::string daneAdresataOddzielonePionowymiKreskami);
public:
    AdresaciPlikMenedzer(std::string nazwaPlikuZAdresatami);
    ~AdresaciPlikMenedzer();
    void dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(std::vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
};

#endif
