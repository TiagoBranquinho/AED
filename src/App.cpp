#include "../include/App.h"

using namespace std;

App::App() {
    loadData();
    menuStack.push(new MainMenu());
}

App::~App() {
    saveData();
}

void App::start() {
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
}

void App::loadData() {
    for (const string& file : files.names){
        readFile(file);
    }
}

void App::saveData() {
    for (const string& file : files.names){
        writeFile(file);
    }
}

void App::readFile(string filename) {
    string dataFolder = "../data/";
    string line;
    fstream f(filename);
    while (getline(f,line)){
        cout << line << endl;
    }
}

void App::writeFile(std::string filename) {

}