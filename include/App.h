#ifndef PROJETOAEROPORTO_APP_H
#define PROJETOAEROPORTO_APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Airline.h"

class App {

public:
    std::string dataFolder = "../data/";
    Airline airline;
    vector<Airport> airports;
    std::vector<std::string> filesname = {"airports.txt", "employees.txt",
                                      "flights.txt", "planes.txt", "carts.txt"};

public:
    /**
     * Default class constructor
     */
    App();
    /**
     * Default class destructor
     */
    ~App();
    Airline &getAirline();
    vector<Airport> &getAirports();
    /**
     * Adds airport argument to airports vector
     * @param airport airport object passed by reference
     */
    void addAirport(const Airport& airport);
    /**
     * Loads all storage files data into the program
     */
    void loadData();
    /**
     * Saves all the program data into to the storage files
     */
    void saveData();
    /**
     * Check which file the argument index matches and call the method to read it
     * @param file index of the file in the filesname vector
     */
    void readFile(int file);
    /**
     * Check which file the argument index matches and call the method to write it
     * @param file index of the file in the filesname vector
     */
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
    /**
     * Reads a flight of the argument file ifstream
     * @param file ifstream passed by reference of the opened file where the flight is written
     * @return flight object that was read
     */
    Flight readaFlight(ifstream &file);
    /**
     * Writes a flight to the argument file ofstream
     * @param file ofstream passed by reference of the opened file where the flight argument needs to be written
     * @param flight flight object passed by reference
     */
    void writeaFlight(ofstream &file, Flight &flight);
    /**
     * Takes a line from the file argument and converts it to an integer that is written to the num argument
     * @param file ifstream passed by reference of the opened file to be read
     * @param num num integer passed by reference
     */
    void getlineint(ifstream &file, int &num);
};


#endif //PROJETOAEROPORTO_APP_H
