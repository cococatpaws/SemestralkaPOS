//
// Created by kamik on 4. 1. 2024.
//

#include "hra.h"

Hra::Hra() : suborHandler(), konvertor(), simulaciaBezi(false), programBezi(true), bolaSpustena(false) {
    this->inicializaciaHry();
}

void Hra::inicializaciaHry() {
    std::string pouzivatelskyVstup;
    Vzor vzor;
    bool uspesneNacitane = false;

    while(!uspesneNacitane) {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Co by si chcel spravit: " << std::endl;
        std::cout << "1 - Vytvorit novu nahodnu hru" << std::endl;
        std::cout << "2 - Vytvorit novu hru so zadanymi zivymi bunkami" << std::endl;
        std::cout << "3 - Nacitat svet z lokalneho suboru" << std::endl;
        std::cout << "4 - Stiahnut si vzor zo serveru" << std::endl;
        std::cout << "Q - ukoncit program" << std::endl;
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

            std::string vzorString = this->suborHandler.precitajZoSuboru(nazovSuboru);

            if (vzorString != "") {
                vzor.vzorZoSuboru(this->konvertor.stringNaVector(vzorString));
                uspesneNacitane = true;
            }
        } else if (pouzivatelskyVstup == "4") {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Vzor zo serveru - to be implemented" << std::endl;
            //TODO - vzor zo serveru
        } else if (pouzivatelskyVstup == "E" || pouzivatelskyVstup =="e") {
            this->programBezi = false;
        }
    }

    this->vzory.push_back(vzor);
}

void Hra::vypisAktualnyVzor() {
    this->vzory.back().vypisVzor();
}

void Hra::hraj() {
    while(programBezi) {
        if (!simulaciaBezi && !bolaSpustena) {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Simulacia je pozastavena! Chces ju spustit?" << std::endl;
            std::cout << "(Simulaciu mozes v akomkolvek okamziku zastavit pomocou tlacidla 'P¨). Pre spustenie simulacie stlac tlacidlo 'G':  ";

            std::string vstup;
            std::getline(std::cin, vstup);
            if (vstup == "g") {
                simulaciaBezi = true;
                bolaSpustena = true;

                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "Pociatocny stav hry: "<< std::endl ;
                this->vypisAktualnyVzor();
            }
        }

        if (!simulaciaBezi && bolaSpustena) {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Simulacia bola pozastavena! Co chces spravit?" << std::endl;
            std::cout << "D - ulozit aktualny vzor na server" << std::endl;
            std::cout << "S - ulozit vzor do lokalneho suboru" << std::endl;
            std::cout << "R - vypisat vykonanu simulaciu spatne" << std::endl;
            std::cout << "F - vypisat vykonanu simulaciu dopredne" << std::endl;
            std::cout << "G - pokracovat vo vykonavani simulacie" << std::endl;
            std::cout << "N - vztvorit novu simulaciu" << std::endl;
            std::cout << "Q - ukoncit program" << std::endl;
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Pre vykonanie vyberu stlac jedno z hore uvedenych pismen na klavesnici: " << std::endl;
            std::string vstup;
            std::getline(std::cin, vstup);
            this->spracujVstup(vstup);
        }

        while (simulaciaBezi) {
            this->vytvorNovyVzor();
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "Plocha po simulacnom kroku: "<< std::endl ;
            this->vypisAktualnyVzor();
            std::cout << "-------------------------------------------" << std::endl;

            std::string vstupZKlavesniceString = this->vstupZKlavesnice(3);
            if (vstupZKlavesniceString != "") {
                this->spracujVstup(vstupZKlavesniceString);
            }
        }
    }
}

std::string Hra::vstupZKlavesnice(int casovyLimit) {
    auto start = std::chrono::steady_clock::now();
    auto prejdeneSekundy = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count();

    while (prejdeneSekundy <= casovyLimit) {
        if (GetAsyncKeyState('P') & 0x8000) {
            //While kvoli tomu, ze ak program nepocka, kym klavesa nie je stlacena pred returnom hodnoty "p", tak sa "p" zobrazi v konzole - neziadanie
            while (GetAsyncKeyState('P') & 0x8000) {

            }
            return "p";
        }
        prejdeneSekundy = std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::steady_clock::now() - start).count();
    }
    return "";
}

void Hra::spracujVstup(const std::string& input) {
    if (input == "s") {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Pod akym nazvom chces ulozit subor: ";
        std::string nazov;
        std::getline(std::cin, nazov);

        std::vector<std::vector<int>> aktualnyVzor = this->vzory.front().getVzor();
        std::string aktualnyVzorString = this->konvertor.vectorNaString(aktualnyVzor);
        this->suborHandler.zapisDoSuboru(aktualnyVzorString, nazov);
    } else if (input == "r") {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "VYPISUJEM SIMULACIU SPATNE" << std::endl;
        std::cout << "Konecna plocha: " << std::endl;
        this->vypisHruOdzadu();
    } else if (input == "f") {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "VYPISUJEM SIMULACIU DOPREDNE" << std::endl;
        std::cout << "Pociatocna plocha: " << std::endl;
        this->vypisHruOdpredu();
    }  else if (input == "q") {
        this->programBezi = false;
    } else if (input == "g") {
        this->simulaciaBezi = true;
    } else if (input == "p") {
        this->simulaciaBezi = false;
    } else if (input == "n") {
        this->vzory.clear();
        this->bolaSpustena = false;
        this->simulaciaBezi = false;
        this->inicializaciaHry();
    } else if (input == "d") {
        //TODO - ulozenie na server
    }
}

void Hra::vytvorNovyVzor() {
    Vzor aktualnyVzor = this->vzory.back();
    std::vector<std::vector<int>> aktualnyVzorVector = aktualnyVzor.getVzor();
    std::string ziveBunky = "";

    for (int i = 0; i < aktualnyVzor.getPocetRiadkov(); ++i) {
        for (int j = 0; j < aktualnyVzor.getPocetStlpcov(); ++j) {
            int pocetZivychSusedov = 0;

            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    if (k == 0 && l == 0) continue;

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

            if (aktualnyVzorVector[i][j] == 1) {
                if (pocetZivychSusedov == 2 || pocetZivychSusedov == 3) {
                    ziveBunky += std::to_string(i) + ";" + std::to_string(j) + " ";
                }
            } else {
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

bool Hra::vypisHru(int pociatocneI, int aktualneI, bool odpredu) {
    std::cout << "-------------------------------------------" << std::endl;
    if (odpredu && aktualneI != pociatocneI) {
        std::cout << "Plocha v nasledujucom stave: " << std::endl;
    } else if (!odpredu && aktualneI != pociatocneI) {
        std::cout << "Plocha v predoslom stave: " << std::endl;
    }
    this->vypisVzorNaPozicii(aktualneI);

    std::string vstupZKlavesniceString = this->vstupZKlavesnice(3);
    if (vstupZKlavesniceString != "") {
        std::cout << "Vstup z klavesnice: " << vstupZKlavesniceString << std::endl;
        this->spracujVstup(vstupZKlavesniceString);
        return true;
    } else {
        return false;
    }

}


void Hra::vypisHruOdzadu() {
    for (int i = this->vzory.size() - 1 ; i >= 0; --i) {
        bool zastavenie = this->vypisHru(this->vzory.size() - 1, i, false);
        if (zastavenie) {
        break;
        }
    }
}

void Hra::vypisHruOdpredu() {
    for (int i = 0 ; i < this->vzory.size(); ++i) {
        bool zastavenie = this->vypisHru(0, i, true);
        if (zastavenie) {
            break;
        }
    }
}

void Hra::vypisVzorNaPozicii(int poziciaVoVektore) {
    this->vzory[poziciaVoVektore].vypisVzor();
}
