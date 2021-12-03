//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_BAGGAGE_H
#define PROJETOAEROPORTO_BAGGAGE_H
#include <string>

using namespace std;

class Baggage {
private:
    double weight;
    const double MAXWEIGHT = 25;
    bool special;
    bool overweight;
public:
    Baggage();
    Baggage(double weight, bool special);
    double getWeight();
    void setWeight(double weight);
    bool isSpecial();
    void setSpecial(bool special);
    bool isOverweight();
    void checkWeight();
};


#endif //PROJETOAEROPORTO_BAGGAGE_H
