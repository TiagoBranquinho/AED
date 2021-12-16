#ifndef PROJETOAEROPORTO_APP_H
#define PROJETOAEROPORTO_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Menu.h"
#include "Airline.h"

struct Filesname{
    std::vector<std::string> names = {"airports.txt", "baggages.txt", "employees.txt",
                                      "flights.txt", "passengers.txt", "planes.txt",
                                      "services.txt", "transp_locals.txt"};
};

class App {

private:
    std::string dataFolder = "../data/";
    Filesname files;
    std::stack<Menu*> menuStack;
    Airline airline;

public:
    App();
    ~App();
    void start();

private:
    void displayMenu();
    void loadData();
    void saveData();
    void readFile(int file);
    void writeFile(int file);

    void writeAirportsFile();
    void writeBaggagesFile();
    void writeEmployeesFile();
    void writeFlightsFile();
    void writePassengersFile();
    void writePlanesFile();
    void writeServicesFile();
    void writeTranspLocalsFile();

    void readAirportsFile();
    void readBaggagesFile();
    void readEmployeesFile();
    void readFlightsFile();
    void readPassengersFile();
    void readPlanesFile();
    void readServicesFile();
    void readTranspLocalsFile();
};


#endif //PROJETOAEROPORTO_APP_H
