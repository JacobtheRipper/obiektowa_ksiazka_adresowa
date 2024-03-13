#ifndef UZYTKOWNIK_MENEDZER_H
#define UZYTKOWNIK_MENEDZER_H

#include<vector>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

class UzytkownikMenedzer {
private:
    int idZalogowanegoUzytkownika;
    std::vector<Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    std::string wczytajLinie();
public:
    UzytkownikMenedzer();
    ~UzytkownikMenedzer();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif