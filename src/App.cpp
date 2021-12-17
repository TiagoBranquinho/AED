#include "../include/App.h"

using namespace std;

App::App() {
    loadData();
}

App::~App() {
    saveData();
}

Airline App::getAirline() const{
    return airline;
}

vector<Airport> App::getAirports() const{
    return airports;
}

void App::addAirport(Airport airport) {
    airports.push_back(airport);
}

void App::loadData() {
    for (int file = 0; file < files.names.size(); file++){
        readFile(file);
    }
}

void App::saveData() {
    for (int file = 0; file < files.names.size(); file++){
        writeFile(file);
    }
}

void App::readFile(int file) {
    switch (file) {
        case 0: readAirportsFile(); break;
        case 1: readBaggagesFile(); break;
        case 2: readEmployeesFile(); break;
        case 3: readFlightsFile(); break;
        case 4: readPassengersFile(); break;
        case 5: readPlanesFile(); break;
        case 6: readServicesFile(); break;
        case 7: readTranspLocalsFile(); break;
        default: break;
    }
}

void App::writeFile(int file) {
    switch (file) {
        case 0: writeAirportsFile();break;
        case 1: writeBaggagesFile();break;
        case 2: writeEmployeesFile();break;
        case 3: writeFlightsFile();break;
        case 4: writePassengersFile();break;
        case 5: writePlanesFile();break;
        case 6: writeServicesDoneFile();break;
        case 7: writeServicesToDoFile();break;
        case 8: writeTranspLocalsFile();break;
        default: break;
    }
}

void App::writeAirportsFile() {
    std::ofstream file(dataFolder + files.names.at(0));
    file.clear();
    if(file.is_open()){
       // for(const Airport &airport : airline.get()){
     }
}


void App::writeBaggagesFile() {

}

void App::writeEmployeesFile() {
    std::ofstream file(dataFolder + files.names.at(2));
    file.clear();
    if(file.is_open()){
        for(const auto &employee : airline.getEmployees()){
            file << employee;
        }
        file.close();
    }
}

void App::writeFlightsFile() {
    std::ofstream file(dataFolder + files.names.at(3));
    file.clear();
    if(file.is_open()){
        for(const auto &flight : airline.getFlights()){
            file << flight;
        }
        file.close();
    }
}

void App::writePassengersFile() {
    std::ofstream file(dataFolder + files.names.at(4));
    file.clear();
    if(file.is_open()){
        for(const auto &flight : airline.getFlights()){
            for(const auto &passenger: flight.getPassengers())
                file << passenger;
        }
        file.close();
    }
}

void App::writePlanesFile() {
    std::ofstream file(dataFolder + files.names.at(5));
    file.clear();
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            file << plane;
        }
    }
    file.close();
}

void App::writeServicesToDoFile() {
    std::ofstream file(dataFolder + files.names.at(6));
    file.clear();
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            while(!plane.getServicesToDo().empty()){
                file << plane.getServicesToDo().front();
                plane.getServicesToDo().pop();
            }
        }
    }
    file.close();
}

void App::writeServicesDoneFile() {
    std::ofstream file(dataFolder + files.names.at(6));
    file.clear();
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            for(const Service &service : plane.getServicesDone())
                file << service;
        }
    }
    file.close();
}

void App::writeTranspLocalsFile() {

}

void App::readAirportsFile() {

}

void App::readBaggagesFile() {

}

void App::readEmployeesFile() {

}

void App::readFlightsFile() {

}

void App::readPassengersFile() {

}

void App::readPlanesFile() {
    std::string plate;
    unsigned int capacity;
    ifstream file(dataFolder + files.names.at(5));
    while(file >> plate >> capacity){
        airline.addPlane(Plane(plate,capacity));
    }
}

void App::readServicesFile() {

}

void App::readTranspLocalsFile() {

}


