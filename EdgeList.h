#pragma once
#include "Neighbor.h"
#include <iostream>
#include <string>
using namespace std;

typedef Neighbor Edge;

class EdgeList
{
public:
public:
	Edge * head, *tail;
	EdgeList();
	EdgeList(const EdgeList* copyLst);
	~EdgeList();
	void tailInsert(int vertexNum, double weight);
	void headInsert(int vertexNum, double weight);
	void tailRemove();
	void headRemove();
	void posInsert(int pos, int vertexNum, double weight);
	void clear();
	bool empty();
	int size();
	string toString();
	Edge retrieve(int pos);
	void posRemove(int pos);
	void replace(int pos, int vertexNum, double weight);
	void insertionSort(Edge **headRef);
	void sortedInsert(Edge **headRef, Edge *new_node);
	EdgeList& operator=(EdgeList &list);
private:
	int count = 0;
};

