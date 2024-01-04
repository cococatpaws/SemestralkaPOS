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
    Vzor vzorDefinovanyUzivatelom(int parRiadky, int parStlpce, std::string ziveBunky); //TODO - konstruktor ked bude chciet niekto vytvorit pociatocny vzor so zadefinovanymi zivymi bunkami - string je zoznam pozicii zivych buniek vo formate 1;1 2;1...
    Vzor vzorZoSuboru(std::vector<std::vector<int>> parVzor);
    Vzor novyVzorPoSimulacnomKroku(std::string ziveBunky, std::string mrtveBunky); //TODO - vzor po kroku simulacie -> dostane string pre zive bunky a string pre mrtve bunky vo forme suradnic 2;1 3;1 atd -> podla tohto naplni vector a posle ho naspat
    std::vector<std::vector<int>> getVzor();
    int getPocetRiadkov() { return this->riadky; };
    int getPocetStlpcov() { return this->stlpce; };
    void vypisVzor();
    void vypisNulovyVzor(int parRiadky, int parStlpce);
    ~Vzor() = default;
};

#endif //SEMESTRALKAPOS_VZOR_H
