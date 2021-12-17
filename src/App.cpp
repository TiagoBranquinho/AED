#include "../include/App.h"

using namespace std;

App::App() {
    //loadData();
}

App::~App() {
    //saveData();
}

Airline &App::getAirline(){
    return airline;
}

vector<Airport> &App::getAirports(){
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
        case 1: readEmployeesFile(); break;
        case 2: readFlightsFile(); break;
        case 3: readPlanesFile(); break;
        default: break;
    }
}

void App::writeFile(int file) {
    switch (file) {
        case 0: writeAirportsFile();break;
        case 1: writeEmployeesFile();break;
        case 2: writeFlightsFile();break;
        case 3: writePlanesFile();break;
        default: break;
    }
}

void App::writeAirportsFile() {
    std::ofstream file(dataFolder + files.names.at(0), ofstream::trunc);
    if(file.is_open()){
        file << airports.size() << endl;
        for(Airport &airport : airports){
           file << airport.getName() << endl << airport.getCity() << endl;
           file << airport.getLocals().size() << endl;
           auto it = airport.localsBeginItr();
           while (it != airport.localsEndItr()){
               file << (*it).getType() << " " << (*it).getDistance() << endl;
               file << (*it).getSchedules().size() << endl;
               for (auto sch : (*it).getSchedules()){
                   file << sch.getTime() << endl;
               }
               it++;
           }
           file << endl;
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
            file << flight.getNumber() << endl;
            file << flight.getDate().getDate() << endl;
            file << flight.getDeparture() << endl;
            file << flight.getDuration() << endl;
            file << flight.getOrigin() << endl;
            file << flight.getDestiny() << endl;
            file << flight.getCheckInStatus() << endl;
            file << flight.getNumberPassengers() << endl;
            for (auto &p : flight.getPassengers()){
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
    }
    file.close();
}

void App::writePlanesFile() {
    std::ofstream file(dataFolder + files.names.at(3), ofstream::trunc);
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            file << plane.getPlate() << endl;
            file << plane.getCapacity() << endl;
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
            for ( Baggage bg : bgs){
                file << bg.getWeight() << endl;
            }
        }
    }
    file.close();
}

void App::writeCartsFile() {

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
                file >> type >> distance;
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
                file >> name;
                file >> ischeckin >> wantscheckin;
                file >> weight;
                f.addPassenger(Passenger(name, new Baggage(weight), wantscheckin));
            }
            queue<Baggage> q;
            file >> qSize;
            for (int k=0; k<qSize; k++){
                file >> weight;
                q.push(Baggage(weight));
            }
            f.setTreadmill(q);
            airline.addFlight(&f);
        }
    }
    file.close();
}

void App::readPlanesFile() {
    std::ifstream file(dataFolder + files.names.at(3));
    string plate, name, date, type;
    int capacity, size, weight;
    bool duty;
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            file >> plate;
            file >> capacity;
            file >> size;
            Plane p(plate, capacity);
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
            p.setPlaneTrunk(bgs);
            p.setServicesDone(servicesDone);
            p.setServicesToDo(servicesToDo);
            airline.getPlanes().push_back(p);
        }
    }
    file.close();
}

void App::readCartsFile() {

}
