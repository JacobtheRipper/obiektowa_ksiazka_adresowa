#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include<string>

class Uzytkownik {
private:
    int id;
    std::string login;
    std::string haslo;
public:
    Uzytkownik();
    ~Uzytkownik();

    void ustawId(int noweId);
    void ustawLogin(std::string nowyLogin);
    void ustawHaslo(std::string noweHaslo);

    int pobierzId();
    std::string pobierzLogin();
    std::string pobierzHaslo();
};

#endif
