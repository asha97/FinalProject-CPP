

#include <iostream>
#include "vertex.h"
#include "HospitalEmployees.h"
using namespace std;

Vertex::Vertex(){

	id = -1;
	value = 0;

}

Vertex::Vertex(int i, int v){
	id = i;
	value = v;
}


void Vertex::setID(int i){

	id = i;

}

void Vertex::setValue(int v){

	value = v;

}

int Vertex::getID() const{

	return id;

}

int Vertex::getValue() const{

	return value;

}

//here we want to print the values and id of a vertex
void Vertex::print() const{

	cout<<"Employee ID:" << value ;
	cout<< "--";
	cout<<"Position#: "<<id;

}

Vertex::~Vertex(){

}

