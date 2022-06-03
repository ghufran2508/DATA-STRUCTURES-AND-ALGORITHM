#include<iostream>
#include"Graph.h"

using namespace std;

int main()
{
	GRAPH gp;

	gp.Insert("A");
	gp.Insert("B");
	gp.Insert("C");
	gp.Insert("D");
	gp.Insert("E");

	gp.Link("A", "B", 5);
	gp.Link("A", "C", 10);
	gp.Link("C", "D", 1);
	gp.Link("B", "D", 15);
	gp.Link("D", "E", 100);

	cout << "\n*****************GRAPH A**********************\n";
	gp.printGeneralGraph();
	cout << "\n*****************GRAPH A**********************\n";

	cout << "\n*****************POSSIBLE PATHS**********************\n";
	cout << "\nCalculating All possible Path between two Vertex...." << endl;
	cout << "All Possible Path between two Vertex are:  " << gp.possiblePaths("A", "E") << endl;
	cout << "\n*****************POSSIBLE PATHS**********************\n";

	cout << "\n*****************GRAPH B(TRANSPOSE)**********************\n";
	GRAPH gp2 = gp.T_Graph();

	gp2.printGeneralGraph();
	cout << "\n*****************GRAPH B(TRANSPOSE)**********************\n";

	cout << "\n\n*******************DIJKSTRA***************************\n";
	gp.Dijkstra("A");
	cout << "\n\n*******************DIJKSTRA***************************\n";

	cout << "\n\n*******************BELLMANFORDS***************************\n";
	gp.BellManFords("B","E");
	cout << "\n\n*******************DIJKSTRA***************************\n";

	return 0;
}