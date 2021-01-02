#include "HelperFunctions.h"

using  namespace std;
string generateCode (string Department)
{
    string read;
    int intCode;
    string newCode;
    ifstream getNumber("code.txt");
    if(!getNumber.is_open())
    {
        cout << "Error Cannot open the File"<< endl ;
    }
    else
    {
        getNumber>>read;
        stringstream strCode (read);
        strCode>>intCode;
        newCode=Department.substr(0,2)+"00"+read;
        intCode++;
    }
    getNumber.close();
    ofstream setNewNumber("code.txt");
    setNewNumber<<intCode;
    setNewNumber.close();
    return newCode;

}
void displayArray(int size,string arr[],string spacer)
{
    for(int i=0; i<size; i++)
    {
        cout<<i<<"\t"<<arr[i]<<spacer;
    }
}
