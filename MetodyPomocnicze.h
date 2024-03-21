#ifndef METODY_POMOCNICZE_H
#define METODY_POMOCNICZE_H

class MetodyPomocnicze {
private:
public:
    MetodyPomocnicze();
    ~MetodyPomocnicze();
    static std::string konwersjaIntNaString(int liczba);
    static std::string wczytajLinie();
    static std::string zamienPierwszaLitereNaDuzaAPozostaleNaMale(std::string tekst);
};

#endif
