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
    for (int file = 0; file < filesname.size(); file++){
        readFile(file);
    }
}

void App::saveData() {
    for (int file = 0; file < filesname.size(); file++){
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
    std::ofstream file(dataFolder + filesname.at(0), ofstream::trunc);
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
               for (auto &sch : (*it).getSchedules()){
                   file << sch.getTime() << endl;
               }
               it++;
           }
       }
    }
    file.close();
}


void App::writeEmployeesFile() {
    std::ofstream file(dataFolder + filesname.at(1), ofstream::trunc);
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
    std::ofstream file(dataFolder + filesname.at(2), ofstream::trunc);
    if(file.is_open()){
        file << airline.getFlights().size() << endl;
        for(auto &flight : airline.getFlights()){
            writeaFlight(file, flight);
        }
    }
    file.close();
}

void App::writePlanesFile() {
    std::ofstream file(dataFolder + filesname.at(3), ofstream::trunc);
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
    std::ofstream file(dataFolder + filesname.at(4), ofstream::trunc);
    if(file.is_open()){
        file << airline.getCarts().size() << endl;
        for (TransportCart &cart : airline.getCarts()){
            file << cart.getC() << endl;
            file << cart.getN() << endl;
            file << cart.getM() << endl;
        }
    }
    file.close();
}

void App::readAirportsFile() {
    std::ifstream file(dataFolder + filesname.at(0));
    int airs, locals, distance, schs;
    string name, city, type, schedule;
    if(file.is_open()){
        getlineint(file, airs);
        for(int i = 0; i < airs; i++){
            getline(file, name);
            getline(file, city);
            getlineint(file, locals);
            Airport air(name, city);
            for(int j = 0; j < locals; j++){
                getline(file, type);
                getlineint(file, distance);
                getlineint(file, schs);
                GroundTransportation gd(type, distance);
                for(int k = 0; k < schs; k++){
                    getline(file, schedule);
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
    std::ifstream file(dataFolder + filesname.at(1));
    int sz, duty;
    string name, type;
    if(file.is_open()){
        getlineint(file, sz);
        for(int i = 0; i < sz ; i++){
            getline(file, name);
            getline(file, type);
            getlineint(file, duty);
            Employee emp(name, type);
            duty ? emp.setOnDuty() : emp.setOffDuty();
            airline.getEmployees().push_back(emp);
        }
    }
    file.close();
}

void App::readFlightsFile() {
    std::ifstream file(dataFolder + filesname.at(2));
    int numflights, num, numPassg, qSize;
    int number, weight;
    string name, date, departure, duration, origin, destiny;
    bool fcheckin, ischeckin, wantscheckin;
    if(file.is_open()){
        getlineint(file, numflights);
        for (int i = 0; i < numflights; i++){
            Flight f = readaFlight(file);
            airline.addFlight(&f);
        }
    }
    file.close();
}

void App::readPlanesFile() {
    std::ifstream file(dataFolder + filesname.at(3));
    string plate, name, date, type;
    int capacity, numplanes, weight, size, fnum;
    int duty, planeduty;
    if(file.is_open()){
        getlineint(file, numplanes);
        for(int l = 0; l < numplanes; l++){
            getline(file, plate);
            getlineint(file, capacity);
            getlineint(file, planeduty);
            getlineint(file, size);
            Plane p(plate, capacity); p.setOnDuty(planeduty);
            queue<Service> servicesToDo;
            for (int i = 0; i < size; i++){
                getline(file, type);
                getline(file, date);
                getline(file, name);
                getlineint(file, duty);
                auto employee = find_if(airline.getEmployees().begin(), airline.getEmployees().end(),
                        [&name](const Employee &emp){return emp.getName() == name;});
                Service sv(type, Date(date), employee.base());
                servicesToDo.push(sv);
            }
            vector<Service> servicesDone;
            getlineint(file, size);
            for (int j = 0; j < size; j++){
                getline(file, type);
                getline(file, date );
                getline(file, name);
                getlineint(file, duty);
                auto employee = find_if(airline.getEmployees().begin(), airline.getEmployees().end(),
                                        [&name](const Employee &emp){return emp.getName() == name;});
                Service sv(type, Date(date), employee.base());
                servicesDone.push_back(sv);
            }
            getlineint(file, size);
            list<Baggage> bgs;
            for ( int k = 0; k < size; k++){
                getlineint(file, weight);
                bgs.emplace_back(weight);
            }
            getlineint(file, size);
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
    std::ifstream file(dataFolder + filesname.at(4));
    int ncarts, c, n, m;
    if(file.is_open()){
        getlineint(file, ncarts);
        for (int i = 0; i < ncarts; i++){
            getlineint(file, c);
            getlineint(file, n);
            getlineint(file, m);
            airline.getCarts().emplace_back(c, n, m);
        }
    }
    file.close();
}

Flight App::readaFlight(ifstream &file) {
    int num, numPassg, qSize;
    int number, weight, passengerId;
    string name, date, departure, duration, origin, destiny;
    int fcheckin, ischeckin, wantscheckin;
    getlineint(file, num);
    getline(file, date);
    getline(file, departure);
    getline(file, duration);
    getline(file, origin);
    getline(file, destiny);
    getlineint(file, fcheckin);
    getlineint(file, numPassg);
    auto ori = find_if(airports.begin(), airports.end(),
                       [&origin](const Airport &air){return air.getName() == origin;});
    auto des = find_if(airports.begin(), airports.end(),
                       [&destiny](const Airport &air){return air.getName() == destiny;});
    Flight f = Flight(num, new Date(date), ori.base(), des.base());
    f.setDeparture(departure); f.setDuration(duration); f.setCheckIn(fcheckin);
    for (int j = 0; j < numPassg; j++){
        getlineint(file, passengerId);
        getline(file, name);
        getlineint(file, ischeckin);
        getlineint(file, wantscheckin);
        getlineint(file, weight);
        bool found = false;
        for (Flight &fl : airline.getFlights()){
            auto ps = find_if(fl.getPassengers().begin(), fl.getPassengers().end(),
                    [&passengerId](Passenger &passg){return passg.getId() == passengerId;});
            if (ps != fl.getPassengers().end()){
                f.addPassenger((*ps));
                found = true; break;
            }
        }
        if (!found) f.addPassenger(Passenger(name, new Baggage(weight), wantscheckin));
    }
    queue<Baggage> q;
    getlineint(file, qSize);
    for (int k=0; k<qSize; k++){
        getlineint(file, weight);
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
    file << flight.getOriginPointer()->getName() << endl;
    file << flight.getDestinyPointer()->getName() << endl;
    file << flight.getCheckInStatus() << endl;
    file << flight.getNumberPassengers() << endl;
    for (auto &p : flight.getPassengers()){
        file << p.getId() << endl;
        file << p.getName() << endl;
        file << p.isCheckedIn() << endl;
        file << p.wantsAutomaticCheckIn() << endl;
        file << p.baggageWeight()<< endl;
    }
    queue<Baggage> q = flight.getTreadmill();
    file << q.size() << endl;
    while (!q.empty()) {
        file << q.front().getWeight() << endl;
        q.pop();
    }
}

void App::getlineint(ifstream &file, int &num) {
    string s;
    getline(file, s);
    stringstream ss(s);
    ss >> num;
    if(!(!ss.fail() && ss.eof()))
        cout << "Invalid file input:  " << s << endl;
}
