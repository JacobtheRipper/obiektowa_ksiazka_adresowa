#ifndef UZYTKOWNIK_MENEDZER_H
#define UZYTKOWNIK_MENEDZER_H

#include <vector>
#include "Uzytkownik.h"
#include "PlikMenedzer.h"

class UzytkownikMenedzer {
private:
    int idZalogowanegoUzytkownika;
    std::vector<Uzytkownik> uzytkownicy;
    PlikMenedzer plikMenedzer;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
public:
    UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami);
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
