

#ifndef GRAPH_H_
#define GRAPH_H_


#include "edge.h"
#include <string>
using namespace std;

class Graph{

	protected:
			Vertex *vertex;
			Edge* edge;
			int lim;
			int countEdge;
			int countVertex;

	public:
	 	 	Graph();
	 	 	virtual ~Graph();
	 	 	virtual bool addVertex(Vertex& )=0;
	 	 	virtual bool addVertices(Vertex* , unsigned int) = 0;
	 	 	virtual bool removeVertex(Vertex& ) = 0;
	 	 	virtual bool addEdge(Edge& ) = 0;
	 	 	virtual bool addEdges(Edge* , unsigned int) = 0;
	 	 	virtual bool remove(Edge& ) = 0;
	 	 	virtual bool searchVertex(const Vertex& ) = 0;
	 	 	virtual bool searchEdge(const Edge& ) = 0;
	 	 	virtual void display(Vertex& ) const = 0;
	 	 	virtual void display(Edge& ) const = 0;
	 	 	virtual void display() const = 0;
	 	 	virtual string toString () const = 0;
	 	 	virtual bool clean() = 0;


};




#endif /* GRAPH_H_ */
