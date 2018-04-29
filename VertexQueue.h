#pragma once
#include "Vertex.h"
#include <iostream>
#include <vector>
using namespace std;

class VertexQueue
{
public:
	vector<Vertex> q;
	void enqueue(Vertex v);
	void dequeue();
	VertexQueue();
	~VertexQueue();
};

