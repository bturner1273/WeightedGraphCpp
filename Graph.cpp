#include "Graph.h"
#include<algorithm>



Graph::Graph()
{
	writeGraph();
	sortEdgesOfAllVerticiesByWeight();
	sortVerticies();
	clearVisitedArr();
}

void Graph:: clearVisitedArr() {
	for (int i = 0; i < graph.size(); i++) {
		visited.push_back(false);
		visited.resize(graph.size());
	}
}

void Graph::sortEdgesOfAllVerticiesByWeight() {
	for (int i = 0; i < graph.size(); i++) {
		graph.at(i).adjList.insertionSort(&graph.at(i).adjList.head);
	}
}



void Graph::sortVerticies() {
	struct less_than_key
	{
		inline bool operator() (const Vertex& struct1, const Vertex& struct2)
		{
			return (struct1.vertexNum < struct2.vertexNum);
		}
	};
	sort(graph.begin(), graph.end(), less_than_key());
}

int Graph::size() {
	return graph.size();
}

string Graph::toString() {
	string toReturn = "";
	for (int i = 0; i < graph.size(); i++) {
		toReturn += "\nVertex " + to_string(graph.at(i).vertexNum) + "-" + graph.at(i).adjList.toString() + "\n";
	}
	return toReturn;
}

void Graph::writeGraph() {
	int firstVertex, secondVertex;
	double weight;
	instruct();
	do {
		cin >> firstVertex >> secondVertex >> weight;
		Vertex first, second;
		first.vertexNum = firstVertex;
		second.vertexNum = secondVertex;
		if (firstVertex == 0, secondVertex == 0, weight == 0) break;
		storeToGraph(first, second, weight);
		storeToGraph(second, first, weight);
	} while (1);
}

void Graph::storeToGraph(Vertex first, Vertex second, double weight) {
	Edge* first_to_second = new Edge(second.vertexNum, weight);
	//if the vertex number is already held in the graph
	if (contains(first.vertexNum) != -1) {
		graph.at(contains(first.vertexNum)).adjList.headInsert(first_to_second->vertexNum,first_to_second->weight);
	}
	//make a vertex with the other vertex in it's adjList 
	//and store it in the graph
	else {
		first.adjList.headInsert(first_to_second->vertexNum, first_to_second->weight);
		graph.push_back(first);
	}
}

void Graph::instruct() {
	cout << "Enter adjacency list in the format: "
		<< "\nfromVertex toVertex weight"
		<< "\ni.e. 1 2 23.4"
		<< "\nWhen finished Enter 0 0 0" << endl << endl;
}


//returns index of vertex already
//held in graph so that it's adjList
//can be updated
int Graph::contains(int vertexNum) {
	for (int i = 0; i < graph.size(); i++) {
		if (graph.at(i).vertexNum == vertexNum) {
			return i;
		}
	}
	return -1;
}

void Graph::DFS(Vertex v) {
	//set the visited value in the vector 
	//indexed at the array number to true
	//and print the vertex number visited
	visited.at(v.vertexNum) = true;
	cout << v.vertexNum << " ";
	//iterate through adjacency list
	for (Edge * x = v.adjList.head; x != NULL; x = x->next) {
		if (!visited.at(x->vertexNum)) {
			DFS(graph.at(x->vertexNum));
		}
	}
	clearVisitedArr();
}

void Graph::BFS(Vertex v) {

}

void Graph::shortestPath(Vertex source, Vertex destination) {

}

Graph::Graph(vector<Vertex> graph) {
	this->graph = graph;
}

Graph::~Graph()
{
}
