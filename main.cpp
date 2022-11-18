#include "manager.h"
#include "person.h"
#include "employee.h"
#include <iostream>
#include <fstream>
#include "department.h"

using namespace std;

int maxNumberOfEmployees();
double amountOfProductsUsed();
void menu();
char ErrorCheckUserInput();
int askForUserInput(string output,int lowerBound,int upperBound);



int main(){
    cout<<"Collin McDevitt Lab 7 CSCN 112 \n";
    cout<<"What is the name of the department ?:";
    string nameOfDepartment;
    getline(cin>>ws,nameOfDepartment);
    double ammountOfProducts=amountOfProductsUsed();
    int maxNumbeOfEmployees=maxNumberOfEmployees();
    department departmentObj(nameOfDepartment,ammountOfProducts,maxNumbeOfEmployees);

    while(true)
    {   menu();
        char userChoice=ErrorCheckUserInput();
        if(userChoice=='M'){
            departmentObj.createNewManager();
        }
        if(userChoice=='E'){
            if(departmentObj.getMaxEmployees()>departmentObj.getSizeOfVector())
            {
                departmentObj.vectorOfEmployeesPushBack(departmentObj.createNewEmployee());
            }else   {
                cout<<"Max number of employees reached\n";
                    }
                }
        if(userChoice=='R'){
            if(departmentObj.getSizeOfVector()>0){
            int employeeId=askForUserInput("Enter the employee ID of the employee you want to remove",1,departmentObj.getSizeOfVector());
            departmentObj.removeEmployee(employeeId-1);
            departmentObj.sortVectorOfEmployees();}
            else{
                cout<<"No employees to remove\n";
            }
            }
        if(userChoice=='L'){
            if(departmentObj.getSizeOfVector()>1) departmentObj.sortVectorOfEmployees();
            departmentObj.printDepartmentInfo();
        }
        if(userChoice=='P'){
            departmentObj.printFinalProfit();
            break;
        }
        

    }


    return 0;
}









int maxNumberOfEmployees(){
    int maxNumOfEmployees;
    while(true){
        cout<<"Please enter the maximum number of employees: Has to be less then 50 ";
        cin>>maxNumOfEmployees;
        if(maxNumOfEmployees>50 || maxNumOfEmployees<0|| cin.fail()){
            cout<<"Please enter a number less then 50: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else{
            break;
        }
    }
    return maxNumOfEmployees;
}
double amountOfProductsUsed(){
    double ammountOfProducts;
    while(true){
        cout<<"Please enter the dollar amount that this department spent on products: ";
        cin>>ammountOfProducts;
        if(ammountOfProducts>0 &&ammountOfProducts<1000000000 && !cin.fail()){
            break;
        }
        else{
            cout<<"Please enter a number between 0 and 1000000000: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    return ammountOfProducts;
}
void menu()
{
cout<<"     Main Menu\n";
cout<<" M--Add Manager\n";
cout<<" E--Add Employee\n";
cout<<" R--Remove Employee\n";
cout<<" L--List Department Info\n";
cout<<" P--Print Final Profit\n";

}
char ErrorCheckUserInput()
{
    char userInput;
    while(true)
    {   cout<<"Please enter a single character...ex 'M','E': \n";

        cin>>userInput;
        if(userInput=='M'||userInput=='E'||userInput=='R'||userInput=='L'||userInput=='P' && !cin.fail())
        {
            break;
        }
        else
        {
            cout<<"Invalid input... \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

    }
    return userInput;
}
int askForUserInput(string output,int lowerBound,int upperBound)
{
    int userChoice;
while(true)
{
    cout<<output+"\n";
    cin>>userChoice;
    if(userChoice>=lowerBound && userChoice<=upperBound && !cin.fail())
    {
        break;
    }
    else
    {
        cout<<"Invalid input please enter a number between "<<lowerBound<<" and "<<upperBound<<"\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

}

return userChoice;

}
