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
