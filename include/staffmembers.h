#ifndef STAFFMEMBERS_H
#define STAFFMEMBERS_H

#include "staff.h"

class staffmembers
{
    public:
        staffmembers();
        void loadStaff();
        void addStaff();
        void SearchStaff();
        void removeData();
        void Modify();



    private:

    string department[13];
    string Title[6];
};

#endif // STAFFMEMBERS_H
