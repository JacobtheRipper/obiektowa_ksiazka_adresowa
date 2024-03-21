#ifndef PLIK_Z_UZYTKOWNIKAMI_H
#define PLIK_Z_UZYTKOWNIKAMI_H

#include <string>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"

class PlikZUzytkownikami {
private:
    const std::string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty(std::fstream &plikTekstowy);
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikZUzytkownikami(std::string nazwaPlikuZUzytkownikami);
    ~PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(std::vector <Uzytkownik> &uzytkownicy);
};

#endif
