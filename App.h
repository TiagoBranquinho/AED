#ifndef PROJETOAEROPORTO_APP_H
#define PROJETOAEROPORTO_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class App {

private:
    vector<string> filesPath = {"airports.txt", "baggages.txt", "employees.txt",
                                "flights.txt", "passengers.txt", "planes.txt",
                                "services.txt", "transp_locals.txt"};

public:
    App();
    void start();
    void displayMenu();
    void loadData();
    void load(ifstream &file);
    void readInput();
};


#endif //PROJETOAEROPORTO_APP_H
