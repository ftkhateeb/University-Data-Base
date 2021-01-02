#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "student.h"

using namespace std;
string generateCode (string Department){
    string read;
    int intCode;
    string newCode;
    ifstream getNumber("code.txt");
    if(!getNumber.is_open()) {  cout << "Error Cannot open the File"<< endl ; }
    else { getNumber>>read;
            stringstream strCode (read);
            strCode>>intCode;
            newCode=Department.substr(0,2)+"00"+read;
            intCode++;
            }getNumber.close();
    ofstream setNewNumber("code.txt");
    setNewNumber<<intCode;
    setNewNumber.close();
    return newCode;

}
void displayArray(int size,string arr[],string spacer){
    for(int i=0;i<size;i++){
        cout<<i<<"\t"<<arr[i]<<spacer;
    }
}
/*
class student{
        private:
            string name;
            string code;
            string department;
            string year;

        public:

            void setName(string name){
                this->name=name;
            }
            void setDepartment(string department){
                this->department=department;
            }
            void setCode(int code){
                this->code=code;
            }
            void setYear(string year){
                this->year=year;
            }
            string getName(){ return name;}
            string getDepartment(){return department;}
            string getCode(){return code;}
            string getYear(){return year;}

};

*/
class students {
        private:
            student studentsArray[50];
            string department[11]={"Structure","Irrigation","public works","Architecture"
            ,"Urban Design and Planning","Power and Electrical Communication","Computer"
            ,"Mechatronics","Mechanical Power","Automotive","Design and Production"};
            string year[5]={"Freshmen","Sophomore","Junior","Senior I","Senior II"};

        public :
    void loadStudents(){
                ifstream loadData("Database.csv");
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
    void addStudent(){

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
    void SearchStudentName(){
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
    void removeData(){

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
        }}
   void Modify(){int index;
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
        }}

};

class staff{
        private:
            string name;
            string Title;
            string department;


        public:

            void setName(string name){
                this->name=name;
            }
            void setDepartment(string department){
                this->department=department;
            }
            void setTitle(string Title){
                this->Title=Title;
            }
            string getName(){ return name;}
            string getDepartment(){return department;}
            string getTitle(){return Title;}

};


class staffmembers {
        private:

            string department[13]={"Structure","Irrigation","public works","Architecture"
            ,"Urban Design and Planning","Power and Electrical Communication","Computer"
            ,"Mechatronics","Mechanical Power","Automotive","Design and Production"};
            string Title[6]={"Demonstrator","Teaching Assistant","Teacher","Assistant professor","Professor" };

        public :
    void loadStaff(){
                ifstream loadData("DatabaseStaff.csv");
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
    void addStaff(){

                string tempName;
                string tempDepartment;
                string tempTitle;

                bool check=1;
        // Name Insertion
            cout <<"Enter the name \n";
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
        // Title
                check =1;
            while(check){

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
            if (ch<=4&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempTitle = Title[ch];
            }else {
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
            switch (cont){
        case 'n':
            {//return to the menu
            cout<<"Okay \n";
            break;}
        case 'y':
            {
        ofstream loadData("DatabaseStaff.csv",ios::app);
             if(!loadData.is_open()) {  cout << "Cannot open the File"<< endl; }
            else {  loadData<<"\n"<<tempName<<';'<<tempDepartment<<';'<<tempTitle; }
            loadData.close();
            break;}

        default:
            {cout<<"answer is not defined,Try Again\n";
            goto aa;
            break;}
            }





}
    void SearchStaff(){
        string searchName;
        string line;
		string nameline;
        string resultArray[20];
        int counter=0;
        cout<<"Enter the Name or the code you want \n";
        cin.ignore();
        getline(cin,searchName);
        ifstream file("DatabaseStaff.csv");
        if(!file.is_open()){ cout<<"Error Cannot open file"; }else{
            while(!file.eof()){
                getline(file,line);
                    istringstream ss(line);
                    string fieldName;
                    getline(ss,fieldName,';');

                if(fieldName.find(searchName) != std::string::npos){
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
    void removeData(){

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
        if(!file.is_open()){ cout<<"Error Cannot open file"; }else{
            while(!file.eof()){
                getline(file,line);
                if(line.find(searchName) != std::string::npos){
                    resultArray[counter]=line;
                    counter++;
                }
            }file.close();}
            if(counter<=0){cout<<"No results!\n"; }else{
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
                string student_db=("DatabaseStaff.csv");
                     const char* p = student_db.c_str();
                     remove(p);
                     rename("tempStaff.csv",p);
                }else if (ask=='n'||ask=='N'){
                cout<<"wala yehemmk\n";
                }else{
                cout<<"NOt defined Input\n";
                goto mm;
                }
        }}
   void Modify(){
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
        ifstream data("DatabaseStaff.csv");
        ofstream temp("tempStaff.csv");
        if(!data.is_open()){cout<<"Error Cannot open file!\n";}else{
            while(!data.eof()){
                getline(data,line);
                if(line.find(removedline) != std::string::npos){
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
        // Title
                check =1;
            while(check){

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

            if (ch<=4&& ch>=0){
                check=0;
                cout<<"it's Ok\n";
                tempTitle = Title[ch];
            }else {
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
            switch (cont){
        case 'n':
            {//return to the menu
            cout<<"Okay \n";
            break;}
        case 'y':
            {
        temp<<tempName<<';'<<tempDepartment<<';'<<tempTitle<<endl;

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
                string student_db=("DatabaseStaff.csv");
                     const char* p = student_db.c_str();
                     remove(p);
                     rename("tempStaff.csv",p);
                }else if (ask=='n'||ask=='N'){
                cout<<"wala yehemmk\n";
                }else{
                cout<<"NOt defined Input\n";
                goto mm;
                }
        }}

};





int main()
{
    cout<<"Choose the database to work with \n(1:student or 2:Stuff)\n\n";
    char d;
    cin>>d;
    if(d=='1'){
            // STUDENT DATABASE
               char choice;
            students  s;
            zz:
            cout<<"Choose the operation you want to do\n (1-load,2-add,3-search,4-remove,5-Modify)\n";
            cin>>choice;
            switch (choice){
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
    }}else if (d=='2'){
                //Stuff DB
                char choice;
            staffmembers  a;
            bb:
                cout<<"Choose the operation you want to do\n (1-load,2-add,3-search,4-remove,5-Modify)\n";
            cin>>choice;
            switch (choice){
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
