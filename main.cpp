#include <iostream>
#include "Graph.h"
//for tests
#include "EdgeList.h"

using namespace std;

int main() {



	//testing genius for-loop! IT WORKS
	/*Vertex v;
	for (int i = 0; i < 3; i++) {
		v.adjList.tailInsert(i, rand() % 5);
	}
	for (Edge * x = v.adjList.head; x != NULL; x = x->next) {
		cout << "vertexNum: " << x->vertexNum << " Weight: " << x->weight << endl;
	}*/

	//bool array-pass testing
	/*bool visited[] = { true, false, true, true };
	bool* visit = &*visited;
	cout << *(visited+1) << endl;*/
	
	//GRAPH TESTING WORKS
	//Graph* g = new Graph();
	//cout << g->toString();
	//GRAPH DFS WORKS
	//g->DFS(g->graph.at(2));
	//cout << endl;
	
	//visited vector instantiated correctly to all false
	//after Graph initialization
	/*for (int i = 0; i < g->visited.size(); i++) {
		cout << g->visited[i] << endl;
	}*/
	
	//TEST EDGELIST WORKS
	//EdgeList a; //we are pretending a is in Vertex 1
	//a.headInsert(2, 34.5);
	//a.headInsert(3, 22.2);
	//a.headInsert(4, 12.5);
	//a.headInsert(5, 42.6);
	//cout << "Vertex 1-";
	//cout << a.toString() << endl;
	//a.insertionSort(&a.head);
	//cout << "After sorting by weight:" << endl;
	//cout << "Vertex 1-" << endl << a.toString() << endl;
	
	system("pause");
	return 0;
}