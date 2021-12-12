#include <iostream>
#include "Schedule.h"
#include "Flight.h"
unsigned int Flight::numberBaggages = 0;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Schedule h1 = Schedule("11:02");
    Schedule h2 = Schedule("01:02");
    Schedule h3 = Schedule("21:23");
    h1.displayTime();
    std::cout << std::endl;
    h2.displayTime();
    std::cout << std::endl;
    h3.displayTime();
    std::cout << std::endl;
    if (h1 < h2){
        std::cout << "h2 > h1" << std::endl;
        std::cout << h2.getHour() << ":" << h2.getMin() << std::endl;

    }
    else if (h1 < h3){
        std::cout << "h3 > h1" << std::endl;
        std::cout << h3.getHour() << ":" << h3.getMin() << std::endl;
    }
    return 0;
}
