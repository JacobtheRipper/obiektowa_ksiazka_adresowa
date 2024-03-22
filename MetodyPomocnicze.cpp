#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "MetodyPomocnicze.h"

MetodyPomocnicze::MetodyPomocnicze() {
}

MetodyPomocnicze::~MetodyPomocnicze() {
}

std::string MetodyPomocnicze::konwersjaIntNaString(int liczba) {
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(std::string liczba) {
    int liczbaInt;
    std::istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

std::string MetodyPomocnicze::wczytajLinie() {
    std::string wejscie = "";
    std::getline(std::cin, wejscie);
    return wejscie;
}

std::string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(std::string tekst) {
    if (!tekst.empty()) {
        std::transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

std::string MetodyPomocnicze::pobierzLiczbe(std::string tekst, int pozycjaZnaku) {
    std::string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
