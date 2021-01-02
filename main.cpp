#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "student.h"
#include "students.h"
#include "HelperFunctions.h"
#include "staff.h"
#include "staffmembers.h"

using namespace std;

int main()
{
    cout<<"Choose the database to work with \n(1:student or 2:Stuff)\n\n";
    char d;
    cin>>d;
    if(d=='1')
    {
        // STUDENT DATABASE
        char choice;
        students  s;
zz:
        cout<<"Choose the operation you want to do\n (1-load,2-add,3-search,4-remove,5-Modify)\n";
        cin>>choice;
        switch (choice)
        {
        case '1':
            s.loadStudents();
            goto zz;
            break;
        case '2':
            s.addStudent();
            goto zz;
            break;
        case '3':
            s.SearchStudentName();
            goto zz;
            break;
        case '4':
            s.removeData();
            goto zz;
            break;
        case '5':
            s.Modify();
            goto zz;
            break;
        default:
            cout<<"Error plz Try Again by entering the the index ";
            goto zz;
            break;
        }
    }
    else if (d=='2')
    {
        //Stuff DB
        char choice;
        staffmembers  a;
bb:
        cout<<"Choose the operation you want to do\n (1-load,2-add,3-search,4-remove,5-Modify)\n";
        cin>>choice;
        switch (choice)
        {
        case '1':
            a.loadStaff();
            goto bb;
            break;
        case '2':
            a.addStaff();
            goto bb;
            break;
        case '3':
            a.SearchStaff();
            goto bb;
            break;
        case '4':
            a.removeData();
            goto bb;
            break;
        case '5':
            a.Modify();
            goto bb;
            break;
        default:
            cout<<"Error plz Try Again by entering the the index ";
            goto bb;
            break;

        }

    }
    return 0;
}
