//
// Created by kamik on 4. 1. 2024.
//

#ifndef SEMESTRALKAPOS_HRA_H
#define SEMESTRALKAPOS_HRA_H

#include "vzor.h"
#include "../utility/konvertor.h"
#include "../utility/subor_handler.h"
#include <vector>
#include <iostream>
#include <thread>
#include <Windows.h>
#include "../socket/my_socket.h"

class Hra {
private:
    std::vector<Vzor> vzory;
    SuborHandler suborHandler;
    Konvertor konvertor;
    bool simulaciaBezi;
    bool programBezi;
    bool bolaSpustena;
    bool vypisHru(int pociatocneI, int aktualneI, bool odpredu);
public:
    Hra();
    void inicializaciaHry();
    void hraj();
    void vypisAktualnyVzor();
    std::string vstupZKlavesnice(int casovyLimit); //v sekundach
    void spracujVstup(const std::string& input);
    void vypisVzorNaPozicii(int poziciaVoVektore);
    void vytvorNovyVzor();
    void vypisHruOdzadu();
    void vypisHruOdpredu();
    ~Hra() = default;
};

#endif //SEMESTRALKAPOS_HRA_H
