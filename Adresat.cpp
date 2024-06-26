#include "Adresat.h"

Adresat::Adresat() {
}

Adresat::Adresat(int id, int idUzytkownika, std::string imie,
        std::string nazwisko, std::string numerTelefonu,
        std::string email, std::string adres) {
    this -> id = id;
    this -> idUzytkownika = idUzytkownika;
    this -> imie = imie;
    this -> nazwisko = nazwisko;
    this -> numerTelefonu = numerTelefonu;
    this -> email = email;
    this -> adres = adres;
}

Adresat::~Adresat() {
}

void Adresat::ustawId(int noweId) {
    if (noweId >= 0) {
        id = noweId;
    }
}

void Adresat::ustawIdUzytkownika(int noweId) {
    if (noweId >= 0) {
        idUzytkownika = noweId;
    }
}

void Adresat::ustawImie(std::string noweImie) {
    imie = noweImie;
}

void Adresat::ustawNazwisko(std::string noweNazwisko) {
    nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(std::string nowyNumerTelefonu) {
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEmail(std::string nowyEmail) {
    email = nowyEmail;
}

void Adresat::ustawAdres(std::string nowyAdres) {
    adres = nowyAdres;
}

int Adresat::pobierzId() {
    return id;
}

int Adresat::pobierzIdUzytkownika() {
    return idUzytkownika;
}

std::string Adresat::pobierzImie() {
    return imie;
}

std::string Adresat::pobierzNazwisko() {
    return nazwisko;
}

std::string Adresat::pobierzNumerTelefonu() {
    return numerTelefonu;
}

std::string Adresat::pobierzEmail() {
    return email;
}

std::string Adresat::pobierzAdres() {
    return adres;
}
