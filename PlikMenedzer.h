#ifndef PLIK_MENEDZER_H
#define PLIK_MENEDZER_H

#include <string>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"

class PlikMenedzer {
private:
    const std::string nazwaPlikuZUzytkownikami;
    const std::string nazwaPlikuZAdresatami;
    
    bool czyPlikJestPusty(std::fstream &plikTekstowy);
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikMenedzer(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami);
    ~PlikMenedzer();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(std::vector <Uzytkownik> &uzytkownicy);
};

#endif
