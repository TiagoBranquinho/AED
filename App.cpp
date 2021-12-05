#include "App.h"
#include "Plane.h"

using namespace std;

App::App() {
    loadData();
}

void App::start() {
    int opt;
    while (true) {
        displayMenu();
        opt = readInput();
        if (chooseOpt(opt)) break;
    }
}

void App::displayMenu() {
    cout << endl;
    cout << "Options:" << endl;
    cout << "1 - View data" << endl;
    cout << "2 - Add data" << endl;
    cout << "3 - Exit" << endl;
    cout << endl;
}

void App::loadData() {
    for (const auto &file : filesPath){
        load("../data/"+file);
    }
}

void App::load(string filename) {
    string line;
    fstream f(filename);
    while (getline(f,line)){
        cout << line << endl;
    }
}

int App::readInput() {
    int opt;
    while (true){
        cin >> opt;
        if(!cin.fail() && cin.peek()=='\n') break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return opt;
}

bool App::chooseOpt(int opt) {
    switch (opt) {
        case 1:
            cout << opt;
            return false;
        case 2:
            cout << opt;
            return false;
        case 3:
            cout << opt;
            return true;
        default:
            return false;

    }
}
