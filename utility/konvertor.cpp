//
// Created by kamik on 3. 1. 2024.
//
#include "konvertor.h"

Konvertor::Konvertor() {}

//Tato metoda sluzi pri nacitani vzoru zo suboru
std::vector<std::vector<int>> Konvertor::stringNaVector(std::string vzor) {
    std::vector<std::vector<int>> vzorVector;

    //pocitam s tym, ze string ma v sebe ulozene na zaciatku znaky cislo;cislo; -> prve cislo je pocet riadkov, druhe pocet stlpcov
    size_t prvaBodkociarka = vzor.find(';');
    size_t druhaBodkociarka = vzor.rfind(';');

    if (prvaBodkociarka != std::string::npos && druhaBodkociarka != std::string::npos) {
        char pocetRiadkovChar = vzor[prvaBodkociarka - 1];
        int pocetRiadkov = std::stoi(std::string(1, pocetRiadkovChar));
        char pocetStlpcovChar  = vzor[druhaBodkociarka - 1];
        int pocetStlpcov = std::stoi(std::string(1, pocetStlpcovChar));
        std::string substringHodnoty = vzor.substr(druhaBodkociarka + 1);

        //inicializacia vektora
        vzorVector.resize(pocetRiadkov);
        for (int i = 0; i < pocetRiadkov; ++i) {
            vzorVector[i].resize(pocetStlpcov);
        }

        //naplnenie vektora
        int pozicia = 0;

        for (int i = 0; i < pocetRiadkov; ++i) {
            for (int j = 0; j < pocetStlpcov; ++j) {
                vzorVector[i][j] = substringHodnoty[pozicia] - '0'; //-0 mi z nejakeho zahadneho dovodu konvertuje string na int
                ++pozicia;
            }
        }
    } else {
        //Mozno to prerobim, a bude sa vyhadzovat vynimka, ktora sa v maine zachyti
        std::cerr << "Nepodarilo sa načítať vzor!! Neplatne zadaný počet riadkov alebo stĺpcov" << std::endl;
    }

    return vzorVector;

};

std::string Konvertor::vectorNaString(std::vector<std::vector<int>> vzor) {
    //Zapisanie rozmerov plochy
    std::string vzorString = std::to_string(vzor.size()) + ";" + std::to_string(vzor[0].size()) + ";";

    //Zapisovanie hodnot
    for (int i = 0; i < vzor.size(); ++i) {
        for (int j = 0; j < vzor[0].size(); ++j) {
            vzorString += std::to_string(vzor[i][j]);
        }
    }

    return vzorString;
}
