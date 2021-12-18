//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_BAGGAGE_H
#define PROJETOAEROPORTO_BAGGAGE_H
#include <string>
#include <sstream>

class Baggage {
private:
    unsigned int id;
    int MAX_WEIGHT = 25;
    int weight;
    bool overweight;
    static unsigned int ID;

public:
    Baggage();
    Baggage(int weight);
    unsigned int getId() const;
    int getWeight() const;
    void setWeight(double weight);
    bool isOverweight() const;
    void checkWeight();
    bool operator==(const Baggage &baggage) const;
    friend std::ostream& operator<<(std::ostream& os, const Baggage &baggage);
};


#endif //PROJETOAEROPORTO_BAGGAGE_H
