#include "manager.h"
#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;

manager::manager() : person()
{

    jobTitle="";
    salary=0.0f;
    promotionDate.setDate(0,0,0000);

}
manager::manager(string jobTitle,double salary,int promotionDay,int promotionMonth,int promotionYear,
                string Fname,string lName,int ID,
                int birthDayD,int birthDayMonth,int birthDayYear,int hirringDay,int hirringMonth,int hirringYear)
:person( Fname, lName, ID,birthDayD, birthDayMonth, birthDayYear, hirringDay, hirringMonth, hirringYear)
{

this->jobTitle=jobTitle;
this->salary=salary;
this->promotionDate.setDate(promotionDay,promotionMonth,promotionYear);
}
void manager::setJobTitle(string jobTitle)
{
this->jobTitle=jobTitle;
}
void manager::setSalary(double salary)
{
    this->salary=salary;
}
void manager::setPromotionDate(int day,int month, int year)
{
    promotionDate.setDate(day,month,year);
}
string manager::getJobTitle() const
{
    return jobTitle;
}

double manager::getSalary() const
{
    return salary;
}
std::ostream & operator <<(std::ostream & out,const manager & localObj)
{
    out<<"Name:"<<std::setw(30)<<std::right<<localObj.getFname()+" "+localObj.getLname()+"\n";
    out<<"Title:"<<std::setw(30)<<std::right<<localObj.getJobTitle()+"\n";
    out<<"Employee ID:"<<std::setw(30)<<std::right<<localObj.getId()<<"\n";
    out<<"Birth Day:"<<std::setw(30)<<std::right<<localObj.birthDay<<"\n";
    out<<"Date Hirred:"<<std::setw(30)<<std::right<<localObj.hirringDate<<"\n";
    out<<"Promotion Date: "<<std::setw(30)<<localObj.promotionDate<<"\n";
    out<<"Salary: "<<std::setw(30)<<std::fixed<<std::setprecision(2)<<localObj.getSalary()<<"\n";
    return out;
}

void manager::askForJobTitle()
{
    std::string jobTitle;
    std::cout<<"Enter the job title: ";
    std::getline(std::cin,jobTitle);
    setJobTitle(jobTitle);
}

void manager::askForSalary()
{//error check and ask for user input 
    double salary=0.0f;
    while(true){
        cout<<"Enter manager Salary: ";
        cin>>salary;
        if(salary>=0 && salary<=10000000 && !cin.fail()){
            break;
        }
        else{
            cout<<"Invalid Input please enter a salary between 0 and 10000000\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setSalary(salary);
}

