//
// Created by kamik on 4. 1. 2024.
//

#include "hra.h"

Hra::Hra() {
    std::string pouzivatelskyVstup;
    Vzor vzor;
    SuborHandler suborHandler;
    Konvertor konvertor;
    bool uspesneNacitane = false;

    while(!uspesneNacitane) {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Co by si chcel spravit: " << std::endl;
        std::cout << "1 - Vytvorit novu nahodnu hru" << std::endl;
        std::cout << "2 - Vytvorit novu hru so zadanymi zivymi bunkami" << std::endl;
        std::cout << "3 - Nacitat svet z lokalneho suboru" << std::endl;
        std::cout << "4 - Stiahnut si vzor zo serveru" << std::endl;
        std::cout << "koniec - ukoncit hru" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Pre uskutocnenie vyberu zadaj jednu z hodnotu uvedenu pred pomlckou: ";

        std::getline(std::cin, pouzivatelskyVstup);
        std::cout << "" << std::endl;
        if (pouzivatelskyVstup == "1" || pouzivatelskyVstup == "2") {
            std::string pocetRiadkov;
            std::string pocetStlpcov;

            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Definovanie velkosti hracej plochy" << std::endl;
            std::cout <<  "Zadaj pocet riadkov: " ;
            std::getline(std::cin, pocetRiadkov);
            std::cout <<  "Zadaj pocet stlpcov: " ;
            std::getline(std::cin, pocetStlpcov);

            int pocetRiadkovInt = std::stoi(pocetRiadkov);
            int pocetStlpcovInt = std::stoi(pocetStlpcov);

            if (pouzivatelskyVstup == "1") {
                if (pocetRiadkovInt > 0 && pocetStlpcovInt > 0) {
                    vzor = vzor.nahodnyVzor(pocetRiadkovInt, pocetStlpcovInt);
                    uspesneNacitane = true;
                } else {
                    std::cout << "Počet riadkov/počet stĺpcov musí byť väčší ako 0!!!!" << std::endl;
                }
            } else {
                if (pocetRiadkovInt > 0 && pocetStlpcovInt > 0) {
                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "Definovanie zivych buniek" << std::endl;
                std::cout << "Tvoja hracia plocha:" << std::endl;
                //vypisanie hracej plochy so samymi nulami
                vzor.vypisNulovyVzor(pocetRiadkovInt, pocetStlpcovInt);

                std::cout << "Zive bunky zadaj ako suradnice riadok;stlpec -> napr. 1;2 2;3 1;4" << std::endl;
                std::cout << "Vstup: ";
                std::string ziveBunky;
                std::getline(std::cin, ziveBunky);
                std::cout << "" << std::endl;
                vzor.vzorDefinovanyUzivatelom(pocetRiadkovInt, pocetStlpcovInt, ziveBunky);
                uspesneNacitane = true;
                } else {
                    std::cout << "Počet riadkov/počet stĺpcov musí byť väčší ako 0!!!!" << std::flush;
                }
            }

        } else if (pouzivatelskyVstup == "3") {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Zadaj nazov lokalneho suboru vo formate nazov.txt" << std::endl;
            std::string nazovSuboru;
            std::getline(std::cin, nazovSuboru);

            std::string vzorString = suborHandler.precitajZoSuboru(nazovSuboru);

            if (vzorString != "") {
                vzor.vzorZoSuboru(konvertor.stringNaVector(vzorString));
                uspesneNacitane = true;
            }
        } else if (pouzivatelskyVstup == "4") {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Vzor zo serveru - to be implemented" << std::endl;
            //TODO - vzor zo serveru
        }
    }

    this->vzory.push_back(vzor);

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Pociatocny stav hry: "<< std::endl ;
    this->vypisAktualnyVzor();
}

void Hra::vypisAktualnyVzor() {
    this->vzory.back().vypisVzor();
}

void Hra::hraj() {
    std::string input = "";

    while (input != "koniec") {
        this->vytvorNovyVzor();
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Plocha po simulacnom kroku: "<< std::endl ;
        this->vypisAktualnyVzor();
    }
}

void Hra::vytvorNovyVzor() {
    Vzor aktualnyVzor = this->vzory.back();
    std::vector<std::vector<int>> aktualnyVzorVector = aktualnyVzor.getVzor();
    std::string ziveBunky = "";

    for (int i = 0; i < aktualnyVzor.getPocetRiadkov(); ++i) {
        for (int j = 0; j < aktualnyVzor.getPocetStlpcov(); ++j) {
            int pocetZivychSusedov = 0;

            //tu potrebujem dalsi cyklus, ktory znova prejde riadky a stlpce vzoru ale teraz s cielom pocitat zive bunky v okoli konkretnej nasej skumanej bunky na suradniciahc i,j
            for (int k = -1; k < 2; ++k) { //od -1 po 1, pretoze sused aktualnej bunky moze mat suradnice riadku i-1, i alebo i+1 (teda -1, 0 a 1)
                for (int l = -1; l < 2; ++l) { //to iste ako riadok
                    if (k == 0 && l == 0) continue; //toto je aktualna bunka - preskocit

                    //dostanem realnu suradnicu skumaneho suseda na mojej ploche
                    int suradnicaRiadok = i+k;
                    int suradnicaStlpec = j+l;

                    if (suradnicaRiadok >= 0 && suradnicaRiadok < aktualnyVzor.getPocetRiadkov()
                        && suradnicaStlpec >= 0 && suradnicaStlpec < aktualnyVzor.getPocetStlpcov()) {
                        int hodnotaNaSuradnici = aktualnyVzorVector[suradnicaRiadok][suradnicaStlpec];

                        if (hodnotaNaSuradnici == 1) {
                            ++pocetZivychSusedov;
                        }
                    }
                }
            }

            //[i][j] == ziva bunka:
            // -> menej ako 2 zivy susedia -> bunka umiera
            // -> 2 alebo 3 zivy susedia -> bunka zije
            // -> viac ako 3 zivy susedia -> bunka umiera
            if (aktualnyVzorVector[i][j] == 1) {
                if (pocetZivychSusedov == 2 || pocetZivychSusedov == 3) {
                    ziveBunky += std::to_string(i) + ";" + std::to_string(j) + " ";
                }
            } else { //[i][j] je mrtva bunka -> ak ma presne 3 zivych -> oziva
                if (pocetZivychSusedov == 3) {
                    ziveBunky += std::to_string(i) + ";" + std::to_string(j) + " ";
                }
            }

        }
    }

    Vzor novyVzor;
    novyVzor.vzorDefinovanyUzivatelom(aktualnyVzorVector.size(), aktualnyVzorVector[0].size(), ziveBunky);
    this->vzory.push_back(novyVzor);

}
