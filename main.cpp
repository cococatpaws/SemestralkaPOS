#include "utility/heap_monitor.h"
#include "my_socket.h"
#include "utility/konvertor.h"
#include "vzor.h"
#include "utility/subor_handler.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;


int main() {
    initHeapMonitor();

    /*Vzor vzor(7,3);
    vzor.vypisVzor();

    Konvertor konvertor;
    std::string test = "3;4;001101000110";

    std::vector<std::vector<int>> skusobnyVzor = konvertor.stringNaVector(test);

    std::cout << "Vypisovanie prekonvertovaneho stringu: " << std::endl;

    Vzor vzorZoStringu(skusobnyVzor, true);

    vzorZoStringu.vypisVzor();

    std::string stringSpatne = konvertor.vectorNaString(vzorZoStringu.getVzor());

    std::cout << "Stringovy vzor spatne: " << stringSpatne << std::endl;


    SuborHandler suborHandler;
    const string vzorNaZapis = konvertor.vectorNaString(vzor.getVzor());
    suborHandler.zapisDoSuboru(vzorNaZapis, "test.txt");

    string precitanyVzorString = suborHandler.precitajZoSuboru("test.txt");
    if (precitanyVzorString != "") {
        std::cout << "Precitany string zo suboru: " << precitanyVzorString << std::endl;
    }*/


}
