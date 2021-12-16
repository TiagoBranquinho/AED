#include "../include/App.h"

#include <utility>
#include <algorithm>

using namespace std;

App::App() {
    loadData();
    menuStack.push(new MainMenu());
}

App::~App() {
    saveData();
}

void App::start() {
    while (!menuStack.empty()) {
        menuStack.top()->display();
        Menu *nextMenu = menuStack.top()->nextMenu();
        if (nextMenu){
            if (nextMenu != menuStack.top()){
                menuStack.push(nextMenu);
            }
        }
        else {
            delete menuStack.top();
            menuStack.pop();
        }
    }
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
        case 1: readAirportsFile();break;
        case 2: readBaggagesFile();break;
        case 3: readEmployeesFile();break;
        case 4: readFlightsFile();break;
        case 5: readPassengersFile();break;
        case 6: readPlanesFile();break;
        case 7: readServicesFile();break;
        case 8: readTranspLocalsFile();break;
        default: break;
    }
    /*string line;
    fstream f(files.names.at(file));
    while (getline(f,line)){
        cout << line << endl;
    }*/
}

void App::writeFile(int file) {
    switch (file) {
        case 1: writeAirportsFile();break;
        case 2: writeBaggagesFile();break;
        case 3: writeEmployeesFile();break;
        case 4: writeFlightsFile();break;
        case 5: writePassengersFile();break;
        case 6: writePlanesFile();break;
        case 7: writeServicesDoneFile();break;
        case 8: writeServicesToDoFile();break;
        case 9: writeTranspLocalsFile();break;
        default: break;
    }
}

void App::writeAirportsFile() {
    std::ofstream file(files.names.at(0), ofstream::trunc);
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
    std::ofstream file(files.names.at(6), ofstream::trunc);
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
    std::ofstream file(files.names.at(6), ofstream::trunc);
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

}

void App::readServicesFile() {

}

void App::readTranspLocalsFile() {

}
