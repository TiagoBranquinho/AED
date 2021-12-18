#ifndef PROJETOAEROPORTO_MENU_H
#define PROJETOAEROPORTO_MENU_H

#include "App.h"

class Menu {
protected:
    App &app;
public:
    explicit Menu(App &app);
    virtual ~Menu();
    virtual void display()=0;
    virtual Menu *nextMenu()=0;
    int readInt();
    std::string readStr();
    void waitForKey();
    Menu *invalidInput();
};

class MainMenu: public Menu{
public:
    MainMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class AirportMenu: public Menu{
public:
    AirportMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class PlaneMenu: public Menu{
public:
    PlaneMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class FlightMenu: public Menu{
public:
    FlightMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class EmployeesMenu: public Menu{
public:
    EmployeesMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class PassengerAndBaggageMenu: public Menu{
public:
    PassengerAndBaggageMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};


class ViewAirports: public Menu{
public:
    ViewAirports(App &app, const std::string& sortedBy = "");
    void display() override;
    Menu *nextMenu() override;
};

class ViewGroundLocals: public Menu{
    std::string sortedBy;
    TransportationLocals locals;
    std::vector<GroundTransportation> locals_vector;
public:
    ViewGroundLocals(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesTODO: public Menu{
    std::string plate;
public:
    ViewServicesTODO(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesDONE: public Menu{
    std::string plate;
public:
    ViewServicesDONE(App &app, const std::string& sortedBy = "");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlanes: public Menu{
    bool onDuty;
public:
    ViewPlanes(App &app, const std::string& choice="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlaneFlights: public Menu{
private:
    std::string plate;
    std::vector<Flight> aux_vector;
public:
    ViewPlaneFlights(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlights: public Menu{
public:
    ViewFlights(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlightPassengers: public Menu{
    unsigned int number;
    std::vector<Passenger> aux_vector;
public:
    ViewFlightPassengers(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewEmployees: public Menu{
public:
    ViewEmployees(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPassengers: public Menu{
    std::string sortedBy;
public:
    ViewPassengers(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewBaggages: public Menu{
    std::string sortedBy;
public:
    ViewBaggages(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

#endif //PROJETOAEROPORTO_MENU_H
