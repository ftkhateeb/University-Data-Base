#include "student.h"

using namespace std;

void student::setName(string name)
{
   this->name=name;
}

void student::setYear( string year)
{
   this->year=year;
}


void student::setCode (int code)
{
    this->code=code;
}


void student::setDepartment(string department)
{
    this->department=department;
}
string student::getCode()
{
    return code;
}

string student::getName()
{
    return name;
}

string student::getDepartment()
{
    return department;
}



string student::getYear()
{
    return year;
}

