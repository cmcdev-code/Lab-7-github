#include "person.h"
#include <iostream>


person::person()
{
    fName="";
    lName="";
    ID=0000;
    birthDay.setDate(0,0,0000);
    hirringDate.setDate(0,0,0000);
}
 person::person(string Fname,string lName,int ID, 
            int birthDayD,int birthDayMonth,int birthDayYear, 
            int hirringDay,int hirringMonth,int hirringYear)
        {   
        this->fName=Fname;
        this->lName=lName;
        this->ID=ID;
        this->birthDay.setDate(birthDayD,birthDayMonth,birthDayYear);
        this->hirringDate.setDate(hirringDay,hirringMonth,hirringYear);
        }
void person::setFname(string Fname)
{
    this->fName=Fname;
}
void person::setLname(string lName)
{
    this->lName=lName;
}
void person::setID(int ID)
{
    this->ID=ID;
}
string person::getFname() const
{
    return this->fName;
}
string person::getLname() const
{
    return this->lName;
}
int person::getId() const
{
    return this->ID;
}





