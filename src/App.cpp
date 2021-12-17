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
    std::ofstream file(dataFolder + files.names.at(3), ofstream::trunc);
    if(file.is_open()){
        file << airline.getFlights().size() << endl;
        for(auto &flight : airline.getFlights()){
            file << flight.getNumber() << endl;
            file << flight.getDate().getDate() << endl;
            file << flight.getDeparture() << endl;
            file << flight.getDuration() << endl;
            file << flight.getOriginAir()->getName() << endl;
            file << flight.getDestinyAir()->getName() << endl;
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
    std::ofstream file(dataFolder + files.names.at(5));
    file.clear();
    if(file.is_open()){
        for(const Plane &plane : airline.getPlanes()){
            file << plane;
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
}

void App::readEmployeesFile() {

}

void App::readFlightsFile() {
    std::ifstream file(dataFolder + files.names.at(3));
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
    std::string plate;
    unsigned int capacity;
    ifstream file(dataFolder + files.names.at(5));
    while(file >> plate >> capacity){
        airline.addPlane(Plane(plate,capacity));
    }
}
