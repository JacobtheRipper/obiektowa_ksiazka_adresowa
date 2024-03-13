#ifndef PLIK_Z_UZYTKOWNIKAMI_H
#define PLIK_Z_UZYTKOWNIKAMI_H

#include <string>
#include <fstream>
#include "Uzytkownik.h"

class PlikZUzytkownikami {
private:
    std::string nazwaPlikuZUzytkownikami;
    std::fstream plikTekstowy;
    bool czyPlikJestPusty();
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
public:
    PlikZUzytkownikami();
    ~PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
