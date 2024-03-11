#include<vector>
#include "Uzytkownik.h"

class KsiazkaAdresowa {
private:
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::vector<Uzytkownik> uzytkownicy;
public:
    KsiazkaAdresowa();
    ~KsiazkaAdresowa();
    void rejestracjaUzytkownika();
};
