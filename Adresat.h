#ifndef ADRESAT_H
#define ADRESAT_H

#include<string>

class Adresat {
private:
    int id;
    int idUzytkownika;
    std::string imie;
    std::string nazwisko;
    std::string numerTelefonu;
    std::string email;
    std::string adres;
public:
    Adresat();
    ~Adresat();

    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweId);
    void ustawImie(std::string noweImie);
    void ustawNazwisko(std::string noweNazwisko);
    void ustawNumerTelefonu(std::string nowyNumerTelefonu);
    void ustawEmail(std::string nowyEmail);
    void ustawAdres(std::string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    std::string pobierzImie();
    std::string pobierzNazwisko();
    std::string pobierzNumerTelefonu();
    std::string pobierzEmail();
    std::string pobierzAdres();
};

#endif
