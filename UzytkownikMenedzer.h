#ifndef UZYTKOWNIK_MENEDZER_H
#define UZYTKOWNIK_MENEDZER_H

#include <vector>
#include "Uzytkownik.h"
#include "UzytkownicyPlikMenedzer.h"

class UzytkownikMenedzer {
private:
    int idZalogowanegoUzytkownika;
    std::vector<Uzytkownik> uzytkownicy;
    UzytkownicyPlikMenedzer uzytkownicyPlikMenedzer;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
public:
    UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami);
    ~UzytkownikMenedzer();
    
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
