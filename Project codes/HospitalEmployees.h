

#ifndef HospitalEmployees_h
#define HospitalEmployees_h

#include <string>
#include <iostream>
#include "vertex.h"
using namespace std;

class HospitalEmployees:public Vertex{
private:
    int idNum;
    string firstName;
    string lastName;
    string dateOfBirth;
    int yearsOfExp;
    string degreeLevel;
    string occupation;
    int hours;
    int salary;
    
public:
    HospitalEmployees();

    HospitalEmployees(int, int, int, string, string, string, int, string, string, int, int);
    
    void setId(int);
    void setFirstName(string);
    void setLastName(string);
    void setDateOfBirth(string);
    void setYearsOfExp(int);
    void setDegreeLevel(string);
    void setOccupation(string);
    void setHours(int);
    void setSalary(int);
    
    int getId();
    string getFirstName();
    string getLastName();
    string getDateOfBirth();
    int getYearsOfExp();
    string getDegreeLevel();
    string getOccupation();
    int getHours();
    int getSalary();
    
    virtual void printInfo();
    ~HospitalEmployees();
    
};


#endif /* HospitalEmployees_h */

