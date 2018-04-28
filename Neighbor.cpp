#include "Neighbor.h"
#include <iostream>
using namespace std;

//constructors
Neighbor::Neighbor() {}

Neighbor::Neighbor(int vertexNum) {
	this->vertexNum = vertexNum;
	this->next = NULL;
}

Neighbor::Neighbor(int vertexNum, double weight) {
	this->vertexNum = vertexNum;
	this->weight = weight;
}

//
//Neighbor::Neighbor(int vertexNum, Neighbor * next) {
//	this->vertexNum = vertexNum;
//	this->next = next;
//}
//
//Neighbor::Neighbor(int vertexNum, Neighbor * next, double weight) {
//	this->vertexNum = vertexNum;
//	this->next = next;
//	this->weight = weight;
//}

Neighbor::~Neighbor(){}
