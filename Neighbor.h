#pragma once
class Neighbor
{
public:
	int vertexNum;
	double weight;
	Neighbor * next;
	Neighbor();
	Neighbor(int vertexNum);
	/*Neighbor(int vertexNum, Neighbor * next);
	Neighbor(int vertexNum, Neighbor * next, double weight);*/
	Neighbor(int vertexNum, double weight);
	~Neighbor();
};

