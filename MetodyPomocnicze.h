#ifndef METODY_POMOCNICZE_H
#define METODY_POMOCNICZE_H

class MetodyPomocnicze {
private:
public:
    MetodyPomocnicze();
    ~MetodyPomocnicze();
    static std::string konwersjaIntNaString(int liczba);
    static int konwersjaStringNaInt(std::string liczba);
    static std::string wczytajLinie();
    static std::string zamienPierwszaLitereNaDuzaAPozostaleNaMale(std::string tekst);
    static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    static std::string pobierzLiczbe(std::string tekst, int pozycjaZnaku);
};

#endif
