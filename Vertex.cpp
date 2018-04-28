#include "Vertex.h"

//constructors
Vertex::Vertex(int vertexNumber, EdgeList adjList)
{
	this->vertexNum = vertexNum;
	this->adjList = adjList;
}

Vertex Vertex::operator =(Vertex toClone) {
	toClone.adjList = this->adjList;
	toClone.vertexNum = this->vertexNum;
	return toClone;
}

Vertex::Vertex() {}
Vertex::~Vertex(){}
