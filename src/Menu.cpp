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
    cout << "5 - Remove Airport" << endl;
    cout << "6 - Add Ground Local to Airport" << endl;
    cout << "7 - Remove Ground Local from Airport" << endl;
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
            cin.ignore(1000,'\n');
            getline(cin,name,'\n');
            cout << "Insert new airport's city" << endl;
            std::string city;
            getline(cin,city,'\n');
            app.addAirport(Airport(name, city));
            return this;
        }
        case 5: {
            cout << "Insert airport's id" << endl;
            unsigned int id;
            cin >> id;
            auto it = std::find_if(app.getAirports().begin(), app.getAirports().end(), [&id](const auto &airport){return airport.getId() == id;});
            if(it != app.getAirports().end())
                app.getAirports().erase(it);
            else
                cout << "There's no such plane";
            return this;
       }
        case 6: {
            cout << "Insert airport's id" << endl;
            unsigned int id;
            cin >> id;
            cout << "Insert local's transportations service type" << endl;
            std::string type;
            cin >> type;
            cout << "Insert local's distance to airport" << endl;
            unsigned int distance;
            cin >> distance;
            bool done = false;
            for(Airport airport : app.getAirports()){
                if(airport.getId() == id){
                    airport.addGroundTransportation(GroundTransportation(type, distance));
                    done = true;
                }
            }
            if(!done){
                cout << "There's no such airport" << endl;
            }
            return this;
        }
        case 7: {
            cout << "Insert airport's id" << endl;
            unsigned int id1;
            cin >> id1;
            cout << "Insert local's id" << endl;
            unsigned int id2;
            cin >> id2;
            bool done = false;
            for(Airport airport : app.getAirports()){
                if(airport.getId() == id1){
                    for(auto it = airport.getLocals().beginItr(); it != airport.getLocals().endItr(); it++) {
                        if((*it).getId() == id2){
                            airport.getLocals().removeGroundTransportation((*it));
                            done = true;
                            break;
                        }
                    }
                    if(!done)
                        cout << "There's no such local" << endl;
                    break;
                }
                cout << "There's no such airport" << endl;
            }
            return this;
        }
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
    cout << "6 - View ServicesDONE of Plane by Date" << endl;
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
            return this;
        }
        case 5: return new ViewServicesTODO(app);
        case 6: return new ViewServicesDONE(app, "date");
        case 7: {
            cout << "Insert new plane's plate" << endl;
            std::string plate;
            cin >> plate;
            cout << "Insert new plane's capacity" << endl;
            unsigned int capacity;
            cin >> capacity;
            app.getAirline().addPlane(Plane(plate, capacity));
            return this;
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
            return this;
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
    cout << "4 - View Flight's Passengers by Id" << endl;
    cout << "5 - View Flight's Passengers by Name" << endl;
    cout << "6 - Add Flight" << endl;
    cout << "7 - Remove Flight" << endl;
    cout << "8 - Start flight" << endl;
    cout << "9 - End flight" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *FlightMenu::nextMenu() {
    switch (readOpt()) {
        case 1: return new ViewFlights(app);
        case 2: return new ViewFlights(app,"date");
        case 3: return new ViewFlights(app,"id");
        case 4: return new ViewFlightPassengers(app,"id");
        case 5: return new ViewFlightPassengers(app,"name");
        case 6: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            cout << "Insert date of flight (year/month/day)" << endl;
            string dt;
            cin >> dt;
            Date date (dt);
            cout << "Insert the airport of origin of the flight" << endl;
            std::string name1;
            cin >> name1;
            cout << "Insert the airport of destiny of the flight" << endl;
            std::string name2;
            cin >> name2;
            auto origin = find_if(app.getAirports().begin(), app.getAirports().end(),
                                  [&name1](const Airport &air){return air.getName()==name1;});
            auto destiny = find_if(app.getAirports().begin(), app.getAirports().end(),
                                   [&name2](const Airport &air){return air.getName()==name2;});
            if (origin != app.getAirports().end() && destiny != app.getAirports().end()){
                auto *f = new Flight(number, &date, origin.base(), destiny.base());
                cout << "Select a plane to realize this flight" << endl;
                ViewPlanes vp(app);
                vp.display();
                string plate;
                cin >> plate;
                auto plane = find_if(app.getAirline().getPlanes().begin(), app.getAirline().getPlanes().end(),[&plate](Plane &p){return p.getPlate()==plate;});
                (*plane).addFlight(*f);
                app.getAirline().addFlight(f);
                cout << "Flight added successfully." << endl;
            }
            else {
                cout << "Invalid airport names!" << endl;
            }
            return this;
        }
        case 7: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            auto flight = find_if(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(),[&number](Flight &f){return f.getNumber() == number;});
            if (flight != app.getAirline().getFlights().end()){
                app.getAirline().getFlights().erase(flight);
                cout << "Flight removed successfully." << endl;
            }
            else
                cout << "There's no such flight";
            return this;
        }
        case 8: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            bool done = false;
            for(Plane &plane : app.getAirline().getPlanes()){
                for (Flight &flight : plane.getFlightPlan()){
                    if(flight.getNumber() == number) {
                        flight.openCheckIn();
                        app.getAirline().checkInPassengers(flight);
                        plane.setOnDuty(true);
                        done = true;
                        break;
                    }
                }
                if(done){
                    break;
                }
            }
            if(done)
                cout << "Flight started successfully" << endl;
            else
                cout << "There's no such flight" << endl;
        }
        case 9: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            bool done = false;
            for(Plane &plane : app.getAirline().getPlanes()) {
                for (Flight &flight: plane.getFlightPlan()) {
                    if (flight.getNumber() == number && flight.getCheckInStatus()) {
                        flight.closeCheckIn();
                        std::remove_if(plane.getFlightPlan().begin(), plane.getFlightPlan().end(),
                                       [&number](Flight &flight) { return number == flight.getNumber(); });
                        std::remove_if(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(),
                                       [&number](Flight &flight) { return number == flight.getNumber(); });
                        plane.setOnDuty(false);
                        done = true;
                        break;
                    }
                }
                if(done)
                    break;
            }
            if(done)
                cout << "Flight ended successfully" << endl;
            else
                cout << "There's no such flight occurring" << endl;
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
            return this;
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
                cout << "There's no such employee";
            return this;
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
            cout << "Insert passenger's baggage weight (0 if there isn't any)" << endl;
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
            for(Flight &flight : app.getAirline().getFlights()){
                if(flight.getNumber() == number) {
                    app.getAirline().addPassengerToFlight(flight, passenger);
                    break;
                }
            }
            return this;
        }
        case 2: {
            cout << "Insert flight's number" << endl;
            unsigned int number;
            cin >> number;
            cout << "Insert passenger's id" << endl;
            unsigned int id;
            cin >> id;
            bool done = false;
            for (Flight &flight: app.getAirline().getFlights()) {
                if (flight.getNumber() == number) {
                    for (Passenger &passenger: flight.getPassengers()) {
                        if (passenger.getId() == id) {
                            std::remove(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(), passenger);
                            done = true;
                            break;
                        }
                    }
                    if (done) {

                    } else
                        cout << "There's no such flight";
                    break;
                }
            }
            if(!done)
                cout << "Invalid Flight Number!!" << endl;
            return this;
        }
        case 0: return nullptr;
        default: return invalidInput();
    }
}

ViewAirports::ViewAirports(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {;
    if (sortedBy == "name")
        sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
            return lhs.getName() < rhs.getName();
        });
    if (sortedBy == "city")
        sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
            return lhs.getCity() < rhs.getCity();
        });
}

void ViewAirports::display() {
    for(Airport &airport : app.getAirports())
        cout << airport;
    cout << endl;
}

Menu *ViewAirports::nextMenu() {
    return nullptr;
}

ViewGroundLocals::ViewGroundLocals(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy){
    /*for(Airport &airport : app.getAirports()){
        sort(airport.localsBeginItr(), airport.localsEndItr(), [](const GroundTransportation &lhs, const GroundTransportation &rhs) {
            return lhs.getDistance() < rhs.getDistance();
        });
    }*/
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
    cout << "Insert plane's plate" << endl;
    std::string plate;
    cin >> plate;
    this->plate = plate;
}

void ViewServicesTODO::display() {
    for(const Plane &plane : app.getAirline().getPlanes()){
        if(plane.getPlate() == plate){
            auto aux = plane.getServicesToDo();
            while(!aux.empty()){
                cout << aux.front();
                aux.pop();
            }
        }
    }
}

Menu *ViewServicesTODO::nextMenu() {
    return nullptr;
}

ViewServicesDONE::ViewServicesDONE(App &app, std::string sortedBy) : Menu(app),sortedBy(sortedBy) {
    cout << "Insert plane's plate" << endl;
    cin >> plate;
    for(const Plane &plane : app.getAirline().getPlanes()){
        if(plane.getPlate() == plate){
            if(sortedBy == "date")
                sort(plane.getServicesDone().begin(), plane.getServicesDone().end(), [](const Service &lhs, const Service &rhs) {
                    return lhs.getDate() < rhs.getDate();
                });
        }
    }
}

void ViewServicesDONE::display() {
    for (const Plane &plane: app.getAirline().getPlanes())
        if (plane.getPlate() == plate)
            for (Service &service: plane.getServicesDone())
                cout << service;
}

Menu *ViewServicesDONE::nextMenu() {
    return nullptr;
}

ViewPlanes::ViewPlanes(App &app, std::string duty): Menu(app), duty(duty){
    // duty?

}

void ViewPlanes::display() {
    for (Plane &plane: app.getAirline().getPlanes())
        cout << plane;
}

Menu *ViewPlanes::nextMenu() {
    return nullptr;
}

ViewPlaneFlights::ViewPlaneFlights(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {
    cout << "Insert plane's plate" << endl;
    cin >> plate;
    for(const Plane &plane : app.getAirline().getPlanes()){
        if(plane.getPlate() == plate){
            for(const Flight &flight : plane.getFlightPlan())
                aux_vector.push_back(flight);
            if (sortedBy == "number")
                sort(aux_vector.begin(), aux_vector.end(), [](const Flight &lhs, const Flight &rhs) {
                    return lhs.getNumber() < rhs.getNumber();
                });
            if (sortedBy == "date")
                sort(aux_vector.begin(), aux_vector.end(), [](Flight &lhs, Flight &rhs) {
                    return lhs.getDate() < rhs.getDate();
                });
        }
    }
}

void ViewPlaneFlights::display() {
    for(const Flight &flight : aux_vector)
        cout << flight;
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
}

void ViewFlights::display() {
    for(Flight &flight : app.getAirline().getFlights())
        cout << flight;
}

Menu *ViewFlights::nextMenu() {
    return nullptr;
}

ViewFlightPassengers::ViewFlightPassengers(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {
    cout << "Insert flight's number" << endl;
    cin >> number;
    for (const Flight &flight: app.getAirline().getFlights()) {
        if (flight.getNumber() == number) {
            if (sortedBy == "id") {
                for (const Passenger &p: flight.getPassengers())
                    aux_vector.push_back(p);
                sort(aux_vector.begin(), aux_vector.end(), [](const Passenger &lhs, const Passenger &rhs) {
                    return lhs.getId() < rhs.getId();
                });
            }
            if (sortedBy == "name") {
                for (const Passenger &p: flight.getPassengers())
                    aux_vector.push_back(p);
                sort(aux_vector.begin(), aux_vector.end(), [](const Passenger &lhs, const Passenger &rhs) {
                    return lhs.getName() < rhs.getName();
                });
            }
        }
    }
}

void ViewFlightPassengers::display() {
    for(const Passenger &passenger : aux_vector)
        cout << passenger;
}

Menu *ViewFlightPassengers::nextMenu() {
    return nullptr;
}

ViewEmployees::ViewEmployees(App &app, std::string sortedBy): Menu(app), sortedBy(sortedBy) {
    if (sortedBy == "id")
        sort(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(), [](const Employee &lhs, const Employee &rhs) {
            return lhs.getId() < rhs.getId();
        });
    if (sortedBy == "name")
        sort(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(), [](const Employee &lhs, const Employee &rhs) {
            return lhs.getName() < rhs.getName();
        });
}

void ViewEmployees::display() {
    for(const Employee &employee : app.getAirline().getEmployees())
        cout << employee;
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
