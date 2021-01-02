#include "staffmembers.h"

using namespace std;

staffmembers::staffmembers()
:department({"Structure","Irrigation","public works","Architecture"
                        ,"Urban Design and Planning","Power and Electrical Communication","Computer"
                        ,"Mechatronics","Mechanical Power","Automotive","Design and Production"
                       })
,Title( {"Demonstrator","Teaching Assistant","Teacher","Assistant professor","Professor" })
{
}
void staffmembers::loadStaff()
{
    ifstream loadData("DatabaseStaff.csv");
    string templine;

    if(!loadData.is_open())
    {
        cout << "Cannot open the File"<< endl ;
    }
    else
    {
        while(!loadData.eof())
        {
            getline(loadData,templine);
            istringstream ss(templine);
            string tempword;
            while(getline(ss, tempword,';'))
            {
                cout << tempword << "\t\t";
            }
            cout<<"\n";
        }

    }
    loadData.close();
}

void staffmembers::addStaff()
{

    string tempName;
    string tempDepartment;
    string tempTitle;

    bool check=1;
    // Name Insertion
    cout <<"Enter the name \n";
    cin.ignore();
    getline(cin,tempName);
    // Department
    while(check)
    {

        cout <<"\n Enter the department form the following list \n";
        displayArray(11,department,"\n");
        int ch;
        cin>>ch;

        //While the input entered is not an integer, prompt the user to enter an integer.
        while(!cin)
        {
            cout << "That was no integer! Please enter an integer: ";
            cin.clear();
            cin.ignore();
            cin >> ch;
        }
        if (ch<=10&& ch>=0)
        {
            check=0;
            cout<<"it's Ok\n";
            tempDepartment = department[ch];
        }
        else
        {
            cout<<"not defined answer ";
        }
    }
    // Title
    check =1;
    while(check)
    {

        cout <<"\n Enter the title of the member from the following list \n";
        displayArray(6,Title,"\n");

        int ch;
        cin>>ch;

        //While the input entered is not an integer, prompt the user to enter an integer.
        while(!cin)
        {
            cout << "That was no integer! Please enter an integer: ";
            cin.clear();
            cin.ignore();
            cin >> ch;
        }
        if (ch<=4&& ch>=0)
        {
            check=0;
            cout<<"it's Ok\n";
            tempTitle = Title[ch];
        }
        else
        {
            cout<<"not defined answer ";
        }

    }

    cout<<tempName<<"\t"<<tempDepartment<<"\t"<<tempTitle;
    char cont;
    string lline;
    string notused;
aa:
    cout<<"\nDo you want to save to the database ?(y|n)\n";
    cin>>cont;
    switch (cont)
    {
    case 'n':
    {
        //return to the menu
        cout<<"Okay \n";
        break;
    }
    case 'y':
    {
        ofstream loadData("DatabaseStaff.csv",ios::app);
        if(!loadData.is_open())
        {
            cout << "Cannot open the File"<< endl;
        }
        else
        {
            loadData<<"\n"<<tempName<<';'<<tempDepartment<<';'<<tempTitle;
        }
        loadData.close();
        break;
    }

    default:
    {
        cout<<"answer is not defined,Try Again\n";
        goto aa;
        break;
    }
    }
}

void staffmembers::SearchStaff()
{
    string searchName;
    string line;
    string nameline;
    string resultArray[20];
    int counter=0;
    cout<<"Enter the Name or the code you want \n";
    cin.ignore();
    getline(cin,searchName);
    ifstream file("DatabaseStaff.csv");
    if(!file.is_open())
    {
        cout<<"Error Cannot open file";
    }
    else
    {
        while(!file.eof())
        {
            getline(file,line);
            istringstream ss(line);
            string fieldName;
            getline(ss,fieldName,';');

            if(fieldName.find(searchName) != std::string::npos)
            {
                resultArray[counter]=line;
                counter++;
            }
        }
        file.close();
        if(counter<=0)
        {
            cout<<"No results!\n";
        }
        else
        {
            cout<<"The results are :\n";
            displayArray(counter,resultArray,"\n");
        }
    }

}

void staffmembers::removeData()
{

    int index;
    string searchName;
    string line;
    string resultArray[20];
    int counter=0;
    string tempword;
    cout<<"Enter the Name you want to remove \n";
    cin.ignore();
    getline(cin,searchName);
    ifstream file("DatabaseStaff.csv");
    if(!file.is_open())
    {
        cout<<"Error Cannot open file";
    }
    else
    {
        while(!file.eof())
        {
            getline(file,line);
            if(line.find(searchName) != std::string::npos)
            {
                resultArray[counter]=line;
                counter++;
            }
        }
        file.close();
    }
    if(counter<=0)
    {
        cout<<"No results!\n";
    }
    else
    {
        cout<<"choose the index of the data you want to remove : \n ";
        displayArray(counter,resultArray,"\n");
        cin>>index;
        //While the input entered is not an integer, prompt the user to enter an integer.
        while(!cin)
        {
            cout << "That was no integer! Please enter an integer: ";
            cin.clear();
            cin.ignore();
            cin >> index;
        }
        string removedline=resultArray[index];
        ifstream data("DatabaseStaff.csv");
        ofstream temp("tempStaff.csv");
        if(!data.is_open())
        {
            cout<<"Error Cannot open file!\n";
        }
        else
        {
            while(!data.eof())
            {
                getline(data,line);
                if(line.find(removedline) != std::string::npos) {}
                else
                {
                    temp<<line<<"\n";

                }
            }
        }
        temp.close();

        data.close();
mm:
        cout<<"\n Are you sure that you want to remove (y|n) \n";
        /*while(getline(removedline,tempword,';')) {
                    cout << tempword << "\t\t";
                }
                cout<<"\n";*/
        char ask;
        cin>>ask;
        if(ask=='y'||ask=='Y')
        {
            string student_db=("DatabaseStaff.csv");
            const char* p = student_db.c_str();
            remove(p);
            rename("tempStaff.csv",p);
        }
        else if (ask=='n'||ask=='N')
        {
            cout<<"wala yehemmk\n";
        }
        else
        {
            cout<<"NOt defined Input\n";
            goto mm;
        }
    }
}

void staffmembers::Modify()
    {
        int index;
        string searchName;
        string line;
        string resultArray[20];
        int counter=0;
        string tempword;
        cout<<"Enter the Name you want to Modify \n";
        cin.ignore();
        getline(cin,searchName);
        ifstream file("DatabaseStaff.csv");
        if(!file.is_open())
        {
            cout<<"Error Cannot open file";
        }
        else
        {
            while(!file.eof())
            {
                getline(file,line);
                if(line.find(searchName) != std::string::npos)
                {
                    resultArray[counter]=line;
                    counter++;
                }
            }
            file.close();
        }
        if(counter<=0)
        {
            cout<<"No results!\n";
        }
        else
        {
            cout<<"choose the data you want to modify : \n";
            displayArray(counter,resultArray,"\n");
            cin>>index;
            //While the input entered is not an integer, prompt the user to enter an integer.
            while(!cin)
            {
                cout << "That was no integer! Please enter an integer: ";
                cin.clear();
                cin.ignore();
                cin >> index;
            }
            string removedline=resultArray[index];
            ifstream data("DatabaseStaff.csv");
            ofstream temp("tempStaff.csv");
            if(!data.is_open())
            {
                cout<<"Error Cannot open file!\n";
            }
            else
            {
                while(!data.eof())
                {
                    getline(data,line);
                    if(line.find(removedline) != std::string::npos)
                    {
                        string tempName;
                        string tempCode;
                        string tempDepartment;
                        string tempTitle;

                        bool check=1;
                        // Name Insertion
                        cout <<"Enter the name \n";
                        cin.ignore();
                        getline(cin,tempName);
                        // Department
                        while(check)
                        {

                            cout <<"\n Enter the department form the following list \n";
                            displayArray(11,department,"\n");
                            int ch;
                            cin>>ch;

                            //While the input entered is not an integer, prompt the user to enter an integer.
                            while(!cin)
                            {
                                cout << "That was no integer! Please enter an integer: ";
                                cin.clear();
                                cin.ignore();
                                cin >> ch;
                            }
                            if (ch<=10&& ch>=0)
                            {
                                check=0;
                                cout<<"it's Ok\n";
                                tempDepartment = department[ch];
                            }
                            else
                            {
                                cout<<"not defined answer ";
                            }
                        }
                        // Title
                        check =1;
                        while(check)
                        {

                            cout <<"\n Enter the title of the member from the following list \n";
                            displayArray(6,Title,"\n");

                            int ch;
                            cin>>ch;

                            //While the input entered is not an integer, prompt the user to enter an integer.
                            while(!cin)
                            {
                                cout << "That was no integer! Please enter an integer: ";
                                cin.clear();
                                cin.ignore();
                                cin >> ch;
                            }

                            if (ch<=4&& ch>=0)
                            {
                                check=0;
                                cout<<"it's Ok\n";
                                tempTitle = Title[ch];
                            }
                            else
                            {
                                cout<<"not defined answer ";
                            }

                        }

                        cout<<tempName<<"\t"<<tempDepartment<<"\t"<<tempTitle;
                        char cont;
                        string lline;
                        string notused;
aa:
                        cout<<"\nDo you want to save to the database ?(y|n)\n";
                        cin>>cont;
                        switch (cont)
                        {
                        case 'n':
                        {
                            //return to the menu
                            cout<<"Okay \n";
                            break;
                        }
                        case 'y':
                        {
                            temp<<tempName<<';'<<tempDepartment<<';'<<tempTitle<<endl;

                            break;
                        }

                        default:
                        {
                            cout<<"answer is not defined,Try Again\n";
                            goto aa;
                            break;
                        }
                        }
                    }
                    else
                    {
                        temp<<line<<"\n";

                    }
                }
            }
            temp.close();

            data.close();
mm:
            cout<<"\n Are you sure that you want to modify (y|n) \n";

            char ask;
            cin>>ask;
            if(ask=='y'||ask=='Y')
            {
                string student_db=("DatabaseStaff.csv");
                const char* p = student_db.c_str();
                remove(p);
                rename("tempStaff.csv",p);
            }
            else if (ask=='n'||ask=='N')
            {
                cout<<"wala yehemmk\n";
            }
            else
            {
                cout<<"NOt defined Input\n";
                goto mm;
            }
        }
    }
