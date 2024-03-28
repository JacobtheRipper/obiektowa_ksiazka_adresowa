#include <iostream>
#include <fstream>
#include "AdresaciPlikMenedzer.h"
#include "MetodyPomocnicze.h"

AdresaciPlikMenedzer::AdresaciPlikMenedzer(std::string nazwaPlikuZAdresatami)
    : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
}

AdresaciPlikMenedzer::~AdresaciPlikMenedzer() {
}

void AdresaciPlikMenedzer::dopiszAdresataDoPliku(Adresat adresat) {
    std::string liniaZDanymiAdresata = "";
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), std::ios::out | std::ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else {
            plikTekstowy << std::endl << liniaZDanymiAdresata;
        }
    }
    else {
        std::cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << std::endl;
    }
    plikTekstowy.close();
    std::system("pause");
}

std::vector<Adresat> AdresaciPlikMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    std::string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    std::vector<Adresat> adresaci;
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), std::ios::in);

    if (plikTekstowy.good() == true) {
        while (std::getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
    }

    plikTekstowy.close();

    return adresaci;
}

int AdresaciPlikMenedzer::wczytajIdOstatniegoAdresataZPliku() {
    int idOstatniegoAdresata = 0;
    std::string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    std::string daneOstaniegoAdresataWPliku = "";
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), std::ios::in);

    if (plikTekstowy.good() == true) {
        while (std::getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }

    return 0;
}

bool AdresaciPlikMenedzer::czyPlikJestPusty(std::fstream &plikTekstowy) {
    plikTekstowy.seekg(0, std::ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

std::string AdresaciPlikMenedzer::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    std::string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat AdresaciPlikMenedzer::pobierzDaneAdresata(std::string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    std::string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
