

#include<iostream>
#include<string>
#include"undirectedGraph.h"
using namespace std;
#include "HospitalEmployees.h"
#include "vertex.h"
#include "edge.h"


//create a function in which we are going to be displaying the adjacency matrix
//have six employees in our system

//empty matrix, where 1s will be added when there is an edge
int vertexArray[6][6]; //since there is 6 employees


void displayMatrix(int numVertex){
	int i;
	int j;

	for (i =0; i<numVertex ; i++){
		for (j=0; j< numVertex ; j++){
			cout << vertexArray[i][j] << " ";
		}
		cout << endl;
	}


}

//adding edge between two nodes
void addingEdge(int x, int y){ //vertex v1.getID(), vertex v2.getID()

	vertexArray[x-1][y-1]=1; //our numbers start at 1....
	vertexArray[y-1][x-1]=1;

}

void removingEdge(int x, int y){
	vertexArray[x-1][y-1] =0;
	vertexArray[y-1][x-1] =0;
}

void deleteMatrix(int numVertex){
	int i;
	int j;

	for (i =0; i<numVertex ; i++){
		for (j=0; j< numVertex ; j++){
			vertexArray[i][j]=0;
		}
		cout << endl;
	}
}


int main(){

	//Employee#1

    int iden = 12345;
    Vertex v1(1, iden);

	string fname = "John";
	string lname = "Doe";
	string dob = "01-01-2000";
	int yearsofexp =2;
	string degree = "BEng";
	string occ = "Bioengineer";
	int hours =37;
	int salary = 45;

	HospitalEmployees h1(v1.getID(), v1.getValue(), iden,fname, lname, dob, yearsofexp, degree, occ, hours, salary);

	//dynamic casting for nursing to hospitalemployees
	v1 = dynamic_cast<Vertex&>(h1);


	//Employee #2 -

    int iden2 = 23456;
    Vertex v2(2, iden2);

	string fname2 = "asha";
	string lname2 = "islam";
	string dob2 = "12-12-12";
	int yearsofexp2 =5;
	string degree2 = "bsc";
	string occ2 = "kinesiologist";
	int hours2 =80;
	int salary2 = 30;

    HospitalEmployees h2 (v2.getID(), v2.getValue(),iden2, fname2,lname2, dob2, yearsofexp2, degree2, occ2, hours2, salary2);

    v2 = dynamic_cast<Vertex&>(h2);
    //h2.printInfo();


    //employee #3

    int iden3 = 23456;
    Vertex v3(1, iden3);

	string fname3 = "jane";
	string lname3 = "doe";
	string dob3 = "12-11-12";
	int yearsofexp3 =12;
	string degree3 = "bsc";
	string occ3 = "biologist";
	int hours3 =56;
	int salary3 = 30;

    HospitalEmployees h3 (v3.getID(), v3.getValue(),iden3, fname3,lname3, dob3, yearsofexp3, degree3, occ3, hours3, salary3);

    v3 = dynamic_cast<Vertex&>(h3);
    //h3.printInfo();

	//Employee #4

    int iden4 = 23456;
    Vertex v4(4, iden4);
	string fname4 = "john";
	string lname4 = "doe";
	string dob4 = "11-12-01";
	int yearsofexp4 =5;
	string degree4 = "bsc";
	string occ4 = "researcher";
	int hours4 =80;
	int salary4 = 30;

    HospitalEmployees h4 (v4.getID(), v4.getValue(),iden4, fname4,lname4, dob4, yearsofexp4, degree4, occ4, hours4, salary4);

    v4 = dynamic_cast<Vertex&>(h4);
    //h4.printInfo();

	//Employee #5

    int iden5 = 23456;
    Vertex v5(5, iden5);
	string fname5 = "ella";
	string lname5 = "bella";
	string dob5 = "06-05-98";
	int yearsofexp5 =8;
	string degree5 = "bsc";
	string occ5 = "physiotherapist";
	int hours5 =40;
	int salary5 = 45;

    HospitalEmployees h5 (v5.getID(), v5.getValue(),iden5, fname5,lname5, dob5, yearsofexp5, degree5, occ5, hours5, salary5);

    v5 = dynamic_cast<Vertex&>(h5);
    //h5.printInfo();


	//Employee #6

    int iden6 = 23456;
    Vertex v6(6, iden6);

	string fname6 = "michael";
	string lname6 = "carry";
	string dob6 = "01-02-94";
	int yearsofexp6 =8;
	string degree6 = "beng";
	string occ6 = "IT";
	int hours6 =80;
	int salary6 = 30;

    HospitalEmployees h6 (v6.getID(), v6.getValue(),iden6, fname6,lname6, dob6, yearsofexp6, degree6, occ6, hours6, salary6);

    v6 = dynamic_cast<Vertex&>(h6);
    //h6.printInfo();

	//create graph to add vertices and edges
	undirectedGraph u1;
	undirectedGraph u2;

	//create the relations w edges
	Edge e1(v1,v2,11);
	Edge e2(v1,v3,22);
	Edge e3(v3,v4,33);
	Edge e4(v4,v5,44);
	Edge e5 (v5, v6, 55);


	//Declares an array of objects the class Vertex
	Edge e[3];
	e[0] = e1;
	e[1] = e2;
	e[2] = e3;

	bool one = u1.addVertex(v1);
	bool two = u1.addVertex(v2);
	bool three = u1.addVertex(v3);
	bool four = u1.addVertex(v4);
	bool five = u1.addVertex(v5);
	bool six = u1.addVertex(v4);
	bool seven = u1.addVertex(v6);


	//Adding vertex/vertices to the graph u1
	cout<<"\n---Add Hospital Employees to Graph 1---\n";
	cout<<"Adding Employee 1: "<<boolalpha <<one << endl;
	cout<<"Adding Employee 2: "<<boolalpha<<two <<endl;
	cout<<"Adding Employee 3: "<<boolalpha << three << endl;
	cout<<"Adding Employee 4: "<<boolalpha<< four<<endl;
	cout<<"Adding Employee 5: "<<boolalpha<<five << endl;
	cout<<"Adding Employee 4 again: "<<boolalpha<< six<<endl;// Return false because it is added
	cout<<"Adding Employee 6: "<< boolalpha<<seven << endl;


	//adding the edges
	one = u1.addEdge(e1);
	two =u1.addEdge(e2);
	three = u1.addEdge(e3);
	four = u1.addEdge(e4);
	five = u1.addEdge(e1);

	//adding the edges in adjacency matrix
	addingEdge(v1.getID(), v2.getID());
	addingEdge(v1.getID(), v3.getID());
	addingEdge(v3.getID(), v4.getID());
	addingEdge(v4.getID(), v5.getID());


	//Adding Edges to the graph u1
	cout<<"\n---Add Relations to the graph 1---\n";
	cout << "(1 = true ; 0 = false)" <<endl;
	cout<<"Adding Relation 1: "<<one<<endl;
	cout<<"Adding Relation 2: "<<two<<endl;
	cout<<"Adding Relation 3: "<<three<<endl;
	cout<<"Adding Relation 4: "<<four<<endl;
	cout<<"Adding Relation 1 again: "<<five<<endl;//Return false because it is already added

	//display the adjacency matrix, which is going to show the relations between two vertices
    int v =6;
	cout <<"\n---Display Adjacency Matrix of all of the connections---\n" << endl;
	displayMatrix(v);
	cout<<"\n\n";


	//Display the path to the edge e2
	cout<<"\n---Path to edge e3--- "<<endl;
	u1.display(e3);

	//Display the path to the vertex v2
	cout<<"\n\n---Path to vertex v5---"<<endl;
	u1.display(v5);

	cout<<"\n\n---Displays details of relations in Graph 1--- "<<endl;
	u1.display();
	cout<<"\n\n";

	cout<< "---Remove employee and relations---\n";
	cout<<"Removes employee 1: "<<u1.removeVertex(v1)<<endl;	//Removing vertex v6 from the graph ug and return true
	cout<<"Removes relation 1: "<<u1.remove(e1)<<endl;//Removing edge e4 from the graph ug and return true
	cout<<"Removes relation 2: "<<u1.remove(e2)<<endl;//Removing edge e4 from the graph ug and return true
	removingEdge(e1.getBeginID(), e1.getEndID());
	removingEdge(e2.getBeginID(), e2.getEndID());


	u1.display();
	cout<<"\n\n---Adjacency matrix---\n\n";
	displayMatrix(v);
	cout <<endl;

	cout <<"---Searching Employees---" << endl;

	cout<<"\nSearch Vertex v1 :"<<u1.searchVertex(v1)<<endl;//return true
	cout<<"Search Edge e1 :"<<u1.searchEdge(e1)<<endl;//return true
	cout<<"Search Edge e5 :"<<u1.searchEdge(e5)<<endl;//return false because the edge e4 is not in the graph

	cout<<"\n\n Now let's assume we are in another department,"<< endl;
	cout<<"where the same employees work with different people.\n";

	//Adding the vertices to the graph u2
	cout<<"\n---Add Employees to Graph #2---\n"<<endl;
	cout<<"Add Employee 1: "<<u2.addVertex(v1)<<endl;
	cout<<"Add Employee 2: "<<u2.addVertex(v2)<<endl;
	cout<<"Add Employee 3: "<<u2.addVertex(v3)<<endl;
	cout<<"Add Employee 4: "<<u2.addVertex(v4)<<endl;
	cout<<"Add Employee 5: "<<u2.addVertex(v5)<<endl;

	Edge newEdge(v2, v5, 66);

	//adding the edges in adjacency matrix
	addingEdge(v2.getID(), v5.getID());
	addingEdge(v1.getID(), v3.getID());
	addingEdge(v3.getID(), v4.getID());
	addingEdge(v4.getID(), v5.getID());

	//Adding the edges to the graph u2
	cout<<"\n---Add Relations in Graph #2---\n"<<endl;
	cout<<"Add Relation 1: "<<u2.addEdge(newEdge)<<endl;
	cout<<"Add Relation 2: "<<u2.addEdge(e2)<<endl;
	cout<<"Add Relation 3: "<<u2.addEdge(e3)<<endl;
	cout<<"Add Relation 4: "<<u2.addEdge(e4)<<endl;


	//Comparing graph1 and 2 and return false since they are not the same
	cout << "\n---Compare Graph 1 & 2 Employee Network---" << endl;
	cout<<"Network 1 == Network 2?: "<<boolalpha<<(u1==u2)<<"\n\n";

	//adding a new employee
	cout << "Do you want to add another Employee into the system? (y/n): ";
	char ans;
	Vertex vNew(7, 1000);
	bool looping = true;

	while (looping == true){

		try{
			cin >> ans;
			if (ans=='n'){
				throw 1.00;
			} else if (ans !='y'){
				throw 1;
			} else {
				looping = false;

			    int idenNew;
			    cout << "Identity Number: ";
			    cin >> idenNew;
			    vNew.setValue(idenNew);
			    cout <<"\n";

				string fnameN;
				cout <<"First Name: " ;
				cin >>fnameN;
				cout << "\n";

				string lnameN;
				cout << "Last Name: ";
				cin >>lnameN;
				cout << "\n";

				string dobN;
				cout << "Date of Birth: ";
				cin >> dobN;
				cout << "\n";

				int yearsofexpN;
				cout << "Years of Experience: ";
				cin >> yearsofexpN;
				cout << "\n";

				string degreeN;
				cout << "Degree Type: ";
				cin >> degreeN;
				cout << "\n";

				string occN;
				cout << "Occupation: ";
				cin >> occN;
				cout << "\n" ;

				int hoursN;
				cout << "Hours worked: " ;
				cin >> hoursN;
				cout << "\n";

				int salaryN;
				cout << "Salary: ";
				cin >> salaryN;
				cout << "\n";

				HospitalEmployees newEmp (vNew.getID(), vNew.getValue(), idenNew, fnameN, lnameN, dobN, yearsofexpN, degreeN, occN, hoursN, salaryN);

				vNew = dynamic_cast<Vertex&>(newEmp);

				//add this new vertex to the graph.
				u1.addVertex(vNew);

				//going to notice that the new vertex added is going to be orphan because there is no connections
				u1.display();

			}
		} catch(double a){
			cout <<"You have chosen not to add any further employee.\n\n";
			break;

		} catch(int catching){
			cout << "Your answer is not valid, please try again.\n";

		}
	}

	//display information about a node, hospital employee 1
	cout << "\n---------info about employee 1---------\n\n";
	cout << "Name of the Employee? : " << h1.getLastName() << ", " << h1.getFirstName() << endl;
	cout << "Occupation? : " << h1.getOccupation() << endl;

	//display full information about employee #2
	cout << "\n---------Full information about employee 2---------\n";
	h2.printInfo();


	//deleting all edges and vertices and return true
	cout<<"\n\n---Clearing everything (clear() function)--- " << endl;
	cout<<u1.clean()<<endl;
	deleteMatrix(v);

	//display the cleared adjacency matrix
	cout << "---Cleared Adjacency Matrix---\n\n";
	displayMatrix(v);

	//display graph
	u1.display();


	return 0;

}


