

#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <string>
using namespace std;


class Vertex{

	private:
			int id;
			int value;


	public:
			Vertex();


			Vertex (int, int);

			//template <typename T>
			//Vertex(T, T);
			~Vertex();

			void setID(int);
			void setValue(int);

			int getID() const;
			int getValue() const;

			//printing the id and values
			void print() const;



};



#endif /* VERTEX_H_ */
