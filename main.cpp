#include <iostream>
#include "KsiazkaAdresowa.h"

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Users.txt");

    std::cout << "\nWitaj uzytkowniku!" << std::endl;
    ksiazkaAdresowa.uruchomPetleGlownaProgramu();

    return 0;
}
