#pragma once
//file that has the class 
#include <vector>
#include <string>
#include "person.h"

class Employee : public person
{

public:


    //constructor
    Employee();
    //3 argument constructor  
    Employee(double milesTraveled,double employeeScore,string Fname,string lName,int ID, int birthDayD,int birthDayMonth,int birthDayYear, int hirringDay,int hirringMonth,int hirringYear);

    //function to put a value in the vector
    void vectorPushBack(double jobs);

    void setMilesTraveled(double milesTravelled);
    
    void setEmployeeScore(double employeeScore);
    double getEmployeeScore() const;


    double getMilesTraveled() const;

    //will return the value of the vector at that index 
    double vectorAtIndex(int index) const;
    //will get the size of the vector 
    int sizeVectorjobs() const;

    //will clear the vector 
    void delVector();

    void askForEmployeeScore();

    void askForMilesTraveled();

    void askForJobs();

    friend std::ostream & operator << (std::ostream &out, const Employee &localObj);
    
   
    bool operator < (const Employee &localObj) const;
    bool operator <= (const Employee &localObj) const;
    bool operator > (const Employee &localObj) const;
    bool operator >= (const Employee &localObj) const;
    bool operator == (const Employee &localObj) const;
    bool operator != (const Employee &localObj) const;

private:
    double employeeScore;
    std::vector<double> jobs;
    double milesTraveled;


};
