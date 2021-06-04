

#include <stdio.h>
#include <string>
#include <iostream>
#include "HospitalEmployees.h"
#include "vertex.h"

using namespace std;

HospitalEmployees::HospitalEmployees():Vertex(){

    idNum = 0;
    firstName = "undefined";
    lastName = "undefined";
    dateOfBirth = "undefined";
    yearsOfExp = 0;
    degreeLevel = "undefined";
    occupation = "undefined";
    hours = 0;
    salary = 0;
}


HospitalEmployees::HospitalEmployees(int ide, int val, int i, string f, string l, string d, int y, string dl, string occ, int h, int s):Vertex(ide, val){

	idNum = i;
    firstName = f;
    lastName = l;
    dateOfBirth = d;
    yearsOfExp = y;
    degreeLevel = dl;
    occupation = occ;
    hours = h;
    salary = s;
}

void HospitalEmployees:: setId(int i){
    idNum = i;
}
void HospitalEmployees::setFirstName(string f){
    firstName = f;
}
void HospitalEmployees::setLastName(string l){
    lastName = l;
}
void HospitalEmployees::setDateOfBirth(string dob){
    dateOfBirth = dob;
}
void HospitalEmployees::setYearsOfExp(int yox){
    yearsOfExp = yox;
}
void HospitalEmployees::setDegreeLevel(string dl){
    degreeLevel = dl;
}

void HospitalEmployees::setOccupation(string occ){
	occupation = occ;
}

void HospitalEmployees::setHours(int h){
    hours = h;
}
void HospitalEmployees::setSalary(int s){
    salary = s;
}

int HospitalEmployees::getId(){
    return idNum;
}
string HospitalEmployees::getFirstName(){
    return firstName;
}
string HospitalEmployees::getLastName(){
    return lastName;
}
string HospitalEmployees::getDateOfBirth(){
    return dateOfBirth;
}
int HospitalEmployees::getYearsOfExp(){
    return yearsOfExp;
}
string HospitalEmployees::getDegreeLevel(){
    return degreeLevel;
}
string HospitalEmployees::getOccupation(){
	return occupation;
}

int HospitalEmployees::getHours(){
    return hours;
}

int HospitalEmployees::getSalary(){
    return salary;
}

void HospitalEmployees::printInfo(){

	cout << "---Information about the Vertex---\n";
	cout<< "Vertex ID: "<< getID() << endl;
	cout << "Vertex Value: " << getValue() << "\n\n";

	cout << "---Information about the Employee---\n";
    cout << "The identification number is: " << getId() << endl;
    cout << "The first name is: " << getFirstName() << endl;
    cout << "The last name is: " << getLastName() << endl;
    cout << "The date of birth is: " << getDateOfBirth() << endl;
    cout << "The years of experience is: " << getYearsOfExp() << endl;
    cout << "The degree level is: " << getDegreeLevel() << endl;
    cout << "The occupation is: " << getOccupation() << endl;
    cout << "The hours worked is: " << getHours() << endl;
    cout << "The salary is: " << getSalary() << endl;
}

HospitalEmployees::~HospitalEmployees(){
    
}

