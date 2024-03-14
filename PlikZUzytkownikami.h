#ifndef PLIK_Z_UZYTKOWNIKAMI_H
#define PLIK_Z_UZYTKOWNIKAMI_H

#include <string>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"

class PlikZUzytkownikami {
private:
    std::string nazwaPlikuZUzytkownikami;
    std::fstream plikTekstowy;
    bool czyPlikJestPusty();
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikZUzytkownikami();
    ~PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector<Uzytkownik> wczytajUzytkownikowZPliku();
};

#endif
