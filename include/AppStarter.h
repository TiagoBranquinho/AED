#ifndef PROJETOAEROPORTO_APPSTARTER_H
#define PROJETOAEROPORTO_APPSTARTER_H

#include "Menu.h"

class AppStarter {
    App app;
    stack<Menu*> menuStack;
public:
    /**
     * Default class constructor that pushes the main menu to the menuStack
     */
    AppStarter();
    /**
     * Starts the application loop and call the App methods to load and save data to files
     */
    void start();
};


#endif //PROJETOAEROPORTO_APPSTARTER_H
