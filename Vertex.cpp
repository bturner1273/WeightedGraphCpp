#include "Vertex.h"

//constructors
Vertex::Vertex(int vertexNumber, EdgeList adjList)
{
	this->vertexNum = vertexNum;
	this->adjList = adjList;
}

Vertex Vertex::operator =(Vertex toClone) {
	this->adjList = toClone.adjList;
	this->vertexNum = toClone.vertexNum;
	return toClone;
}

Vertex::Vertex() {}
Vertex::~Vertex(){}
