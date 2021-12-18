#include "../include/AppStarter.h"

AppStarter::AppStarter() {
    app.loadData();
    menuStack.push(new MainMenu(app));
}

void AppStarter::start() {
    while (!menuStack.empty()) {
        menuStack.top()->display();
        Menu *nextMenu = menuStack.top()->nextMenu();
        if (nextMenu){
            if (nextMenu != menuStack.top()){
                menuStack.push(nextMenu);
            }
        }
        else {
            delete menuStack.top();
            menuStack.pop();
        }
    }
    app.saveData();
}
