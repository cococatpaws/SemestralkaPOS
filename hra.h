//
// Created by kamik on 4. 1. 2024.
//

#ifndef SEMESTRALKAPOS_HRA_H
#define SEMESTRALKAPOS_HRA_H

#include "vzor.h"
#include "utility/konvertor.h"
#include "utility/subor_handler.h"
#include <vector>

class Hra {
private:
    std::vector<Vzor> vzory;
public:
    Hra();
    void vypisAktualnyVzor();
    void vypisVzorNaPozicii(int poziciaVoVektore);
    void vytvorNovyVzor(); //vytvori vzor zivych a mrtvych buniek a posle to ako stringy do metody v triede Vzor -> ta vrati novy vzor a hra si ho prida do vectoru
    void vypisHruOdzadu(); //tieto metody odpredu odzadu mozno pojdu do jednej a dostanu to ako parameter
    void vypisHruOdpredu();
    void hraj(); //cely priebeh hry ?
    ~Hra() = default;
};

#endif //SEMESTRALKAPOS_HRA_H
