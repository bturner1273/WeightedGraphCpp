#pragma once
#include "Vertex.h"
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
	vector<bool> visited;
	vector<Vertex> graph;
	Graph();
	Graph(vector<Vertex> graph);
	void writeGraph();
	void instruct();
	void storeToGraph(Vertex first, Vertex second, double weight);
	string toString();
	void sortVerticies();
	void sortEdgesOfAllVerticiesByWeight();
	int contains(int vertexNum);
	void DFS(Vertex v);
	void BFS(Vertex v);
	void shortestPath(Vertex source);
	void clearVisitedArr();
	int size();
	template<class> struct greater;
	~Graph();
};

