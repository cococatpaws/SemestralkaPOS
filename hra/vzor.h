//
// Created by kamik on 3. 1. 2024.
//
#ifndef SEMESTRALKAPOS_VZOR_H
#define SEMESTRALKAPOS_VZOR_H
#include <string>
#include <random>
#include <iostream>
#include <sstream>


class Vzor {
private:
    //std::string vzor;
    std::vector<std::vector<int>> vzor;
    int riadky;
    int stlpce;
    void inicializuj(int parRiadky, int parStlpce);
public:
    Vzor();
    Vzor nahodnyVzor(int parRiadky, int parStlpce);
    Vzor vzorDefinovanyUzivatelom(int parRiadky, int parStlpce, std::string ziveBunky);
    Vzor vzorZoSuboru(std::vector<std::vector<int>> parVzor);
    std::vector<std::vector<int>> getVzor();
    int getPocetRiadkov();
    int getPocetStlpcov();
    void vypisVzor();
    void vypisNulovyVzor(int parRiadky, int parStlpce);
    ~Vzor() = default;
};

#endif //SEMESTRALKAPOS_VZOR_H
