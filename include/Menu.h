#ifndef PROJETOAEROPORTO_MENU_H
#define PROJETOAEROPORTO_MENU_H

#include "App.h"

class Menu {
protected:
    App &app;
public:
    /**
     * Class constructor with an application object
     * @param app application object passed by reference
     */
    explicit Menu(App &app);
    /**
     * Class destructor to clear the object in memory
     */
    virtual ~Menu();
    /**
     * Displays the menu in the terminal
     */
    virtual void display()=0;
    /**
     * Gets a menu pointer to the next menu after this one
     * @return menu pointer
     */
    virtual Menu *nextMenu()=0;
    /**
     * Reads an integer number input from the terminal
     * @return integer number read
     */
    int readInt();
    /**
     * Reads a string input from the terminal
     * @return string read
     */
    std::string readStr();
    /**
     * Waits for enter key to be pressed
     */
    void waitForKey();
    /**
     * If there was an invalid input prints a message and returns a pointer the a current menu
     * @return menu pointer
     */
    Menu *invalidInput();
};

class MainMenu: public Menu{
public:
    explicit MainMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class AirportMenu: public Menu{
public:
    explicit AirportMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class PlaneMenu: public Menu{
public:
    explicit PlaneMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class FlightMenu: public Menu{
public:
    explicit FlightMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class EmployeesMenu: public Menu{
public:
    explicit EmployeesMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class PassengerAndBaggageMenu: public Menu{
public:
    explicit PassengerAndBaggageMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class TransportCartMenu: public Menu{
public:
    explicit TransportCartMenu(App &app);
    void display() override;
    Menu *nextMenu() override;
};


class ViewAirports: public Menu{
public:
    explicit ViewAirports(App &app, const std::string& sortedBy = "");
    void display() override;
    Menu *nextMenu() override;
};

class ViewGroundLocals: public Menu{
    std::string sortedBy;
    TransportationLocals locals;
    std::vector<GroundTransportation> locals_vector;
public:
    explicit ViewGroundLocals(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesTODO: public Menu{
    std::string plate;
public:
    explicit ViewServicesTODO(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class ViewServicesDONE: public Menu{
    vector<Service> aux;
    std::string plate;
public:
    explicit ViewServicesDONE(App &app, const std::string& sortedBy = "");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlanes: public Menu{
    int onDuty;
public:
    explicit ViewPlanes(App &app, const std::string& choice="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewPlaneFlights: public Menu{
private:
    std::string plate;
    std::vector<Flight> aux_vector;
public:
    explicit ViewPlaneFlights(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlights: public Menu{
public:
    explicit ViewFlights(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewFlightPassengers: public Menu{
    unsigned int number;
    std::vector<Passenger> aux_vector;
public:
    explicit ViewFlightPassengers(App &app, std::string sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewEmployees: public Menu{
public:
    explicit ViewEmployees(App &app, const std::string& sortedBy="");
    void display() override;
    Menu *nextMenu() override;
};

class ViewSchedules: public Menu{
    GroundTransportation groundTransp;
public:
    explicit ViewSchedules(App &app);
    void display() override;
    Menu *nextMenu() override;
};

class ViewTransportCarts: public Menu{
public:
    explicit ViewTransportCarts(App &app);
    void display() override;
    Menu *nextMenu() override;
};

#endif //PROJETOAEROPORTO_MENU_H
