#ifndef UZYTKOWNICY_PLIK_MENEDZER_H
#define UZYTKOWNICY_PLIK_MENEDZER_H

#include <string>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"

class UzytkownicyPlikMenedzer {
private:
    const std::string nazwaPlikuZUzytkownikami;
    
    bool czyPlikJestPusty(std::fstream &plikTekstowy);
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    UzytkownicyPlikMenedzer(std::string nazwaPlikuZUzytkownikami);
    ~UzytkownicyPlikMenedzer();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(std::vector <Uzytkownik> &uzytkownicy);
};

#endif
