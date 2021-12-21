//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_PERSON_H
#define PROJETOAEROPORTO_PERSON_H

#include <string>
#include <sstream>
#include <iomanip>

class Person {
protected:
    unsigned int id;
    std::string name;
    static unsigned int ID; /** static id variable to give automatically an id to each person  */
public:
    /**
     * Deafult class constructor
     */
    Person();
    /**
     * Class constructor with passenger's name
     * @param name name string
     */
    Person(std::string name);
    virtual std::string getName() const;
    virtual unsigned int getId() const;
    /**
     * Checks if this person is the same as another one based on their id
     * @param person person object passed by reference
     * @return true if they have the same id or false otherwise
     */
    virtual bool operator==(const Person& person) const;
};


#endif //PROJETOAEROPORTO_PERSON_H
