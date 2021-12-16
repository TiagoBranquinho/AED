#ifndef PROJETOAEROPORTO_MENU_H
#define PROJETOAEROPORTO_MENU_H


class Menu {
public:
    Menu();
    virtual ~Menu();
    virtual void display()=0;
    virtual Menu *nextMenu()=0;
    int readOpt();
    Menu *invalidInput();
};

class MainMenu: public Menu{
public:
    MainMenu();
    void display() override;
    Menu *nextMenu() override;
};

class AirportMenu: public Menu{
public:
    AirportMenu();
    void display() override;
    Menu *nextMenu() override;
};

class PlaneMenu: public Menu{
public:
    PlaneMenu();
    void display() override;
    Menu *nextMenu() override;
};


#endif //PROJETOAEROPORTO_MENU_H
