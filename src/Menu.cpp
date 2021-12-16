#include "../include/Menu.h"
#include <iostream>

using namespace std;

Menu::~Menu() = default;

Menu::Menu(App &app): app(app) {}

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

MainMenu::MainMenu(App &app): Menu(app){}

void MainMenu::display(){
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "1 - Airports management" << endl;
    cout << "2 - Planes management" << endl;
    cout << "3 - Flights management" << endl;
    cout << "4 - Employees management" << endl;
    cout << "5 - Passengers/Baggage management" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *MainMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new AirportMenu(app);
        case 2: return new PlaneMenu(app);
        case 3: return new FlightMenu(app);
        case 4: return new EmployeesMenu(app);
        case 5: return new PassengerAndBaggageMenu(app);
        case 0: return nullptr;
        default: return invalidInput();
    }
}

AirportMenu::AirportMenu(App &app): Menu(app){}

void AirportMenu::display() {
    cout << "Airport menu:" << endl;
    cout << "1 - View Airports sorted by name" << endl;
    cout << "2 - View Airports sorted by city" << endl;
    cout << "3 - View Airport Ground Locals sorted by distance" << endl;
    cout << "4 - Add Airport" << endl;
    cout << "6 - Remove Airport" << endl;
    cout << "5 - Add Ground Local to Airport" << endl;
    cout << "6 - Remove Ground Local from Airport" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *AirportMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewAirports(app, "name");
        case 2: return new ViewAirports(app, "city");
        case 3: return new ViewGroundLocals(app, "distance");
        case 4: break;
        case 5: break;
        case 6: break;
        case 0: return nullptr;
        default: return invalidInput();
    }
}

PlaneMenu::PlaneMenu(App &app): Menu(app){}

void PlaneMenu::display() {
    cout << "Plane menu:" << endl;
    cout << "1 - View all Planes" << endl;
    cout << "2 - View Planes on duty" << endl;
    cout << "3 - View Planes off duty" << endl;
    cout << "4 - Add Service to Plane" << endl;
    cout << "5 - View Service of Plane" << endl;
    cout << "6 - Add Plane" << endl;
    cout << "7 - Remove Plane" << endl;
    cout << "8 - View Plane's Flights" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *PlaneMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewPlanes(app);
        case 2: return new ViewPlanes(app,"on");
        case 3: return new ViewPlanes(app, "off");
        case 4: return nullptr;
        case 5: return new ViewServicesTODO(app);
        case 6: return nullptr;
        case 7: return nullptr;
        case 8: return new ViewPlaneFlights(app);
        case 0: return nullptr;
        default: return invalidInput();
    }
}

FlightMenu::FlightMenu(App &app): Menu(app) {
}

void FlightMenu::display() {
    cout << "Flight menu:" << endl;
    cout << "1 - View all Flights" << endl;
    cout << "2 - View Flights sorted by Date" << endl;
    cout << "3 - View Flights sorted by Id" << endl;
    cout << "4 - Add Flight" << endl;
    cout << "5 - Remove Flight" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *FlightMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewFlights(app);
        case 2: return new ViewFlights(app,"date");
        case 3: return new ViewFlights(app,"id");
        case 4: return nullptr;
        case 5: return nullptr;
        case 0: return nullptr;
        default: return invalidInput();
    }
}

EmployeesMenu::EmployeesMenu(App &app): Menu(app) {

}

void EmployeesMenu::display() {

}

Menu *EmployeesMenu::nextMenu() {
    return nullptr;
}

PassengerAndBaggageMenu::PassengerAndBaggageMenu(App &app): Menu(app) {

}

void PassengerAndBaggageMenu::display() {
    cout << "Passengers and Baggage menu:" << endl;
    cout << "1 - Add to Flight" << endl;
    cout << "2 - Remove from Flight" << endl;
    cout << "3 - ...........";  // not finished
    cout << endl;
}

Menu *PassengerAndBaggageMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return nullptr;
        case 2: return nullptr;
        case 0: return nullptr;
        default: return invalidInput();
    }
}

ViewAirports::ViewAirports(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy){

}

void ViewAirports::display() {

}

Menu *ViewAirports::nextMenu() {
    return nullptr;
}

ViewGroundLocals::ViewGroundLocals(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy){

}

void ViewGroundLocals::display() {

}

Menu *ViewGroundLocals::nextMenu() {
    return nullptr;
}

ViewServicesTODO::ViewServicesTODO(App &app) : Menu(app) {

}

void ViewServicesTODO::display() {

}

Menu *ViewServicesTODO::nextMenu() {
    return nullptr;
}

ViewServicesDONE::ViewServicesDONE(App &app) : Menu(app) {

}

void ViewServicesDONE::display() {

}

Menu *ViewServicesDONE::nextMenu() {
    return nullptr;
}

ViewPlanes::ViewPlanes(App &app, std::string duty): Menu(app), duty(duty){

}

void ViewPlanes::display() {

}

Menu *ViewPlanes::nextMenu() {
    return nullptr;
}

ViewPlaneFlights::ViewPlaneFlights(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewPlaneFlights::display() {

}

Menu *ViewPlaneFlights::nextMenu() {
    return nullptr;
}

ViewFlights::ViewFlights(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewFlights::display() {

}

Menu *ViewFlights::nextMenu() {
    return nullptr;
}

ViewFlightPassengers::ViewFlightPassengers(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewFlightPassengers::display() {

}

Menu *ViewFlightPassengers::nextMenu() {
    return nullptr;
}

ViewEmployees::ViewEmployees(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewEmployees::display() {

}

Menu *ViewEmployees::nextMenu() {
    return nullptr;
}

ViewPassengers::ViewPassengers(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewPassengers::display() {

}

Menu *ViewPassengers::nextMenu() {
    return nullptr;
}

ViewBaggages::ViewBaggages(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {

}

void ViewBaggages::display() {

}

Menu *ViewBaggages::nextMenu() {
    return nullptr;
}
