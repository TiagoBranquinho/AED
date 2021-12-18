#include "../include/Menu.h"
#include <iostream>

using namespace std;

Menu::~Menu() = default;

Menu::Menu(App &app): app(app) {}

int Menu::readInt() {
    int opt; string optstr;
    while (true){
        stringstream ss;
        ss << readStr(); ss >> opt;
        if(!ss.fail() && ss.eof() && opt>=0) break;
        cout << "Invalid input. Try a valid integer..." << endl;
    }
    cout << endl;
    return opt;
}

void Menu::waitForKey() {
    string str;
    cout << endl << "Press enter to continue..." << endl;
    getline(cin, str);
}

std::string Menu::readStr() {
    string str;
    cout << ": ";
    getline(cin, str);
    return str;
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
    switch (readInt()) {
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
    cout << "3 - View Airport's Ground Locals sorted by distance" << endl;
    cout << "4 - View Airport's Ground Locals sorted by type" << endl;
    cout << "5 - Add Airport" << endl;
    cout << "6 - Remove Airport" << endl;
    cout << "7 - Add Ground Local to Airport" << endl;
    cout << "8 - Remove Ground Local from Airport" << endl;
    cout << "9 - View Schedules from Ground Local from Airport" << endl;
    cout << "10 - Add Schedule to Ground Locals of Airport" << endl;
    cout << "11 - Remove Schedule from Ground Locals of Airport" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *AirportMenu::nextMenu() {
    switch (readInt()) {
        case 1: return new ViewAirports(app, "name");
        case 2: return new ViewAirports(app, "city");
        case 3: return new ViewGroundLocals(app, "distance");
        case 4: return new ViewGroundLocals(app, "type");
        case 5: {
            cout << "Insert new airport's name" << endl;
            std::string name = readStr();
            if (name.empty()) return this;
            cout << "Insert new airport's city" << endl;
            std::string city = readStr();
            if (city.empty()) return this;
            app.addAirport(Airport(name, city));
            return this;
        }
        case 6: {
            cout << "Insert airport's id" << endl;
            unsigned int id = readInt();
            auto it = std::find_if(app.getAirports().begin(), app.getAirports().end(), [&id](const auto &airport){return airport.getId() == id;});
            if(it != app.getAirports().end())
                app.getAirports().erase(it);
            else
                cout << "There's no such airport" << endl;
            return this;
       }
        case 7: {
            cout << "Insert airport's id" << endl;
            unsigned int id= readInt();
            cout << "Insert local's transportations service type" << endl;
            std::string type = readStr();
            if (type.empty()) return this;
            cout << "Insert local's distance to airport" << endl;
            unsigned int distance = readInt();
            bool done = false;
            for(Airport &airport : app.getAirports()){
                if(airport.getId() == id){
                    airport.addGroundTransportation(GroundTransportation(type, distance));
                    done = true;
                }
            }
            if(!done){
                cout << "There's no such airport" << endl;
            }
            else
                cout << "Local added successfully" << endl;
            return this;
        }
        case 8: {
            cout << "Insert airport's id" << endl;
            unsigned int id1 = readInt();
            cout << "Insert local's id" << endl;
            unsigned int id2 = readInt();
            bool done = false;
            for(Airport &airport : app.getAirports()){
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
            }
            return this;
        }
        case 9: return new ViewSchedules(app);
        case 10:{
            cout << "Insert airport id " << endl;
            int airId = readInt();
            cout << "Insert Ground Local id" << endl;
            int gdId = readInt();
            cout << "Insert schedule in format (HH:MM) " << endl;
            string schedule = readStr();
            if (schedule.empty()) return this;
            auto airp = find_if(app.getAirports().begin(), app.getAirports().end(), [&airId](const Airport &air){return air.getId() == airId;});
            if (airp != app.getAirports().end()){
                auto gd = airp->getLocals().beginItr();
                GroundTransportation newgd;
                bool done = false;
                while (gd != airp->getLocals().endItr()){
                    if ((*gd).getId() == gdId){
                        newgd = (*gd);
                        newgd.addSchedule(Schedule(schedule));
                        done = true; break;
                    }
                    gd++;
                }
                if (done){
                    airp->getLocals().removeGroundTransportation(*gd);
                    airp->getLocals().addGroundTransportation(newgd);
                    cout << "Successfully added Schedule" << endl;
                }
                else cout << "Ground Local not found! " << endl;
            }
            waitForKey();
            return this;
        }
        case 11:{
            cout << "Confirm Airport id " << endl;
            int airId = readInt();
            cout << "Insert Ground Local id" << endl;
            int gdId = readInt();
            cout << "Insert schedule in format (HH:MM) " << endl;
            string schedule = readStr();
            if (schedule.empty()) return this;
            auto airp = find_if(app.getAirports().begin(), app.getAirports().end(),
                                [&airId](const Airport &air){return air.getId() == airId;});

            auto gd = airp->getLocals().beginItr();
            GroundTransportation newgd;
            bool done = false;
            while (gd != airp->getLocals().endItr()){
                if ((*gd).getId() == gdId){
                    newgd = (*gd);
                    auto rm = find_if(newgd.getSchedules().begin(), newgd.getSchedules().end(),[&schedule](const Schedule &sch) { return sch.getTime() == schedule; });
                    if (rm != (*gd).getSchedules().end()){
                        newgd.removeSchedule(*rm);
                        cout << "Schedule successfully schedule removed." << endl;
                        done = true; break;
                    }
                }
                gd++;
            }
            if (done){
                airp->getLocals().removeGroundTransportation(*gd);
                airp->getLocals().addGroundTransportation(newgd);
            }
            else cout << "Schedule not found!" << endl;
            waitForKey();
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
    cout << "2 - View all Planes by plate" << endl;
    cout << "3 - View all Planes by capacity" << endl;
    cout << "4 - View Planes on duty" << endl;
    cout << "5 - View Planes off duty" << endl;
    cout << "6 - Add Service to Plane" << endl;
    cout << "7 - Mark Plane's Service as DONE" << endl;
    cout << "8 - View ServicesTODO of Plane" << endl;
    cout << "9 - View ServicesDONE of Plane by Date" << endl;
    cout << "10 - Add Plane" << endl;
    cout << "11 - Remove Plane" << endl;
    cout << "12 - View Plane's Flights by Date" << endl;
    cout << "13 - View Plane's Flights by Number" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *PlaneMenu::nextMenu() {
    switch (readInt()) {
        case 1: return new ViewPlanes(app);
        case 2: return new ViewPlanes(app,"plate");
        case 3: return new ViewPlanes(app,"capacity");
        case 4: return new ViewPlanes(app,"on");
        case 5: return new ViewPlanes(app, "off");
        case 6: {
            cout << "Insert plane plate" << endl;
            std::string plate = readStr();
            if (plate.empty()) return this;
            bool employeeExists = false;
            bool done = false;
            for(Plane &plane : app.getAirline().getPlanes()){
                if(plane.getPlate() == plate){
                    cout << "Insert type of service" << endl;
                    std::string type = readStr();
                    if (type.empty()) return this;
                    cout << "Insert date of service (day then month then year)" << endl;
                    unsigned int day, month, year;
                    day = readInt();
                    month = readInt();
                    year = readInt();
                    Date date (day, month, year);
                    cout << "Insert the id of the employee responsible for the service" << endl;
                    unsigned int id = readInt();
                    Service service;
                    for (Employee &employee : app.getAirline().getEmployees()){
                        if(employee.getId() == id){
                            service = Service (type, date, &employee);
                            employeeExists = true;
                            break;
                        }
                    }
                    if(!employeeExists) {
                        cout << "There's no such employee" << endl;
                        return this;
                    }
                    else {
                        plane.addService(service);
                        done = true;
                        break;
                    }
                }
            }
            if(!done)
                cout << "There's no such plane" << endl;
            else
                cout << "Service added successfully" << endl;
            return this;
        }
        case 7: {
            cout << "Insert plane plate" << endl;
            std::string plate = readStr();
            if (plate.empty()) return this;
            bool done = true;
            for(Plane &plane : app.getAirline().getPlanes()) {
                if (plane.getPlate() == plate) {
                    if(plane.getServicesToDo().empty()){
                        cout << "There's no services to do in this plane" << endl;
                        return this;
                    }
                    plane.removeServiceDONE();
                    done = true;
                    cout << "Service successfully marked as done" << endl;
                    break;
                }
            }
            if(!done)
                cout << "There's no such plane" << endl;
            return this;
        }
        case 8: return new ViewServicesTODO(app);
        case 9: return new ViewServicesDONE(app, "date");
        case 10: {
            cout << "Insert new plane's plate" << endl;
            std::string plate = readStr();
            if (plate.empty()) return this;
            cout << "Insert new plane's capacity" << endl;
            unsigned int capacity = readInt();
            try {
                app.getAirline().addPlane(Plane(plate, capacity));
            }
            catch(InvalidPlateException &e) {
                cout << "Inserted invalid plane plate" << endl;
                return this;
            }
            return this;
        }
        case 11: {
            cout << "Insert plane's plate" << endl;
            std::string plate = readStr();
            if (plate.empty()) return this;
            bool done = false;
            for (Plane &plane : app.getAirline().getPlanes()){
                if(plane.getPlate() == plate){
                    for(auto it = app.getAirline().getPlanes().begin(); it != app.getAirline().getPlanes().end(); it++){
                        if((*it) == plane){
                            app.getAirline().getPlanes().erase(it);
                            done = true;
                            break;
                        }
                    }
                }
            }
            if(!done)
                cout << "There's no such plane";
            return this;
        }

        case 12:  return new ViewPlaneFlights(app,"date");
        case 13: return new ViewPlaneFlights(app,"number");
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
    switch (readInt()) {
        case 1: return new ViewFlights(app);
        case 2: return new ViewFlights(app,"date");
        case 3: return new ViewFlights(app,"id");
        case 4: return new ViewFlightPassengers(app,"id");
        case 5: return new ViewFlightPassengers(app,"name");
        case 6: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
            cout << "Insert date of flight (year/month/day)" << endl;
            string dt = readStr();
            if (dt.empty()) return this;
            try {
                Date date(dt);
            }
            catch(InvalidDateException){
                cout << "Inserted an invalid date format" << endl;
                return this;
            }
            Date date(dt);
            cout << "Insert the id of the airport of origin of the flight" << endl;
            unsigned int id1 = readInt();
            cout << "Insert the id of the airport of destiny of the flight" << endl;
            unsigned int id2 = readInt();
            auto origin = find_if(app.getAirports().begin(), app.getAirports().end(),
                                  [&id1](const Airport &air){return air.getId()==id1;});
            auto destiny = find_if(app.getAirports().begin(), app.getAirports().end(),
                                   [&id2](const Airport &air){return air.getId()==id2;});
            if (origin != app.getAirports().end() && destiny != app.getAirports().end()){
                auto *f = new Flight(number, &date, origin.base(), destiny.base());
                ViewPlanes vp(app);
                vp.display();
                cout << "Select a plane to realize this flight" << endl;
                string plate = readStr();
                auto plane = find_if(app.getAirline().getPlanes().begin(), app.getAirline().getPlanes().end(),[&plate](Plane &p){return p.getPlate()==plate;});
                if(plane != app.getAirline().getPlanes().end()) {
                    if((*plane).getOnDuty()){
                        cout << "That plane is already on duty" << endl;
                        return this;
                    }
                    else {
                        (*plane).addFlight(*f);
                        app.getAirline().addFlight(f);
                        cout << "Flight added successfully." << endl;
                    }
                }
                else{
                    cout << "There's no such plane" << endl;
                    return this;
                }
            }
            else {
                cout << "Invalid airport ids!" << endl;
            }
            return this;
        }
        case 7: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
            bool done = false;
            for(auto it = app.getAirline().getFlights().begin(); it != app.getAirline().getFlights().end(); it++) {
                if ((*it).getNumber() == number) {
                    app.getAirline().getFlights().erase(it);
                    cout << "Flight removed successfully." << endl;
                    done = true;
                    break;
                }
            }
            if(!done){
                cout << "There's no such flight" << endl;
            }
            return this;
        }
        case 8: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
            bool done = false;
            for(Plane &plane : app.getAirline().getPlanes()){
                for (Flight &flight : plane.getFlightPlan()){
                    if(flight.getNumber() == number) {
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
            return this;
        }
        case 9: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
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
            return this;
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
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *EmployeesMenu::nextMenu() {
    switch (readInt()) {
        case 1: return new ViewEmployees(app);
        case 2: return new ViewEmployees(app,"name");
        case 3: return new ViewEmployees(app,"id");
        case 4: {
            cout << "Insert employee's name" << endl;
            std::string name = readStr();
            if (name.empty()) return this;
            cout << "Insert employee's type" << endl;
            std::string type = readStr();
            if (type.empty()) return this;
            app.getAirline().addEmployee(Employee(name, type));
            waitForKey();
            return this;
        }
        case 5: {
            cout << "Insert employee's id" << endl;
            unsigned int id = readInt();
            bool done = false;

            auto rm = find_if(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(),
                                    [&id](Employee &emp){return emp.getId() == id;});
            if (rm != app.getAirline().getEmployees().end()){
                app.getAirline().removeEmployee(*rm);
                done = true;
            }
            if(done)
                cout << "Employee removes successfully." << endl;
            else
                cout << "There's no such employee" << endl;
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
    cout << "0 - Exit" << endl;
    cout << endl;
}

Menu *PassengerAndBaggageMenu::nextMenu() {
    switch (readInt()) {
        case 1: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
            cout << "Insert passenger's name" << endl;
            string name = readStr();
            if (name.empty()) return this;
            cout << "Insert passenger's baggage weight (0 if there isn't any)" << endl;
            double weight = readInt();
            bool done = false;
            Passenger passenger;
            if(weight > 0){
                Baggage baggage(weight);
                cout << "Does the passenger want automatic check in? Insert 1 for yes and 0 for no" << endl;
                bool wantsAutomaticCheckIn = readInt();
                passenger = Passenger(name, &baggage,wantsAutomaticCheckIn);
            }
            else
                passenger = Passenger(name, nullptr,false);
            for(Flight &flight : app.getAirline().getFlights()){
                if(flight.getNumber() == number) {
                    try {
                        app.getAirline().addPassengerToFlight(flight, passenger);
                    }
                    catch(InvalidFlightException) {
                        cout << "There's no such flight" << endl;
                        return this;
                    }
                    cout << "Added passenger successfully" << endl;
                    break;
                }
            }
            return this;
        }
        case 2: {
            cout << "Insert flight's number" << endl;
            unsigned int number = readInt();
            cout << "Insert passenger's id" << endl;
            unsigned int id = readInt();
            bool done = false;
            bool flighExists = false;
            for (Flight &flight: app.getAirline().getFlights()) {
                if (flight.getNumber() == number) {
                    flighExists = true;
                    for (auto it = flight.getPassengers().begin(); it != flight.getPassengers().end(); it++) {
                        if ((*it).getId() == id) {
                            flight.getPassengers().erase(it);
                            done = true;
                            break;
                        }
                    }
                    if(!done){
                        cout << "There's no such passenger on this flight" << endl;
                        return this;
                    }
                }
            }
            if(!flighExists)
                cout << "Invalid Flight Number!!" << endl;
            return this;
        }
        case 0: return nullptr;
        default: return invalidInput();
    }
}

ViewAirports::ViewAirports(App &app, const std::string& sortedBy): Menu(app){
    if (sortedBy == "name") {
        if (app.getAirports().size() <= 1) {}
        else {
            sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
                return lhs.getName() < rhs.getName();
            });
        }
    }
    if (sortedBy == "city") {
        if (app.getAirports().size() <= 1){}
        else {
            sort(app.getAirports().begin(), app.getAirports().end(), [](const Airport &lhs, const Airport &rhs) {
                return lhs.getCity() < rhs.getCity();
            });
        }
    }

}

void ViewAirports::display() {
    for(Airport &airport : app.getAirports())
        cout << airport;
    waitForKey();
}

Menu *ViewAirports::nextMenu() {
    return nullptr;
}

ViewGroundLocals::ViewGroundLocals(App &app, const std::string& sortedBy): Menu(app), sortedBy(sortedBy){
    cout << "Insert Airport's id: " << endl;
    unsigned int id = readInt();
    for(Airport &airport : app.getAirports()){
        if(airport.getId() == id){
            locals = airport.getLocals();
            locals_vector = locals.asVector();
        }
    }
    if(sortedBy == "type"){
        if(locals_vector.size() <= 1){}
        else {
            sort(locals_vector.begin(), locals_vector.end(),
                 [](const GroundTransportation &lhs, const GroundTransportation &rhs) {
                     return lhs.getType() < rhs.getType();
                 });
        }
    }
}

void ViewGroundLocals::display() {
    if(sortedBy == "type")
        for(GroundTransportation &groundTransportation : locals_vector){
            cout << groundTransportation;
        }
    else if (sortedBy == "distance")
        locals.print();
    waitForKey();
}

Menu *ViewGroundLocals::nextMenu() {
    return nullptr;
}

ViewServicesTODO::ViewServicesTODO(App &app) : Menu(app) {
    cout << "Insert plane's plate" << endl;
    plate = readStr();
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
    waitForKey();
}

Menu *ViewServicesTODO::nextMenu() {
    return nullptr;
}

ViewServicesDONE::ViewServicesDONE(App &app, const std::string& sortedBy) : Menu(app) {
    cout << "Insert plane's plate" << endl;
    plate = readStr();
    for(const Plane &plane : app.getAirline().getPlanes()){
        if(plane.getPlate() == plate){
            if(plane.getServicesDone().size() <= 1){}
            else if(sortedBy == "date")
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
    waitForKey();
}

Menu *ViewServicesDONE::nextMenu() {
    return nullptr;
}

ViewPlanes::ViewPlanes(App &app, const std::string& choice): Menu(app){
    if(choice == "on")
        onDuty = true;
    else if (choice == "off")
        onDuty = false;
    else if(choice == "plate") {
        if (app.getAirline().getPlanes().size() <= 1) {}
        else {
            sort(app.getAirline().getPlanes().begin(), app.getAirline().getPlanes().end(),
                 [](const Plane &lhs, const Plane &rhs) {
                     return lhs.getPlate() < rhs.getPlate();
                 });
        }
    }
    else if(choice == "capacity") {
        if (app.getAirline().getPlanes().size() <= 1) {}
        else {
            sort(app.getAirline().getPlanes().begin(), app.getAirline().getPlanes().end(),
                 [](const Plane &lhs, const Plane &rhs) {
                     return lhs.getCapacity() < rhs.getCapacity();
                 });
        }
    }
}

void ViewPlanes::display() {
    if(onDuty)
        for(const Plane &plane : app.getAirline().getPlanes()){
            if(plane.getOnDuty())
                cout << plane;
        }
    else if(!onDuty)
        for(const Plane &plane : app.getAirline().getPlanes()){
            if(!plane.getOnDuty())
                cout << plane;
        }
    else{
        for (const Plane &plane: app.getAirline().getPlanes()){
            cout << plane;
        }
    }
    waitForKey();
}


Menu *ViewPlanes::nextMenu() {
    return nullptr;
}

ViewPlaneFlights::ViewPlaneFlights(App &app, const std::string& sortedBy): Menu(app){
    cout << "Insert plane's plate" << endl;
    plate = readStr();
    for(const Plane &plane : app.getAirline().getPlanes()){
        if(plane.getPlate() == plate){
            for(const Flight &flight : plane.getFlightPlan())
                aux_vector.push_back(flight);
            if (sortedBy == "number") {
                if(aux_vector.size() <= 1){}
                else {
                    sort(aux_vector.begin(), aux_vector.end(), [](const Flight &lhs, const Flight &rhs) {
                        return lhs.getNumber() < rhs.getNumber();
                    });
                }
            }
            if (sortedBy == "date") {
                if(aux_vector.size() <= 1){}
                else {
                    sort(aux_vector.begin(), aux_vector.end(), [](Flight &lhs, Flight &rhs) {
                        return lhs.getDate() < rhs.getDate();
                    });
                }
            }
        }
    }
}

void ViewPlaneFlights::display() {
    for(const Flight &flight : aux_vector)
        cout << flight;
    waitForKey();
}

Menu *ViewPlaneFlights::nextMenu() {
    return nullptr;
}

ViewFlights::ViewFlights(App &app, const std::string& sortedBy): Menu(app) {
    if (sortedBy == "date") {
        if(app.getAirline().getFlights().size() <= 1){}
        else {
            sort(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(),
                 [](const Flight &lhs, const Flight &rhs) {
                     return lhs.getDate() < rhs.getDate();
            });
        }
    }
    if (sortedBy == "number") {
        if(app.getAirline().getFlights().size() <= 1){}
        else {
            sort(app.getAirline().getFlights().begin(), app.getAirline().getFlights().end(),
                 [](const Flight &lhs, const Flight &rhs) {
                     return lhs.getNumber() < rhs.getNumber();
            });
        }
    }
}

void ViewFlights::display() {
    for(Flight &flight : app.getAirline().getFlights())
        cout << flight;
    waitForKey();
}

Menu *ViewFlights::nextMenu() {
    return nullptr;
}

ViewFlightPassengers::ViewFlightPassengers(App &app, std::string sortedBy): Menu(app) {
    cout << "Insert flight's number" << endl;
    number = readInt();
    for (const Flight &flight: app.getAirline().getFlights()) {
        if (flight.getNumber() == number) {
            if (sortedBy == "id") {
                for (const Passenger &p: flight.getPassengers())
                    aux_vector.push_back(p);
                if(aux_vector.size() <= 1){}
                else {
                    sort(aux_vector.begin(), aux_vector.end(), [](const Passenger &lhs, const Passenger &rhs) {
                        return lhs.getId() < rhs.getId();
                    });
                }
            }
            if (sortedBy == "name") {
                for (const Passenger &p: flight.getPassengers())
                    aux_vector.push_back(p);
                if(aux_vector.size() <= 1){}
                else {
                    sort(aux_vector.begin(), aux_vector.end(), [](const Passenger &lhs, const Passenger &rhs) {
                        return lhs.getName() < rhs.getName();
                    });
                }
            }
        }
    }
}

void ViewFlightPassengers::display() {
    for(const Passenger &passenger : aux_vector)
        cout << passenger;
    waitForKey();
}

Menu *ViewFlightPassengers::nextMenu() {
    return nullptr;
}

ViewEmployees::ViewEmployees(App &app, const std::string& sortedBy): Menu(app) {
    if (sortedBy == "id") {
        if(app.getAirline().getEmployees().size() <= 1){}
        else {
            sort(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(),
                 [](const Employee &lhs, const Employee &rhs) {
                     return lhs.getId() < rhs.getId();
            });
        }
    }
    if (sortedBy == "name") {
        if (app.getAirline().getEmployees().size() <= 1) {}
        else {
            sort(app.getAirline().getEmployees().begin(), app.getAirline().getEmployees().end(),
                 [](const Employee &lhs, const Employee &rhs) {
                     return lhs.getName() < rhs.getName();
            });
        }
    }
}

void ViewEmployees::display() {
    for(const Employee &employee : app.getAirline().getEmployees())
        cout << employee;
    waitForKey();
}

Menu *ViewEmployees::nextMenu() {
    return nullptr;
}

ViewPassengers::ViewPassengers(App &app, const std::string& sortedBy): Menu(app) {

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

ViewSchedules::ViewSchedules(App &app): Menu(app) {
    cout << "Insert Airport's id " << endl;
    int airId = readInt();
    cout << "Insert Ground Local id" << endl;
    int gdId = readInt();
    auto airp = find_if(app.getAirports().begin(), app.getAirports().end(), [&airId](const Airport &air){return air.getId() == airId;});
    if (airp == app.getAirports().end()){
        cout << "Airport not found!" << endl;
        return;
    }
    auto gd = airp->getLocals().beginItr();
    while (gd != airp->getLocals().endItr()){
        if ((*gd).getId() == gdId){
            groundTransp = (*gd);
            return;
        }
        gd++;
    }
    cout << "Ground Local not found!" << endl;
}

void ViewSchedules::display() {
    for(Schedule &sch : groundTransp.getSchedules()){
        cout << sch << endl;
    }
    waitForKey();
}

Menu *ViewSchedules::nextMenu() {
    return nullptr;
}
