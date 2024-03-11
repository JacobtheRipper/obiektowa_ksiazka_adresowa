#include<vector>
#include "Uzytkownik.h"

class KsiazkaAdresowa {
private:
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::string nazwaPlikuZUzytkownikami;
    std::vector<Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    std::string wczytajLinie();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::string konwersjaIntNaString(int liczba);
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    bool czyPlikJestPusty(std::fstream &plikTekstowy);
public:
    KsiazkaAdresowa();
    ~KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
