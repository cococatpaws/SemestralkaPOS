//
// Created by kamik on 3. 1. 2024.
//

#include "subor_handler.h"

SuborHandler::SuborHandler() {}

std::string SuborHandler::precitajZoSuboru(const std::string& nazovSuboru) {
    std::string precitanyVzor = "";

    std::ifstream subor;
    subor.open(nazovSuboru);
    if (subor.is_open()) {
        std::getline(subor, precitanyVzor);
        subor.close();
    } else {
        std::cerr << "Nepodarilo sa otvoriť súbor pre čítanie." << std::endl;
    }

    return precitanyVzor;
}

void SuborHandler::zapisDoSuboru(const std::string& parVzor, const std::string& nazovSuboru) {
    std::ofstream subor;
    subor.open(nazovSuboru,  std::ios::out | std::ios::trunc); //vytvori novy subor alebo prepise existujuci s danym nazvom

    if(subor.is_open()) {
        subor << parVzor << std::endl;
        subor.close();
    } else {
        std::cerr << "Nepodarilo sa otvoriť súbor pre zápis." << std::endl;
    }
}
