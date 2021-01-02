#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "HelperFunctions.h"

class staff
{
    public:
    staff();
    void setName(string name);
    void setDepartment(string department);
    void setTitle(string Title);
    string getName();
    string getDepartment();
    string getTitle();


    private:
    string name;
    string Title;
    string department;
};

#endif // STAFF_H
