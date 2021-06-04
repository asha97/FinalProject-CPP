
#include <iostream>
#include "edge.h"
using namespace std;

Edge::Edge(){

	weight = -1;

}

Edge::Edge(Vertex &b, Vertex &e, int w){

	begin = b;
	end = e;
	weight = w;

}

void Edge::setBegin(Vertex &b){

	begin = b;

}

void Edge::setEnd(Vertex &e){

	end =  e;

}

void Edge::setWeight(int w){

	weight = w;

}

int Edge::getBeginID() const{

	return begin.getID();

}

int Edge::getBeginValue() const{

	return begin.getValue();

}

int Edge::getEndID() const{

	return end.getID();

}

int Edge::getEndValue() const{

	return end.getValue();
}

int Edge::getWeight() const{

	return weight;

}

void Edge::print() const{

	begin.print();
	cout<<" --> ";
	end.print();


}

Edge::~Edge(){


}
