#ifndef PROJETOAEROPORTO_APP_H
#define PROJETOAEROPORTO_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Menu.h"

struct Filesname{
    std::string airports_file = "airports.txt";
    std::string baggages_file = "baggages.txt";
    std::string employees_file = "employees.txt";
    std::string flights_file = "flights.txt";
    std::string passengers_file = "passengers.txt";
    std::string planes_file = "planes.txt";
    std::string services_file = "services.txt";
    std::string transp_locals_file= "transp_locals.txt";
    std::vector<std::string> names = {airports_file, baggages_file, employees_file,
                                      flights_file, passengers_file, planes_file,
                                      services_file, transp_locals_file};
};

class App {

private:
    Filesname files;
    std::stack<Menu*> menuStack;

public:
    App();
    ~App();
    void start();

private:
    void displayMenu();
    void loadData();
    void saveData();
    void readFile(std::string filename);
    void writeFile(std::string filename);
};


#endif //PROJETOAEROPORTO_APP_H
