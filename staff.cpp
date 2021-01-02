#include "staff.h"

using namespace std;

staff::staff()
{
    //ctor
}
void staff::setName(string name)
{
    this->name=name;
}
void staff::setDepartment(string department)
{
    this->department=department;
}
void staff::setTitle(string Title)
{
    this->Title=Title;
}
string staff::getName()
{
    return name;
}
string staff::getDepartment()
{
    return department;
}
string staff::getTitle()
{
    return Title;
}
