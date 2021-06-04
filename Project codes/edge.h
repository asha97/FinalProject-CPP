

#ifndef EDGE_H_
#define EDGE_H_

#include "vertex.h"

class Edge{

	private:
			int weight;
			Vertex begin;
			Vertex end;


	public:
			Edge();
			Edge(Vertex&, Vertex&, int);
			void setBegin(Vertex&);
			void setEnd(Vertex&);
			void setWeight(int);
			int getBeginID() const;
			int getBeginValue() const;
			int getEndID() const;
			int getEndValue() const;
			int getWeight() const;
			void print() const;
			~Edge();

};





#endif /* EDGE_H_ */
