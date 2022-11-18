#pragma once 
#include <string>
#include "dateObj.h"

using std::string;


class person{
    public:


    //zero argument constructor 
    person();

    //multi argument constructor 
    person(
        string Fname,
        string lName,
        int ID, 
        int birthDayD =0,int birthDayMonth=0,int birthDayYear=0000, 
        int hirringDay=0,int hirringMonth=0,int hirringYear=0000
    );

    void setFname(string Fname);
    void setLname(string lName);

    void setID(int ID);



    string getFname() const;
    string getLname() const;

    int getId() const;

    Date birthDay;
    Date hirringDate;

    private:
    

    string fName;
    string lName;
    int ID;

    

};  