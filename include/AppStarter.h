#ifndef PROJETOAEROPORTO_APPSTARTER_H
#define PROJETOAEROPORTO_APPSTARTER_H

#include "Menu.h"

class AppStarter {
    App app;
    stack<Menu*> menuStack;
public:
    AppStarter();
    void start();
};


#endif //PROJETOAEROPORTO_APPSTARTER_H
