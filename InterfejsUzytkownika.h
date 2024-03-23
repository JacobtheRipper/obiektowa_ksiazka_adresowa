#ifndef INTERFEJS_UZYTKOWNIKA_H
#define INTERFEJS_UZYTKOWNIKA_H

class InterfejsUzytkownika {
private:
    char wczytajZnak();
public:
    InterfejsUzytkownika();
    ~InterfejsUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
