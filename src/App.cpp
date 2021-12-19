#include "../include/App.h"

using namespace std;

App::App() = default;
App::~App() = default;

Airline &App::getAirline(){
    return airline;
}

vector<Airport> &App::getAirports(){
    return airports;
}

void App::addAirport(const Airport& airport) {
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
        case 1: readEmployeesFile(); break;
        case 2: readFlightsFile(); break;
        case 3: readPlanesFile(); break;
        case 4: readCartsFile(); break;
        default: break;
    }
}

void App::writeFile(int file) {
    switch (file) {
        case 0: writeAirportsFile();break;
        case 1: writeEmployeesFile();break;
        case 2: writeFlightsFile();break;
        case 3: writePlanesFile();break;
        case 4: writeCartsFile(); break;
        default: break;
    }
}

void App::writeAirportsFile() {
    std::ofstream file(dataFolder + files.names.at(0), ofstream::trunc);
    if(file.is_open()){
        file << airports.size() << endl;
        for(Airport airport : airports){
           file << airport.getName() << endl;
           file << airport.getCity() << endl;
           file << airport.getLocals().size() << endl;
           auto it = airport.localsBeginItr();
           while (it != airport.localsEndItr()){
               file << (*it).getType() << endl;
               file << (*it).getDistance() << endl;
               file << (*it).getSchedules().size() << endl;
               for (auto sch : (*it).getSchedules()){
                   file << sch.getTime() << endl;
               }
               it++;
           }
       }
    }
    file.close();
}


void App::writeEmployeesFile() {
    std::ofstream file(dataFolder + files.names.at(1), ofstream::trunc);
    if(file.is_open()){
        file << airline.getEmployees().size() << endl;
        for(auto &employee : airline.getEmployees()){
            file << employee.getName() << endl;
            file << employee.getType() << endl;
            file << employee.isOnDuty() << endl;
        }
    }
    file.close();
}

void App::writeFlightsFile() {
    std::ofstream file(dataFolder + files.names.at(2), ofstream::trunc);
    if(file.is_open()){
        file << airline.getFlights().size() << endl;
        for(auto &flight : airline.getFlights()){
            writeaFlight(file, flight);
        }
    }
    file.close();
}

void App::writePlanesFile() {
    std::ofstream file(dataFolder + files.names.at(3), ofstream::trunc);
    if(file.is_open()){
        file << airline.getPlanes().size() << endl;
        for(Plane &plane : airline.getPlanes()){
            file << plane.getPlate() << endl;
            file << plane.getCapacity() << endl;
            file << plane.getOnDuty() << endl;
            file << plane.getServicesToDo().size() << endl;
            queue<Service> qserv = plane.getServicesToDo();
            while (!qserv.empty()){
                Service sv = qserv.front();
                file << sv.getType() << endl;
                file << sv.getDate().getDate() << endl;
                file << sv.getEmployee()->getName() << endl;
                file << sv.getEmployee()->isOnDuty() << endl;
                qserv.pop();
            }
            vector<Service> vserv= plane.getServicesDone();
            file << vserv.size() << endl;
            for (const Service& sv : vserv){
                file << sv.getType() << endl;
                file << sv.getDate().getDate() << endl;
                file << sv.getEmployee()->getName() << endl;
                file << sv.getEmployee()->isOnDuty() << endl;
            }
            file << plane.getTrunk().size() << endl;
            list<Baggage> bgs = plane.getTrunk();
            for ( Baggage &bg : bgs){
                file << bg.getWeight() << endl;
            }
            file << plane.getFlightPlan().size() << endl;
            for ( Flight &f : plane.getFlightPlan()){
                writeaFlight(file, f);
            }
        }
    }
    file.close();
}

void App::writeCartsFile() {
    std::ofstream file(dataFolder + files.names.at(3), ofstream::trunc);
    if(file.is_open()){
        file << airline.getCarts().size();
        for (TransportCart &cart : airline.getCarts()){
            file << cart.getNumBaggs() << endl;
            file << cart.getNumber() << endl;
            file << cart.getC() << " " << cart.getN() << " " << cart.getM() << endl;
            stack<Baggage> aux;
            auto slots = cart.getSlots();
            for (auto carriage = slots.rbegin(); carriage != slots.rend(); carriage++){
                for (auto stack = (*carriage).rbegin(); stack != (*carriage).rend(); stack++){
                    while(!(*stack).empty()){
                        aux.push((*stack).top());
                        (*stack).pop();
                    }
                }
            }
            while (!aux.empty()){
                file << aux.top().getWeight() << endl;
                aux.pop();
            }
        }
    }
    file.close();
}

void App::readAirportsFile() {
    std::ifstream file(dataFolder + files.names.at(0));
    int airs, locals, distance, schs;
    string name, city, type, schedule;
    if(file.is_open()){
        file >> airs;
        for(int i = 0; i < airs; i++){
            file >> name;
            file >> city;
            file >> locals;
            Airport air(name, city);
            for(int j = 0; j < locals; j++){
                file >> type;
                file >> distance;
                file >> schs;
                GroundTransportation gd(type, distance);
                for(int k = 0; k < schs; k++){
                    file >> schedule;
                    gd.addSchedule(Schedule(schedule));
                }
                air.addGroundTransportation(gd);
            }
            airports.push_back(air);
        }
    }
    file.close();
}

void App::readEmployeesFile() {
    std::ifstream file(dataFolder + files.names.at(1));
    int sz; bool duty;
    string name, type;
    if(file.is_open()){
        file >> sz;
        for(int i = 0; i < sz ; i++){
            file >> name;
            file >> type;
            file >> duty;
            Employee emp(name, type);
            duty ? emp.setOnDuty() : emp.setOffDuty();
            airline.getEmployees().push_back(emp);
        }
    }
    file.close();
}

void App::readFlightsFile() {
    std::ifstream file(dataFolder + files.names.at(2));
    int numflights, num, numPassg, qSize;
    int number, weight;
    string name, date, departure, duration, origin, destiny;
    bool fcheckin, ischeckin, wantscheckin;
    if(file.is_open()){
        file >> numflights;
        for (int i = 0; i < numflights; i++){
            Flight f = readaFlight(file);
            airline.addFlight(&f);
        }
    }
    file.close();
}

void App::readPlanesFile() {
    std::ifstream file(dataFolder + files.names.at(3));
    string plate, name, date, type;
    int capacity, numplanes, weight, size, fnum;
    bool duty, planeduty;
    if(file.is_open()){
        file >> numplanes;
        for(int l = 0; l < numplanes; l++){
            file >> plate;
            file >> capacity;
            file >> planeduty;
            file >> size;
            Plane p(plate, capacity); p.setOnDuty(planeduty);
            queue<Service> servicesToDo;
            for (int i = 0; i < size; i++){
                file >> type;
                file >> date;
                file >> name;
                file >> duty;
                auto employee = find_if(airline.getEmployees().begin(), airline.getEmployees().end(),
                        [&name](const Employee &emp){return emp.getName() == name;});
                Service sv(type, Date(date), employee.base());
                servicesToDo.push(sv);
            }
            vector<Service> servicesDone;
            file >> size;
            for (int j = 0; j < size; j++){
                file >> type;
                file >> date;
                file >> name;
                file >> duty;
                auto employee = find_if(airline.getEmployees().begin(), airline.getEmployees().end(),
                                        [&name](const Employee &emp){return emp.getName() == name;});
                Service sv(type, Date(date), employee.base());
                servicesDone.push_back(sv);
            }
            file >> size;
            list<Baggage> bgs;
            for ( int k = 0; k < size; k++){
                file >> weight;
                bgs.emplace_back(weight);
            }
            file >> size;
            for (int m = 0; m < size; m++){
                Flight f = readaFlight(file);
                p.addFlight(f);
            }
            p.setPlaneTrunk(bgs);
            p.setServicesDone(servicesDone);
            p.setServicesToDo(servicesToDo);
            airline.getPlanes().push_back(p);
        }
    }
    file.close();
}

void App::readCartsFile() {
    std::ifstream file(dataFolder + files.names.at(3));
    int ncarts, numbgs, numcart, c, n, m, weight;
    if(file.is_open()){
        file >> ncarts;
        for (int i = 0; i < ncarts; i++){
            file >> numbgs;
            file >> numcart;
            file >> c >> n >> m;
            TransportCart cart(c, n, m);
            cart.setNumber(numcart);
            for (int j = 0; j < numbgs; j++){
                file >> weight;
                cart.addBaggage(Baggage(weight));
            }
            airline.getCarts().push_back(cart);
        }
    }
    file.close();
}

Flight App::readaFlight(ifstream &file) {
    int num, numPassg, qSize;
    int number, weight, passengerId;
    string name, date, departure, duration, origin, destiny;
    bool fcheckin, ischeckin, wantscheckin;
    file >> num;
    file >> date;
    file >> departure;
    file >> duration;
    file >> origin;
    file >> destiny;
    file >> fcheckin;
    file >> numPassg;
    auto ori = find_if(airports.begin(), airports.end(),
                       [&origin](const Airport &air){return air.getName() == origin;});
    auto des = find_if(airports.begin(), airports.end(),
                       [&destiny](const Airport &air){return air.getName() == destiny;});
    Flight f = Flight(num, new Date(date), ori.base(), des.base());
    f.setDeparture(departure); f.setDuration(duration); f.setCheckIn(fcheckin);
    for (int j = 0; j < numPassg; j++){
        file >> passengerId;
        file >> name;
        file >> ischeckin >> wantscheckin;
        file >> weight;
        for (Flight &fl : airline.getFlights()){
            auto ps = find_if(fl.getPassengers().begin(), fl.getPassengers().end(),
                    [&passengerId](Passenger &passg){return passg.getId() == passengerId;});
            if (ps != fl.getPassengers().end()){
                f.addPassenger((*ps));
            }
            else f.addPassenger(Passenger(name, new Baggage(weight), wantscheckin));
        }
    }
    queue<Baggage> q;
    file >> qSize;
    for (int k=0; k<qSize; k++){
        file >> weight;
        q.push(Baggage(weight));
    }
    f.setTreadmill(q);
    return f;
}

void App::writeaFlight(ofstream &file, Flight &flight) {
    file << flight.getNumber() << endl;
    file << flight.getDate().getDate() << endl;
    file << flight.getDeparture() << endl;
    file << flight.getDuration() << endl;
    file << flight.getOriginAir()->getName() << endl;
    file << flight.getDestinyAir()->getName() << endl;
    file << flight.getCheckInStatus() << endl;
    file << flight.getNumberPassengers() << endl;
    for (auto &p : flight.getPassengers()){
        file << p.getId() << endl;
        file << p.getName() << endl;
        file << p.isCheckedIn() << " " << p.wantsAutomaticCheckIn() << endl;
        Baggage bg = *p.getBaggage();
        file << bg.getWeight() << endl;
    }
    queue<Baggage> q = flight.getTreadmill();
    file << q.size() << endl;
    while (!q.empty()) {
        file << q.front().getWeight() << endl;
        q.pop();
    }
}
