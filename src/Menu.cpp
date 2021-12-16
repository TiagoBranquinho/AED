#include "../include/Menu.h"
#include <iostream>

using namespace std;

int Menu::readOpt() {
    int opt;
    while (true){
        cin >> opt;
        if(!cin.fail() && cin.peek()=='\n') break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Try a number..." << endl;
    }
    return opt;
}

Menu *Menu::invalidInput() {
    cout << "Invalid input option!" << endl;
    return this;
}

Menu::~Menu() = default;

Menu::Menu() = default;

MainMenu::MainMenu(): Menu(){}

void MainMenu::display(){
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "1 - Airports management" << endl;
    cout << "2 - Planes management" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *MainMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new AirportMenu();
        case 2: return new PlaneMenu();
        case 0: return nullptr;
        default: return invalidInput();
    }
}

AirportMenu::AirportMenu(): Menu(){}

void AirportMenu::display() {
    cout << "airport menu" << endl;
}

Menu *AirportMenu::nextMenu() {
    switch (readOpt()) {
        case 0: return nullptr;
        default: return invalidInput();
    }
}

PlaneMenu::PlaneMenu(): Menu(){}

void PlaneMenu::display() {
    cout << "plane menu" << endl;
}

Menu *PlaneMenu::nextMenu() {
    switch (readOpt()) {
        case 0: return nullptr;
        default: return invalidInput();
    }
}
