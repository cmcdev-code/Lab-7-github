//file that has all the class function definitions
#include "employee.h"//header file
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
//0 argument constructor 
Employee::Employee() :person() {
   employeeScore=0000;
    milesTraveled=0.0f;
}

//3 argument constructor 
Employee::Employee(double milesTraveled,double employeeScore,string Fname,string lName,int ID, int birthDayD,
            int birthDayMonth,int birthDayYear, int hirringDay,int hirringMonth,int hirringYear) 

:person(Fname,lName,ID,birthDayD,birthDayMonth,birthDayYear,hirringDay,hirringMonth,hirringYear)
{
this->milesTraveled=milesTraveled;    
this->employeeScore=employeeScore;
}

//adds a jobs to the back of the vector 
void Employee::vectorPushBack(double jobs) {
    this->jobs.push_back(jobs);
}
//gets the value at a certain index in the vector 
double Employee::vectorAtIndex(int index) const {
    return this->jobs.at(index);
}
void Employee::setEmployeeScore(double employeeScore) {
    this->employeeScore=employeeScore;
}

double Employee::getEmployeeScore() const {
    return this->employeeScore;
}

//member function to delete all values in the vector 
void Employee::delVector() {
    this->jobs.clear();
}

int Employee::sizeVectorjobs() const
{
    return this->jobs.size();
}

void Employee::setMilesTraveled(double milesTravelled)
{
    this->milesTraveled=milesTravelled;
}
double Employee::getMilesTraveled() const
{
    return milesTraveled;
}


std::ostream & operator <<(std::ostream & out,const Employee & localObj)
{
    out<<"Name:"<<std::setw(30)<<std::right<<localObj.getFname()+" "+localObj.getLname()+"\n";
    out<<"Employee ID:"<<std::setw(30)<<std::right<<localObj.getId()<<"\n";
    out<<"Birth Day:"<<std::setw(30)<<std::right<<localObj.birthDay<<"\n";
    out<<"Date Hirred:"<<std::setw(30)<<std::right<<localObj.hirringDate<<"\n";
    out<<"Miles Traveled:"<<std::setw(30)<<std::right<<localObj.getMilesTraveled()<<"\n";
    out<<"Employee Rating:"<<std::setw(30)<<std::right<<localObj.getEmployeeScore()<<"\n";
    out<<"Completed Job Revenue: \n";
    for(int i=0;i<localObj.sizeVectorjobs();i++)
    {
        out<<std::setw(30)<<std::right<<"$"<<std::fixed<<std::setprecision(2)<<localObj.vectorAtIndex(i)<<"\n";
    }
    return out;
}

void Employee::askForEmployeeScore()
{//error check and ask for user input 
    double score=0.0f;
    while(true){
        cout<<"Enter Employee Score: ";
        cin>>score;
        if(score>=0 && score<=100 && !cin.fail()){
            
            break;
        }
        else{
            cout<<"Invalid Input please enter a score between 0 and 100\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setEmployeeScore(score);
}


void Employee::askForMilesTraveled()
{//error check and ask for user input 
    double miles=0.0f;
    while(true){
        cout<<"Enter Miles Traveled: ";
        cin>>miles;
        if(miles>=0 && miles<=10000 && !cin.fail()){

            break;
        }
        else{
            cout<<"Invalid input please enter a value between 0 and 10000\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setMilesTraveled(miles);
}

void Employee::askForJobs()
{
double jobsCompleted=0.0f;
while(true){
    cout<<"What was the total revenue of the job? \n";
    cin>>jobsCompleted;
    if(jobsCompleted>=0 && jobsCompleted<=100000000 && !cin.fail()){
        break;
    }
    else{
        cout<<"Error please enter a number between 0 and 100000000\n";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
}
vectorPushBack(jobsCompleted);
}

bool Employee::operator<(const Employee & localObj) const
{
    if(this->getEmployeeScore()<localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator <=(const Employee & localObj) const
{
    if(this->getEmployeeScore()<=localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator>(const Employee & localObj) const
{
    if(this->getEmployeeScore()>localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator >=(const Employee & localObj) const
{
    if(this->getEmployeeScore()>=localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator==(const Employee & localObj) const
{
    if(this->getEmployeeScore()==localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Employee::operator!=(const Employee & localObj) const
{
    if(this->getEmployeeScore()!=localObj.getEmployeeScore())
    {
        return true;
    }
    else
    {
        return false;
    }
}
