

#include <iostream>
#include <array>
#include <string>
#include "undirectedGraph.h"
using namespace std;

//default constructor
undirectedGraph::undirectedGraph(){


}
//destructor
undirectedGraph::~undirectedGraph(){


}

//adds vertex
bool undirectedGraph::addVertex(Vertex& v){

	if(countVertex<lim){

		if(countVertex == 0){ //adding the first vertex

			vertex[countVertex] = v;
			//increase for the # of vertex since added
			countVertex = countVertex+1;
			return true;
		}

		else{
			for(int i = 0; i<countVertex ; i++){ //if it exists, then return false
				if(vertex[i].getID() == v.getID())
					return false;
			}

			//adding vertex after going through conditions
			vertex[countVertex] = v;
			countVertex = countVertex+1;
			return true;
		}
	}

	return false;
}
//removes one vertex from the graph
bool undirectedGraph::removeVertex(Vertex& v){

	if (countVertex > 0){

		for(int i = 0; i < countVertex ;  i++){

			//iterate through loop to find value that equates to the vertex we want to remove
			//both id and value
			if(vertex[i].getID() == v.getID() && vertex[i].getValue() == v.getValue()){
				for(int j = i; j< countVertex; j++){
					vertex[j] = vertex[j+1];
				}

				//want to remove edge linked to node that has been removed
				if (countEdge > 0){

					for(int m = 0; m<countEdge; m++){

						//making sure same id for begin and end of the edge, as well as for the value
						//to make sure removing the right edge
						if(( (edge[m].getBeginID() == v.getID()) &&  ( edge[m].getBeginValue()) == v.getValue()) || ((edge[m].getEndID()==v.getID()) && v.getValue() ==  edge[m].getEndValue())){

							for(int n = m; n < countEdge; n++){
								edge[n] = edge [n+1];
							}
							countEdge = countEdge - 1;
						}
					}
				}
				countVertex = countVertex -1;
				return true;
			}
		}
	}

	return false;
}
//stores vertex in an pointer array
bool undirectedGraph::addVertices(Vertex* vert, unsigned int size){

	if(countVertex<lim){

		if(countVertex==0){ //if there are no vertex yet

			for(size_t i = 0; i<size; i++){

				this->addVertex(vert[i]);
			}
			return true;
		}

		else{

			//if there are already pre-existing vertices
			for(int j = 0; j<countVertex; j++){

				for(size_t k = 0; k<size; k++){
					//if it already exists, return false
					if(this->vertex[j].getID()==vert[k].getID()){
						return false;
					}
				}
			}

			//adding the vertex
			for(size_t l = 0; l<size; l++){
				this->addVertex(vert[l]);
			}

			return true;
		}
	}



	return false;
}
//adds an edge to the graph
bool undirectedGraph::addEdge(Edge& ed){

	if(countEdge<lim){

		if(countEdge == 0){
			if(countVertex==0){ //if there are not vertex, cant add edges
				return false;
			}

			else{

			for(int f = 0; f<countVertex; f++){

				//comparing id and value of vertices t
				if(ed.getEndID()==this->vertex[f].getID() && ed.getEndValue()== this->vertex[f].getValue()){

					for(int a = 0; a<countVertex; a++){

						if(ed.getBeginID()==this->vertex[a].getID() && ed.getBeginValue()== this->vertex[a].getValue()){
							edge[countEdge] = ed;
							countEdge = countEdge+1;
							return true;
						}
					}
				}
			}

			return false;
			}
		}

		else{

			if(countVertex==0){ //if there are no vertices
				return false;
			}


			for(int i = 0; i < countEdge; i++){ //if edge exists already,cant add another one

				if((edge[i].getBeginID() == ed.getBeginID() && edge[i].getEndID() == ed.getEndID() && edge[i].getWeight()== ed.getWeight()) || (edge[i].getEndID() == ed.getBeginID() && edge[i].getBeginID() == ed.getEndID() && edge[i].getWeight()== ed.getWeight())){

					return false;

				}
			}

			for(int f = 0; f<countVertex; f++){ //find the vertices and make the link

				if(ed.getEndID()==this->vertex[f].getID() && ed.getEndValue()== this->vertex[f].getValue()){

					for(int a = 0; a<countVertex; a++){

						if(ed.getBeginID()==this->vertex[a].getID() && ed.getBeginValue()== this->vertex[a].getValue()){

							edge[countEdge] = ed;
							countEdge = countEdge+1;
							return true;
						}
					}
				}
			}

			return false;
		}
	}

	return false;
}
//stores edges in array pointer
bool undirectedGraph::addEdges(Edge* eP,unsigned int size){

	//size of edge pointer
	int p;
	p= sizeof(eP);

	//making array of boolean to make sure that they have all been added
	bool *check;
	check = new bool [p];

	//initializing to false the array
	for(size_t b = 0; b<p; b++){

		check[b] = false;

	}

	if(countEdge<lim){
		if(countEdge==0){
			if(countVertex==0){ //if there are no vertices, cant add edge
							return false;
			}else {
				for(size_t s = 0; s<size; s++){

					for(int f = 0; f<countVertex; f++){
						//making sure to make the right connections by comparing id and value
						if(eP[s].getEndID()==this->vertex[f].getID() && eP[s].getEndValue()== this->vertex[f].getValue()){

							for(int a = 0; a<countVertex; a++){

								if(eP[s].getBeginID()==this->vertex[a].getID() && eP[s].getBeginValue()== this->vertex[a].getValue()){
									check[s] = true;

								}
							}
						}
					}
				}

				for(size_t d = 0; d<size; d++){
					if(check[d] == false){
						return false;
					}
				}

				for(size_t i = 0; i<size; i++){
					this->addEdge(eP[i]);
				}
				return true;

			}
		}

		else{

			if(countVertex==0){ // if there are no vertices
							return false;
						}
			else{
					for(size_t s = 0; s<size; s++){

						for(int f = 0; f<countVertex; f++){

							//making sure to have same id and value of the vertices to make right connections
							if(eP[s].getEndID()==this->vertex[f].getID() && eP[s].getEndValue()== this->vertex[f].getValue()){

								for(int a = 0; a<countVertex; a++){

									if(eP[s].getBeginID()==this->vertex[a].getID() && eP[s].getBeginValue()== this->vertex[a].getValue()){

										check[s] = true;

									}
								}
							}
						}
					}

					//display if the edges has been added
					for(size_t d = 0; d<size; d++){
						if(check[d] == false){
							return false;
						}

						cout << endl;
						cout<<check[d] << endl;
					}

					//if edge exists, return false
					for(int j = 0; j<countEdge; j++){
						for(size_t k = 0; k<size; k++){

							//compare begin and end if and value  of edge to make sure it does not exist
							if((this->edge[j].getBeginID() == eP[k].getBeginID() && this->edge[j].getEndID() == eP[k].getEndID()) || (this->edge[j].getEndID() == eP[k].getBeginID() && this->edge[j].getBeginID()== eP[k].getEndID())){
								return false;
							}
						}
					}

					//adding edges
					for(size_t l = 0; l<size; l++){
						this->addEdge(eP[l]);
					}

					return true;
				}
		}
	}

	return false;
}
//removes edge from the graph
bool undirectedGraph::remove(Edge &e){

	if (countEdge>0){

		for(int i = 0; i < countEdge; i++){
			//compare to make sure that the edge exists to remove it
			if((edge[i].getBeginID() == e.getBeginID() && edge[i].getEndID() == e.getEndID() && edge[i].getWeight()== e.getWeight()) || (edge[i].getEndID() == e.getBeginID() && edge[i].getBeginID() == e.getEndID() && edge[i].getWeight()== e.getWeight())){

				for (int j = i; j<countEdge; j++){
					edge[j] = edge[j+1];
				}
				countEdge = countEdge-1;
				return true;
			}
		}
	}

	//if it doesnt exist, then you cant remove it
	//so return false
	return false;

}
//looks for a vertex
bool undirectedGraph::searchVertex(const Vertex& v){

	//iterate through loop to make sure that it exists
	//with id and value matching
	for(int i = 0; i<countVertex; i++){
		if(vertex[i].getID() == v.getID() && vertex[i].getValue() == v.getValue()){
			return true;
		}
	}

	//return false if it does not exist
	return false;
}
//looks for a edge
bool undirectedGraph::searchEdge(const Edge& e){

	//look if the edge exist with begin and end id and value
	//to make sure it exists
	for(int i = 0; i< countEdge; i++){
		if((edge[i].getBeginID() == e.getBeginID() && edge[i].getEndID() == e.getEndID() && edge[i].getWeight()== e.getWeight() && edge[i].getBeginValue() == e.getBeginValue() && edge[i].getEndValue() == e.getEndValue()) || (edge[i].getEndID() == e.getBeginID() && edge[i].getBeginID() == e.getEndID() && edge[i].getWeight()== e.getWeight() && edge[i].getEndValue() == e.getBeginValue() && edge[i].getBeginValue() == e.getEndValue())){
			return true;
		}
	}
	//if it doesnt exist
	return false;

}
// displays the path w vertex
void undirectedGraph::display(Vertex& v) const{

	int storing; //store the end value as begin

	for(int i = 0; i<countEdge; i++){

		//end id of an edge match the vertex id
		if(edge[i].getEndID() == v.getID()){
			//call print function of edge
			edge[i].print();
			//store begin id of the end id just found
			storing = edge[i].getBeginID();

			for(int j = 0; j<countEdge;j++){

				for(int k = 0; k<countEdge; k++){
					//
					if(storing == edge[k].getEndID()){
						//call print function of edge
						edge[k].print();
						storing = edge[k].getBeginID();
					}
				}
			}
		}
	}
}
// displays the path that contains the edge.
void undirectedGraph::display(Edge& e) const{

	int ending;

	for(int i = 0; i<countEdge; i++){
		if((edge[i].getBeginID() == e.getBeginID() && edge[i].getEndID() == e.getEndID() && edge[i].getWeight()== e.getWeight()) || (edge[i].getEndID() == e.getBeginID() && edge[i].getBeginID() == e.getEndID() && edge[i].getWeight()== e.getWeight())){
			//print the edge of the path if the id and value and weight match
			edge[i].print();
			ending = edge[i].getBeginID();

			for(int j = 0; j<countEdge;j++){

				for(int k = 0; k<countEdge; k++){
					//same goes here, but now we are checking the end id to make sure to print the end
					if(ending== edge[k].getEndID()){

						edge[k].print();
						ending = edge[k].getBeginID();
					}
				}
			}
		}
	}

}
// displays graph
void undirectedGraph::display() const{

	bool orp = true;

	cout<<"\nEmployee Relation Graph: \n"<<endl;
	for(int i = 0; i<countEdge; i++){
		edge[i].print();
		cout << endl;
	}
	cout << endl;

	cout<<"\nOrphan Employees: \n"<<endl;

	for(int j = 0; j<countVertex; j++){
		for(int m = 0; m<countEdge; m++){
			if(vertex[j].getID()==edge[m].getBeginID() || vertex[j].getID()==edge[m].getEndID()){
				orp = false;
			}
		}
		if (orp){
			vertex[j].print();
			cout<<endl;
		}

		orp = true;
	}
}
// converts graph to a string
string undirectedGraph::toString() const{

	bool * look;
	look = new bool [countEdge];
	string str;

	bool ch = false;
	string s1;
	string sav;

	int la;
	int ind;
	int en;

	//initializing
	for(int i = 0 ; i<countEdge; i++){
		look[i] = false;
	}


		//check if the id matches and if it does then it is going to return true
		for(int n = 0; n<countEdge; n++){
			if(look[n]==false){

				en=edge[n].getEndID();

				for (int p = 0; p<countEdge; p++){

					for(int q= 0; q<countEdge; q++){

						if(en == edge[q].getBeginID()){
							ind = q;
							en = edge[q].getEndID();
							ch = true;
						}
					}
				}

				if (ch == true){
					//if the change is true, then u are going to start converting the graph
					//into strings
					s1 = to_string(edge[ind].getBeginValue())+"(ID:"+to_string(edge[ind].getBeginID())+")-";
					s1 = to_string(edge[ind].getEndValue())+"(ID:"+to_string(edge[ind].getEndID())+")";


					la = edge[ind].getBeginID();
					look[ind] = true;

					for(int m = 0; m<countEdge;m++){
						for(int k = 0; k<countEdge; k++){
							if(la == edge[k].getEndID()){

								s1.insert(0,1,'-');
								sav = "(ID:"+to_string(edge[k].getBeginID())+")";

								s1.insert(0,sav);

								s1.insert(0,to_string(edge[k].getBeginValue()));
								la = edge[k].getBeginID();
								look[k] =true;
								}
							}
						}

				}

				else{
					s1 = to_string(edge[n].getBeginValue())+"(ID:"+to_string(edge[n].getBeginID())+")-"+to_string(edge[n].getEndValue())+"(ID:"+to_string(edge[n].getEndID())+")";
					la = edge[n].getBeginID();
					look[n] = true;
					for(int m = 0; m<countEdge;m++){
						for(int k = 0; k<countEdge; k++){
							if(la == edge[k].getEndID()){

								s1.insert(0,1,'-');
								sav= "(ID: "+to_string(edge[k].getBeginID())+")";

								s1.insert(0,sav);

								s1.insert(0,to_string(edge[k].getBeginValue()));
								la = edge[k].getBeginID();
								look[k] =true;
								}
							}
						}
				}
				if(n==0){
					str=s1;
				}
				else if (n>0){
					str = str+"; "+s1;
				}
				ch = false;


				}

		}

	return str;
}
//remove all the vertex and edge;
bool undirectedGraph::clean(){

	//if there are no edges or vertices
	if(countEdge == 0 || countVertex ==0){
		return false;
	}

		//delete the pointer
		delete [] edge;
		delete [] vertex;

		countEdge = 0;
		countVertex =0;

		//new memory allocation
		vertex = new Vertex[lim];
		edge = new Edge [lim];

		return true;


}

//same vertex and edge in two compared graphs
bool undirectedGraph::operator==(const undirectedGraph & graph)const{

	if (countEdge == graph.countEdge && countVertex == graph.countVertex){
		bool *ed;
		bool *ve;
		ed = new bool[countEdge];
		ve = new bool[countVertex];

		//initializing the array pointers
		for(int i = 0; i< countEdge; i++){
			ed[i] = false;
		}

		for(int j = 0; j< countVertex; j++){
				ve[j] = false;
		}

		//compare and have the same id and value in the two graphs
		//for the edge
		for(int m = 0; m<countEdge; m++){
			for(int n = 0; n<countEdge; n++){
				if((edge[m].getBeginID()==graph.edge[n].getBeginID() && edge[m].getEndID()==graph.edge[n].getEndID()
						&& edge[m].getBeginValue()== graph.edge[n].getBeginValue()&& edge[m].getEndValue()==graph.edge[n].getEndValue()
						&& edge[m].getWeight()==graph.edge[n].getWeight()) || (edge[m].getEndID()==graph.edge[n].getBeginID()
						&& edge[m].getBeginID()==graph.edge[n].getEndID() && edge[m].getEndValue()== graph.edge[n].getBeginValue()
						&& edge[m].getBeginValue()==graph.edge[n].getEndValue()&& edge[m].getWeight()==graph.edge[n].getWeight())){
					ed[m] = true;
				}
			}
		}
		//compare and have the same id and value in the two graphs
		//for the vertices
	    for(int o = 0; o<countVertex; o++){
	    	for(int p = 0; p<countVertex; p++){
	    		if(vertex[o].getID() == graph.vertex[p].getID() && vertex[o].getValue()==graph.vertex[p].getValue()){
	    			ve[o] = true;
	    		}
	    	}
	    }

	    //if there are any false value in the array pointer, then return false
	    for(int q = 0; q<countEdge; q++){
	    	if(ed[q] == false){
	    		return false;
	    	}
	    }

	    //return false if there are any false value in the array pointer of vertices
	    for(int r = 0; r<countVertex; r++){
	    	if(ve[r] == false){
	    		return false;
	    	}
	    }

	    //if they dont have the same number of vertex or edge
	} else if (countEdge != graph.countEdge || countVertex != graph.countVertex){
		return false;
	}

	return true;
}
