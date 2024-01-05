//
// Created by kamik on 3. 1. 2024.
//
#include "vzor.h"

Vzor::Vzor() {}

Vzor Vzor::nahodnyVzor(int parRiadky, int parStlpce) {
    this->inicializuj(parRiadky, parStlpce);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(0,1);

    for (int i = 0; i < this->riadky; ++i) {
        for (int j = 0; j < this->stlpce; ++j) {
            double genCislo = distribution(gen);
            if (genCislo < 0.3) {
                this->vzor[i][j] = 1;
            } else {
                this->vzor[i][j] = 0;
            }
        }
    }

    return *this;
}

Vzor Vzor::vzorZoSuboru(std::vector<std::vector<int>> parVzor) {
    this->vzor = parVzor;
    this->riadky = parVzor.size();
    this->stlpce = parVzor[0].size();

    return *this;
}


std::vector<std::vector<int>> Vzor::getVzor() {
    return this->vzor;
}

Vzor Vzor::vzorDefinovanyUzivatelom(int parRiadky, int parStlpce, std::string ziveBunky) {
    this->inicializuj(parRiadky, parStlpce);

    for (int i = 0; i < this->riadky; ++i) {
        for (int j = 0; j < this->stlpce; ++j) {
            this->vzor[i][j] = 0;
        }
    }

    std::istringstream  suradnice(ziveBunky);
    std::string suradnica;

    while (suradnice >> suradnica) {
        int riadok = std::stoi(suradnica.substr(0,suradnica.find(';')));
        int stlpec = std::stoi(suradnica.substr(2,suradnica.find(';')));

        if (riadok > this->riadky || stlpec > this->stlpce) {
            std::cout << "Bunka so suradnicami " + suradnica + " nebude zapocitana do plochy, pretoze je mimo plochy!!" << std::endl;
            break;
        }

        for (int i = 0; i < this->riadky; ++i) {
            for (int j = 0; j < this->stlpce; ++j) {
                if ( i == riadok && j == stlpec) {
                    this->vzor[i][j] = 1;
                    break;
                }
            }
        }
    }
    return *this;
}

void Vzor::inicializuj(int parRiadky, int parStlpce) {
    this->riadky = parRiadky;
    this->stlpce = parStlpce;
    this->vzor.resize(this->riadky);

    for (int i = 0; i < this->riadky; ++i) {
        this->vzor[i].resize(this->stlpce);
    }
}

void Vzor::vypisVzor() {
    std::cout << "    ";
    for (int i = 0; i < this->stlpce; ++i) {
        std::cout << i << " " ;
    }
    std::cout << "" << std::endl;

    std::cout << "   ";
    for (int i = 0; i < this->stlpce; ++i) {
        std::cout << "__";
    }
    std::cout << "" << std::endl;

    for (int i = 0; i < this->riadky; ++i) {
        std::cout << i << " | ";
        for (int j = 0; j < this->stlpce; ++j) {
            std::cout << this->vzor[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void Vzor::vypisNulovyVzor(int parRiadky, int parStlpce) {
    std::cout << "    ";
    for (int i = 0; i < parStlpce; ++i) {
        std::cout << i << " " ;
    }
    std::cout << "" << std::endl;

    std::cout << "   ";
    for (int i = 0; i < parStlpce; ++i) {
        std::cout << "__";
    }
    std::cout << "" << std::endl;

    for (int i = 0; i < parRiadky; ++i) {
        std::cout << i << " | ";
        for (int j = 0; j < parStlpce; ++j) {
            std::cout << "0 ";
        }
        std::cout << "" << std::endl;
    }
}

