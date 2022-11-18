#pragma once
#include "person.h"
#include <string>
#include <iostream>



class manager: public person

{ 

    public:

    manager();

    manager(string jobTitle,double salary,int promotionDay,int promotionMonth,int promotionYear,string Fname,string lName,int ID,int birthDayD,int birthDayMonth,int birthDayYear,int hirringDay,int hirringMonth,int hirringYear);

    void setJobTitle(string jobTitle);
    void setSalary(double salary);
    void setPromotionDate(int day,int month,int year);

    string getJobTitle() const;
    double getSalary() const;

    void askForJobTitle();

    void askForSalary();



    friend std::ostream & operator << (std::ostream &out, const manager &localObj);
    Date promotionDate;
    private:

    string jobTitle;
    double salary;
     



};
