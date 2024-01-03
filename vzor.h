//
// Created by kamik on 3. 1. 2024.
//
#ifndef SEMESTRALKAPOS_VZOR_H
#define SEMESTRALKAPOS_VZOR_H
#include <string>
#include <random>
#include <iostream>


class Vzor {
private:
    //std::string vzor;
    std::vector<std::vector<int>> vzor;
    int riadky;
    int stlpce;

public:
    Vzor(int parRiadky, int parStlpce);
    Vzor(int parRiadky, int parStlpce, std::string ziveBunky); //TODO - konstruktor ked bude chciet niekto vytvorit pociatocny vzor so zadefinovanymi zivymi bunkami - string je zoznam pozicii zivych buniek vo formate 1;1 2;1...
    Vzor(std::vector<std::vector<int>> parVzor, bool jeZoSuboru);
    std::vector<std::vector<int>> getVzor();
    void vypisVzor();
    void zmenBunky(); //TODO
    ~Vzor() = default;
};

#endif //SEMESTRALKAPOS_VZOR_H
