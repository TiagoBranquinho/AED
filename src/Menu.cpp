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
        case 4: {
            cout << "Insert new airport's name" << endl;
            std::string name;
            cin >> name;
            cout << "Insert new airport's city" << endl;
            std::string city;
            cin >> city;
            app.addAirport(Airport(name, city));
            break;
        }
        case 5: {
            cout << "Insert airport's id" << endl;
            unsigned int id;
            cin >> id;
            bool done = false;
            for (Airport &airport : app.getAirports()){
                if(airport.getId() == id){
                    std::remove(app.getAirports().begin(), app.getAirports().end(), airport);
                    done = true;
                    break;
                }
            }
            if(done){

            }
            else
                cout << "There's no such plane";
            break;
        }
        case 6: return nullptr;
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
    cout << "5 - View ServicesTODO of Plane" << endl;
    cout << "6 - View ServicesDONE of Plane" << endl;
    cout << "7 - Add Plane" << endl;
    cout << "8 - Remove Plane" << endl;
    cout << "9 - View Plane's Flights by Date" << endl;
    cout << "10 - View Plane's Flights by Number" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *PlaneMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewPlanes(app);
        case 2: return new ViewPlanes(app,"on");
        case 3: return new ViewPlanes(app, "off");
        case 4: {
            cout << "Insert plane plate" << endl;
            std::string plate;
            cin >> plate;
            for(Plane plane : app.getAirline().getPlanes()){
                if(plane.getPlate() == plate){
                    cout << "Insert type of service" << endl;
                    std::string type;
                    cin >> type;
                    cout << "Insert date of service (day/month/year)" << endl;
                    unsigned int day, month, year;
                    cin >> day;
                    cin >> month;
                    cin >> year;
                    Date date (day, month, year);
                    cout << "Insert the id of the employee responsible for the service" << endl;
                    unsigned int id;
                    cin >> id;
                    Service service;
                    for (Employee &employee : app.getAirline().getEmployees()){
                        if(employee.getId() == id){
                            service = Service (type, date, &employee);
                            break;
                        }
                        else
                            cout << "There's no such employee";
                    }
                    plane.addService(service);
                    break;
                }
                else
                    cout << "There's no such plane";
            }
            break;
        }
        case 5: return new ViewServicesTODO(app);
        case 6: return new ViewServicesDONE(app);
        case 7: {
            cout << "Insert new plane's plate" << endl;
            std::string plate;
            cin >> plate;
            cout << "Insert new plane's capacity" << endl;
            unsigned int capacity;
            cin >> capacity;
            app.getAirline().addPlane(Plane(plate, capacity));
            break;
        }
        case 8: {
            cout << "Insert plane's plate" << endl;
            std::string plate;
            cin >> plate;
            bool done = false;
            for (Plane plane : app.getAirline().getPlanes()){
                if(plane.getPlate() == plate){
                    std::remove(app.getAirline().getPlanes().begin(), app.getAirline().getPlanes().end(), plane);
                    done = true;
                    break;
                }
            }
            if(done){

            }
            else
                cout << "There's no such plane";
            break;
        }
        case 9:  return new ViewPlaneFlights(app,"date");
        case 10: return new ViewPlaneFlights(app,"number");
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
        case 4: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            cout << "Insert date of flight (day/month/year)" << endl;
            unsigned int day, month, year;
            cin >> day;
            cin >> month;
            cin >> year;
            Date date (day, month, year);
            cout << "Insert the id of the airport of origin of the flight" << endl;
            unsigned int id1;
            cin >> id1;
            cout << "Insert the id of the airport of destiny of the flight" << endl;
            unsigned int id2;
            cin >> id2;
            bool originExists = false;
            bool destinyExists = false;
            for (Airport &airport : app.getAirports()){
                if(airport.getId() == id1) {
                    Airport origin = airport;
                    originExists = true;
                }
                else if(airport.getId() == id2) {
                    Airport destiny = airport;
                    destinyExists = true;
                }
            }
            if(originExists && destinyExists)
                app.getAirline().addFlight(Flight(number, date, &origin, &destiny));
            break;
        }
        case 5: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            bool done = false;
            for (Flight flight : app.getAirline().getFlights()){
                if(flight.getNumber() == number){
                    std::remove(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(), flight);
                    done = true;
                    break;
                }
            }
            if(done){

            }
            else
                cout << "There's no such flight";
            break;
        }
        case 0: return nullptr;
        default: return invalidInput();
    }
}

EmployeesMenu::EmployeesMenu(App &app): Menu(app) {
}

void EmployeesMenu::display() {
    cout << "Employee menu:" << endl;
    cout << "1 - View all Employees" << endl;
    cout << "2 - View Employees sorted by name" << endl;
    cout << "3 - View Employees sorted by id" << endl;
    cout << "4 - Add Employ" << endl;
    cout << "5 - Remove Employ" << endl;
    cout << "6 - Add Employee to Service" << endl;
    cout << "7 - Remove Employee of Service" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *EmployeesMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewEmployees(app);
        case 2: return new ViewEmployees(app,"name");
        case 3: return new ViewEmployees(app,"id");
        case 4: {
            cout << "Insert employee's name" << endl;
            std::string name;
            cin >> name;
            cout << "Insert employee's type" << endl;
            std::string type;
            cin >> type;
            app.getAirline().addEmployee(Employee(name, type));
            break;
        }
        case 5: {
            cout << "Insert employee's id" << endl;
            unsigned int id;
            cin >> id;
            bool done = false;
            for (const Employee& employee : app.getAirline().getEmployees()){
                if(employee.getId() == id){
                    std::remove(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(), employee);
                    done = true;
                    break;
                }
            }
            if(done){

            }
            else
                cout << "There's no such flight";
            break;
        }
        case 0: return nullptr;
        default: return invalidInput();
    }
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
        case 1: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            cout << "Insert passenger's name" << endl;
            string name;
            cin >> name;
            bool wantsAutomaticCheckIn = false;
            cout << "Insert passenger's baggage weight (0 if there insn't any)" << endl;
            double weight;
            cin >> weight;
            Passenger passenger;
            if(weight > 0){
                Baggage baggage(weight);
                cout << "Does the passenger want automatic check in? Insert true or false" << endl;
                cin >> wantsAutomaticCheckIn;
                passenger = Passenger(name, &baggage,wantsAutomaticCheckIn);
            }
            else
                passenger = Passenger(name, nullptr,false);
            bool done = false;
            for(Flight &flight : app.getAirline().getFlights()){
                if(flight.getNumber() == number){
                    flight.addPassenger(passenger);
                    done = true;
                }
            }
            if(!done)
                cout << "Invalid Flight Number!!" << endl;
            break;
        }
        case 2: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            cout << "Insert passenger's name" << endl;
            string name;
            cin >> name;
            bool wantsAutomaticCheckIn = false;
            cout << "Insert passenger's baggage weight (0 if there insn't any)" << endl;
            double weight;
            cin >> weight;
            Passenger passenger;
            if(weight > 0){
                Baggage baggage;
                cout << "Does the passenger want automatic check in? Insert true or false" << endl;
                cin >> wantsAutomaticCheckIn;
                passenger = Passenger(name, &baggage, wantsAutomaticCheckIn);
            }
            else
                passenger = Passenger(name, nullptr,false);
            bool done = false;
            for(Flight &flight : app.getAirline().getFlights()){
                if(flight.getNumber() == number){
                    flight.removePassenger(passenger);
                    done = true;
                }
            }
            if(!done)
                cout << "Invalid Flight Number!!" << endl;
            break;
        }
        case 0: return nullptr;
        default: return invalidInput();
    }
}

ViewAirports::ViewAirports(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {
    if (sortedBy == "name")
        sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
            return lhs.getName() < rhs.getName();
        });
    if (sortedBy == "city")
        sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
            return lhs.getCity() < rhs.getCity();
        });
    display();
}

void ViewAirports::display() {
    for(Airport &airport : app.getAirports())
        cout << airport << endl;
}

Menu *ViewAirports::nextMenu() {
    return nullptr;
}

ViewGroundLocals::ViewGroundLocals(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy){
    /*for(Airport &airport : app.getAirports()){
        sort(airport.localsBeginItr(), airport.localsEndItr(), [](const GroundTransportation &lhs, const GroundTransportation &rhs) {
            return lhs.getDistance() < rhs.getDistance();
        });
    }
    display();
     */
}
void ViewGroundLocals::display() {
    for(Airport &airport : app.getAirports()){
        airport.printLocals();
    }
}

Menu *ViewGroundLocals::nextMenu() {
    return nullptr;
}

ViewServicesTODO::ViewServicesTODO(App &app) : Menu(app) {
    display(); // nao ha ordem de ordenacao especificada no menu
}

void ViewServicesTODO::display() {
    for(const Plane &plane : app.getAirline().getPlanes()){
        auto aux = plane.getServicesToDo();
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }
        cout << endl <<  "Plane: " << plane.getPlate() << endl;
    }
}

Menu *ViewServicesTODO::nextMenu() {
    return nullptr;
}

ViewServicesDONE::ViewServicesDONE(App &app) : Menu(app) {
    display();  // nao ha ordem de ordenacao especificada no menu
}

void ViewServicesDONE::display() {
    for(const Plane &plane : app.getAirline().getPlanes()){
        for(Service &service : plane.getServicesDone()){
            cout << service;
        }
        cout << endl << "Plane: " << plane.getPlate() << endl;
    }
}

Menu *ViewServicesDONE::nextMenu() {
    return nullptr;
}

ViewPlanes::ViewPlanes(App &app, std::string duty): Menu(app), duty(duty){
    // duty?
    display();
}

void ViewPlanes::display() {
    for (Plane &plane: app.getAirline().getPlanes())
        cout << plane;
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
    if (sortedBy == "date")
        sort(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(), [](const Flight &lhs, const Flight &rhs) {
            return lhs.getDate() < rhs.getDate();
        });
    if (sortedBy == "number")
        sort(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(), [](const Flight &lhs, const Flight &rhs) {
            return lhs.getNumber() < rhs.getNumber();
        });
    display();
}

void ViewFlights::display() {
    for(Flight &flight : app.getAirline().getFlights())
        cout << flight;
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
