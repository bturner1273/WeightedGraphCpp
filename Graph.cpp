#include "Graph.h"
#include<list>		//for BFS
#include<algorithm>
#include<limits>
#include <queue>

double *dist;
int *prev_;

template<class _Ty = void>
struct Graph::greater
{	// functor for operator<
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (dist[_Left] > dist[_Right]);
	}
};


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
	clearVisitedArr();
	list<Vertex> q;
	//visited.at(v.vertexNum) = true;
	q.push_back(v);
	while (!q.empty()){
		cout << q.front().vertexNum << " ";
		v = q.front(); //dequeue
		q.pop_front();
		visited.at(v.vertexNum) = true;
		for (Edge * x = v.adjList.head; x != NULL; x = x->next) {
			if (!visited.at(x->vertexNum)) {
				visited.at(x->vertexNum) = true;
				q.push_back(graph.at(x->vertexNum));
			}
		}

	}
}

void Graph::shortestPath(Vertex source) {
	dist = new double[graph.size()];
	prev_ = new int[graph.size()]();
	priority_queue<double, vector<double>, greater<int>> q;
	cout << DBL_MAX +1 << endl;
	memset(dist, DBL_MAX, graph.size() * sizeof(double));
	memset(prev_, 0, graph.size() * sizeof(int));
	for (int i = 0; i < graph.size(); i++) {
		q.push(graph.at(i).vertexNum);
	}
	dist[source.vertexNum] = 0;
	while (!q.empty()) {
		int x = q.top();
		q.pop();
		for (Edge * i = graph.at(x).adjList.head; i != NULL; i = i->next) {
			double temp = dist[x] + i->weight;
			cout << temp << endl;
			if (temp < dist[i->vertexNum]) {
				dist[i->vertexNum] = temp;
				prev_[i->vertexNum] = x;
			}
		}
	}
	for (int i = 0; i < graph.size(); i++) 
		cout << "Vertex 0 shortest path to Vertex " << graph.at(i).vertexNum << " is " << dist[i] << endl;

	delete[] dist;
	delete[] prev_;
}

Graph::Graph(vector<Vertex> graph) {
	this->graph = graph;
}