#ifndef PROJETOAEROPORTO_APP_H
#define PROJETOAEROPORTO_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Airline.h"

struct Filesname{
    std::vector<std::string> names = {"airports.txt", "employees.txt",
                                      "flights.txt", "planes.txt"};
};

class App {

public:
    std::string dataFolder = "../data/";
    Filesname files;
    Airline airline;
    vector<Airport> airports;

public:
    App();
    ~App();
    void start();
    Airline &getAirline();
    vector<Airport> &getAirports();
    void addAirport(Airport airport);

public:
    void displayMenu();
    void loadData();
    void saveData();
    void readFile(int file);
    void writeFile(int file);

    void writeAirportsFile();
    void writeEmployeesFile();
    void writeFlightsFile();
    void writePlanesFile();

    void readAirportsFile();
    void readEmployeesFile();
    void readFlightsFile();
    void readPlanesFile();
};


#endif //PROJETOAEROPORTO_APP_H
