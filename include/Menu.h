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
    int readOpt();
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
    std::string sortedBy;
public:
    ViewAirports(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewGroundLocals: public Menu{
    std::string sortedBy;
public:
    ViewGroundLocals(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesTODO: public Menu{
public:
    ViewServicesTODO(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesDONE: public Menu{
public:
    ViewServicesDONE(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlanes: public Menu{
    std::string duty;
public:
    ViewPlanes(App &app, std::string duty="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlaneFlights: public Menu{
    std::string sortedBy;
public:
    ViewPlaneFlights(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlights: public Menu{
    std::string sortedBy;
public:
    ViewFlights(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlightPassengers: public Menu{
    std::string sortedBy;
public:
    ViewFlightPassengers(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewEmployees: public Menu{
    std::string sortedBy;
public:
    ViewEmployees(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPassengers: public Menu{
    std::string sortedBy;
public:
    ViewPassengers(App &app, std::string sortedBy="");
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
