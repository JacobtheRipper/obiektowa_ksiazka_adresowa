#include <string>
#include <sstream>
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
