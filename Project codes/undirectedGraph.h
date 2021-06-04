

#ifndef UNDIRECTEDGRAPH_H_
#define UNDIRECTEDGRAPH_H_

#include "graph.h"
using namespace std;

class undirectedGraph: public Graph {

	public:
			undirectedGraph();
			virtual ~undirectedGraph();

			//adding the vertex and array of vertices
	 	 	virtual bool addVertex(Vertex&);
	 	 	virtual bool addVertices(Vertex*, unsigned int);

	 	 	//adding edge and array of edges
	 	 	virtual bool addEdge(Edge&);
	 	 	virtual bool addEdges(Edge* , unsigned int);

	 	 	//removing edge and vertex
	 	 	virtual bool remove(Edge&);
	 	 	virtual bool removeVertex(Vertex& );

	 	 	//searching vertex and edge
	 	 	virtual bool searchVertex(const Vertex& );
	 	 	virtual bool searchEdge(const Edge& );

	 	 	//displaying various paths containing a vertex or edge
	 	 	//dont want to confuse with the print function, cuz already overloaded
	 	 	virtual void display(Vertex&) const;
	 	 	virtual void display(Edge& ) const;
	 	 	virtual void display() const;

	 	 	//conversion to string to display data
	 	 	virtual string toString () const;

	 	 	//remove all vertex and edge
	 	 	virtual bool clean();

	 	 	//compare and have same edge/vertex
	 	 	bool operator==(const undirectedGraph&) const;

};




#endif /* UNDIRECTEDGRAPH_H_ */
