#pragma once
#include "Neighbor.h"
#include "EdgeList.h"
typedef Neighbor Edge;


class Vertex
{
public:
	int vertexNum;
	EdgeList adjList;
	Vertex();
	Vertex(int vertexNum, EdgeList adjList);
	Vertex operator =(Vertex toClone);
	~Vertex();
};

