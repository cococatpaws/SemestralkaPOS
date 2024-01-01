#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <algorithm>
#include <fstream>
#include "my_socket.h"
using namespace std;

// change row and column value to set the canvas size
const int row = 5;
const int col = 4;


struct Vzor {
    string vzor;
    static Vzor vytvor(int **vzor);
    };

Vzor Vzor::vytvor(int **vzor) {
    string txt;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
           txt+= to_string(vzor[i][j] )+ ";";
        }
    }
    Vzor v = {txt};
    return v;
}

 void generujSpetne(string txt, int ** vzor){
    txt.erase(std::remove(txt.begin(), txt.end(), ';'), txt.end());
    const char* pomocna = txt.c_str();
    int pocet = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            vzor[i][j] = pomocna[pocet] - '0';
            pocet++;
        }
    }

}

void row_line() {
    cout << endl;
    for (int i = 0; i < col; i++) {
        cout << " -----";
    }
    cout << endl;
}
void vypis(int** vzor) {
    row_line();
    for (int i = 0; i < row; i++) {
        cout << ":";
        for (int j = 0; j < col; j++) {
            cout << "  " << vzor[i][j] << "  :";
        }
        row_line();
    }
}



int main() {



    int** txt = new int*[row];
    for (int i = 0; i < row; i++) {
        txt[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            txt[i][j] = 1;
        }
    }

    Vzor vzor = Vzor::vytvor(txt);
    cout << vzor.vzor;

    generujSpetne(vzor.vzor, txt);
    vypis(txt);

    try {
        fstream inputFile("simulacia.txt", ios::out);
        inputFile << vzor.vzor << endl;
        inputFile << vzor.vzor << endl;
        inputFile.close();

    } catch(EXCEPTION_DEBUG_INFO e){
        cout << "Súbor sa nenašiel";
    }
    try {
        fstream outputFile("simulacia.txt", ios::in);
        cout << "kontrola" <<endl;
        string s;
        outputFile >> s;
        generujSpetne(s,txt);
        vypis(txt);
        outputFile.close();
    } catch(EXCEPTION_DEBUG_INFO e){
        cout << "Súbor sa nenašiel";
    }
    for (int i = 0; i < row; i++) {
        delete[] txt[i];
    }
    delete[] txt;

}
