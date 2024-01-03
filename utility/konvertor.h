//
// Created by kamik on 3. 1. 2024.
//

#ifndef SEMESTRALKAPOS_KONVERTOR_H
#define SEMESTRALKAPOS_KONVERTOR_H

#include <string>
#include <vector>
#include <iostream>

class Konvertor {
private:

public:
    Konvertor();
    std::vector<std::vector<int>> stringNaVector(std::string vzor);
    std::string vectorNaString(std::vector<std::vector<int>> vzor);
    ~Konvertor() = default;
};

#endif //SEMESTRALKAPOS_KONVERTOR_H
