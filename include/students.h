#ifndef STUDENTS_H
#define STUDENTS_H
#include "student.h"

using namespace std;

class students
{
    public:
         students();
        void loadStudents();
        void addStudent();
        void SearchStudentName();
        void removeData();
        void Modify();

    private:

            student studentsArray[50]; // to be modified to be implemented by a vector -Ahmed ELkhateeb
            string department[11];
            string year[5];

};

#endif // STUDENTS_H
