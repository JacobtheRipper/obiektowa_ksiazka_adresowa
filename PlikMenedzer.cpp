#include <iostream>
#include <fstream>
#include "PlikMenedzer.h"
#include "MetodyPomocnicze.h"

PlikMenedzer::PlikMenedzer(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami)
    : nazwaPlikuZUzytkownikami(nazwaPlikuZUzytkownikami), nazwaPlikuZAdresatami(nazwaPlikuZAdresatami) {
}

PlikMenedzer::~PlikMenedzer() {
}

void PlikMenedzer::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    std::string liniaZDanymiUzytkownika = "";
    std::fstream plikTekstowy;

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), std::ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else {
            plikTekstowy << std::endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << std::endl;
    plikTekstowy.close();
}

std::vector<Uzytkownik> PlikMenedzer::wczytajUzytkownikowZPliku() {
    Uzytkownik uzytkownik;
    std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    std::vector<Uzytkownik> uzytkownicy;
    std::fstream plikTekstowy;

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), std::ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)) {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
    }

    plikTekstowy.close();

    return uzytkownicy;
}

void PlikMenedzer::zapiszWszystkichUzytkownikowDoPliku(std::vector<Uzytkownik> &uzytkownicy) {
    std::fstream plikTekstowy;
    std::string liniaZDanymiUzytkownika = "";
    std::vector<Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), std::ios::out);

    if (plikTekstowy.good() == true) {
        for (std::vector<Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec) {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else {
                plikTekstowy << liniaZDanymiUzytkownika << std::endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else {
        std::cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << std::endl;
    }
    plikTekstowy.close();
};

bool PlikMenedzer::czyPlikJestPusty(std::fstream &plikTekstowy) {
    plikTekstowy.seekg(0, std::ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

std::string PlikMenedzer::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    std::string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwersjaIntNaString(uzytkownik.pobierzId()) + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

Uzytkownik PlikMenedzer::pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    Uzytkownik uzytkownik;
    std::string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}
