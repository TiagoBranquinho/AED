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
        case 1: readAirportsFile();
        case 2: readBaggagesFile();
        case 3: readEmployeesFile();
        case 4: readFlightsFile();
        case 5: readPassengersFile();
        case 6: readPlanesFile();
        case 7: readServicesFile();
        case 8: readTranspLocalsFile();
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
        case 1: writeAirportsFile();
        case 2: writeBaggagesFile();
        case 3: writeEmployeesFile();
        case 4: writeFlightsFile();
        case 5: writePassengersFile();
        case 6: writePlanesFile();
        case 7: writeServicesFile();
        case 8: writeTranspLocalsFile();
        default: break;
    }
}

void App::writeAirportsFile() {

}

void App::writeBaggagesFile() {

}

void App::writeEmployeesFile() {

}

void App::writeFlightsFile() {

}

void App::writePassengersFile() {

}

void App::writePlanesFile() {

}

void App::writeServicesFile() {

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
