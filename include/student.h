#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class student
{
    public:
          void setName(string );
          void setDepartment(string );
          void setCode(int );
          void setYear(string );
          string getName();
          string getDepartment();
          string getCode();
          string getYear();


    protected:

    private:
            string name;
            string code;
            string department;
            string year;
};

#endif // STUDENT_H
