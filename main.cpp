#include "manager.h"
#include "person.h"
#include "employee.h"
#include <iostream>
#include <fstream>

using namespace std;



int main(void){
    manager test("Manager",199,1,1,2000,"Collin","McDevitt",18182,4,20,2002,12,12,12);
    cout<< test;
    Employee test2(100,100,"Collin","McDevitt",18182,4,20,2002,12,12,12);
    cout<< test2;
    
    


}

