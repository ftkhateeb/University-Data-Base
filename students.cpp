#include "students.h"
#include "student.h"
#include "HelperFunctions.h"

using namespace std;

students::students()
:department({"Structure","Irrigation","public works","Architecture"
            ,"Urban Design and Planning","Power and Electrical Communication","Computer"
            ,"Mechatronics","Mechanical Power","Automotive","Design and Production"})
,year({"Freshmen","Sophomore","Junior","Senior I","Senior II"})

{

}
void students::addStudent()
{
  string tempName;
                string tempCode;
                string tempDepartment;
                string tempYear;

                bool check=1;
        // Name Insertion
            cout <<"Enter the name of the student \n";
            cin.ignore();
            getline(cin,tempName);
        // Department
            while(check){

            cout <<"\n Enter the department of the student form the following list \n";
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
            if (ch<=10&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempDepartment = department[ch];
            }else {
            cout<<"not defined answer ";
            }


                    /*for(int i=0;i<11;i++){
            string Str = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
                        if(tempDepartment==department[i]){
                            check=0;
                            cout << "It's Ok \n";
                        }else if(tempDepartment.find(Str) != std::string::npos){
                                check=0;
                                cout<<"It's ok\n";
                                tempDepartment =department[i];
                             }else if(i>=10&& check==1){
                            cout<<"\n\n Try Again \n";
                             }  }*/}
        // Year
                check =1;
            while(check){

            cout <<"\n Enter the year of the student \n";
            displayArray(5,year,"\n");
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
            if (ch<=4&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempYear = year[ch];
            }else {
            cout<<"not defined answer ";
            }
                    }
            //set code
            tempCode = generateCode(tempDepartment);
            cout<<tempName<<"\t"<<tempCode<<"\t"<<tempDepartment<<"\t"<<tempYear;
            char cont;
            string lline;
            string notused;
            aa:
            cout<<"\nDo you want to save to the database ?(y|n)\n";
            cin>>cont;
            switch (cont){
        case 'n':
            {//return to the menu
            cout<<"leeh keda \n";
            break;}
        case 'y':
            {

            ofstream loadData("Database.csv",ios::app);
             if(!loadData.is_open()) {  cout << "Cannot open the File"<< endl ; }
            else {  loadData<<"\n"<<tempName<<';'<<tempCode<<';'<<tempDepartment<<';'<<tempYear; }
            loadData.close();
            break;}

        default:
            {cout<<"answer is not defined,Try Again\n";
            goto aa;
            break;}
            }
}

void students::loadStudents()
{
fstream loadData("Database.csv");
                string templine;

            if(!loadData.is_open()) {  cout << "Cannot open the File"<< endl ; }
            else {
                while(!loadData.eof()){
                        getline(loadData,templine);
                        istringstream ss(templine);
                        string tempword;
                    while(getline(ss, tempword,';')) {
                            cout << tempword << "\t\t";
                        }
                        cout<<"\n";
                    }

                  }loadData.close();
}

void students::Modify()
{
int index;
        string searchName;
        string line;
        string resultArray[20];
        int counter=0;
        string tempword;
        cout<<"Enter the Name or the code you want to Modify \n";
        cin.ignore();
        getline(cin,searchName);
        ifstream file("Database.csv");
        if(!file.is_open()){ cout<<"Error Cannot open file"; }else{
            while(!file.eof()){
                getline(file,line);
                if(line.find(searchName) != std::string::npos){
                    resultArray[counter]=line;
                    counter++;
                }
            }file.close();}
            if(counter<=0){cout<<"No results!\n"; }else{
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
        ifstream data("Database.csv");
        ofstream temp("temp.csv");
        if(!data.is_open()){cout<<"Error Cannot open file!\n";}else{
            while(!data.eof()){
                getline(data,line);
                if(line.find(removedline) != std::string::npos){
string tempName;
                string tempCode;
                string tempDepartment;
                string tempYear;

                bool check=1;
        // Name Insertion
            cout <<"Enter the name of the student \n";
            cin.ignore();
            getline(cin,tempName);
        // Department
            while(check){

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
            if (ch<=10&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempDepartment = department[ch];
            }else {
            cout<<"not defined answer ";
            } }
        // Year
                check =1;
            while(check){

            cout <<"\n Enter the year of the student \n";
            displayArray(5,year,"\n");
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
            if (ch<=4&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempYear = year[ch];
            }else {
            cout<<"not defined answer ";
            }
                    }
            //set code
            tempCode = generateCode(tempDepartment);
            cout<<tempName<<"\t"<<tempCode<<"\t"<<tempDepartment<<"\t"<<tempYear;
            char cont;
            string lline;
            string notused;
            aa:
            cout<<"\nDo you want to save to the database ?(y|n)\n";
            cin>>cont;
            switch (cont){
        case 'n':
            {//return to the menu
            cout<<"leeh keda \n";
            break;}
        case 'y':
            {
        temp<<tempName<<';'<<tempCode<<';'<<tempDepartment<<';'<<tempYear<<endl;

            break;}

        default:
            {cout<<"answer is not defined,Try Again\n";
            goto aa;
            break;}
            }
                }else {
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
                if(ask=='y'||ask=='Y'){
                string student_db=("Database.csv");
                     const char* p = student_db.c_str();
                     remove(p);
                     rename("temp.csv",p);
                }else if (ask=='n'||ask=='N'){
                cout<<"wala yehemmk\n";
                }else{
                cout<<"NOt defined Input\n";
                goto mm;
                }
        }
}
void students::removeData()
{
int index;
        string searchName;
        string line;
        string resultArray[20];
        int counter=0;
        string tempword;
        cout<<"Enter the Name or the code you want to remove \n";
        cin.ignore();
        getline(cin,searchName);
        ifstream file("Database.csv");
        if(!file.is_open()){ cout<<"Error Cannot open file"; }else{
            while(!file.eof()){
                getline(file,line);
                if(line.find(searchName) != std::string::npos){
                    resultArray[counter]=line;
                    counter++;
                }
            }file.close();}
            if(counter<=0){cout<<"No results!\n"; }else{
            cout<<"choose the data you want to remove : \n";
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
        ifstream data("Database.csv");
        ofstream temp("temp.csv");
        if(!data.is_open()){cout<<"Error Cannot open file!\n";}else{
            while(!data.eof()){
                getline(data,line);
                if(line.find(removedline) != std::string::npos){}else {
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
                if(ask=='y'||ask=='Y'){
                string student_db=("Database.csv");
                     const char* p = student_db.c_str();
                     remove(p);
                     rename("temp.csv",p);
                }else if (ask=='n'||ask=='N'){
                cout<<"wala yehemmk\n";
                }else{
                cout<<"NOt defined Input\n";
                goto mm;
                }
        }
}
void students::SearchStudentName()
{
        string searchName;
        string line;
        string resultArray[20];
        int counter=0;
        cout<<"Enter the Name or the code you want \n";
        cin.ignore();
        getline(cin,searchName);
        ifstream file("Database.csv");
        if(!file.is_open()){ cout<<"Error Cannot open file"; }else{
            while(!file.eof()){
                getline(file,line);
                if(line.find(searchName) != std::string::npos){
                    resultArray[counter]=line;
                    counter++;
                }
            }file.close();
            if(counter<=0){cout<<"No results!\n"; }else{
            cout<<"The results are :\n";
            displayArray(counter,resultArray,"\n");
            }
        }
}
