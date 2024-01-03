//
// Created by kamik on 3. 1. 2024.
//
#include "vzor.h"

Vzor::Vzor(int parRiadky, int parStlpce) : riadky(parRiadky), stlpce(parStlpce) {
    //inicializacia vzoru
    this->vzor.resize(this->riadky);

    for (int i = 0; i < this->riadky; ++i) {
        this->vzor[i].resize(this->stlpce);
    }

    //random generatory maybe ako atribut triedy -> reusovanie
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(0,1);

    for (int i = 0; i < this->riadky; ++i) {
        for (int j = 0; j < this->stlpce; ++j) {
            double genCislo = distribution(gen);
            if (genCislo < 0.2) {
                this->vzor[i][j] = 1;
            } else {
                this->vzor[i][j] = 0;
            }
        }
    }
}

//konstruktor na novy vzor
// jeZoSuboru: false -> parVzor je stary vzor (z predosleho kroku simulacie) vytvora sa zive/mrtve bunky z existujuceho vektora do noveho vzoru, ktory sa potom da do listu vzorov v triede Hra
// jeZoSuboru: true -> parVzor je zo suboru a iba sa skopci do atributu vzor
Vzor::Vzor(std::vector<std::vector<int>> parVzor, bool jeZoSuboru) {
    if (jeZoSuboru) {
        this->vzor = parVzor;
        this->riadky = parVzor.size();
        this->stlpce = parVzor[0].size();
    } else {
        //TODO - dorobit druhu cast konstruktora
    }
}

std::vector<std::vector<int>> Vzor::getVzor() {
    return this->vzor;
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
