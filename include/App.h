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
                                      "flights.txt", "planes.txt", "carts.txt"};
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
    Airline &getAirline();
    vector<Airport> &getAirports();
    void addAirport(Airport airport);

    void loadData();
    void saveData();
    void readFile(int file);
    void writeFile(int file);

    void writeAirportsFile();
    void writeEmployeesFile();
    void writeFlightsFile();
    void writePlanesFile();
    void writeCartsFile();

    void readAirportsFile();
    void readEmployeesFile();
    void readFlightsFile();
    void readPlanesFile();
    void readCartsFile();
};


#endif //PROJETOAEROPORTO_APP_H
