

#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(){

	lim = 50;
	countVertex = 0;
	countEdge = 0;
	vertex = new Vertex [lim];
	edge = new Edge [lim];

}

Graph::~Graph(){

	delete [] vertex;
	delete [] edge;

}


