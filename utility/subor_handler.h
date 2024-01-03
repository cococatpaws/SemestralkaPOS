//
// Created by kamik on 3. 1. 2024.
//

#ifndef SEMESTRALKAPOS_SUBOR_H
#define SEMESTRALKAPOS_SUBOR_H

#include <string>
#include <fstream>
#include <iostream>


class SuborHandler {
private:
    std::string vzor;
public:
    SuborHandler();
    void zapisDoSuboru(const std::string& parVzor, const std::string& nazovSuboru);
    std::string precitajZoSuboru(const std::string& nazovSuboru);
    ~SuborHandler() = default;
};

#endif //SEMESTRALKAPOS_SUBOR_H
