#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../include/Employee.h"

using namespace std;
using testing::Eq;

TEST(test_1, createEmp){
    Employee emp1("entio", "cleaner");
    Employee emp2("jose", "mechanic");
    Employee emp3("antoni", "cleaner");
    Employee emp4("maria", "cleaner");
    vector<Employee> emps = {emp1, emp2, emp3, emp4};

    bool done = false;
    unsigned int id = 2;

    auto rm = find_if(emps.begin(), emps.end(),
            [&id](const Employee &emp){return emp.getId() == id;});
    if (rm != emps.end()) emps.erase(rm);
    /*for (const Employee& employee : emps) {
        if (employee.getId() == id) {
            std::remove(emps.begin(), emps.end(), employee);
            done = true;
            break;
        }
    }*/

    /*auto rm = remove_if(emps.begin(), emps.end(),
                        [&id](Employee &emp){return emp.getId() == id;});*/
    /*if (rm != emps.end()) done = true;*/

    for (auto emp:emps)
        cout << emp.getName() << " " << emp.getId() << endl;

    EXPECT_EQ(emps.size(), 3);
}