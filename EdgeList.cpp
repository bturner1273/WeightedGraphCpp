#include "EdgeList.h"

void EdgeList::tailInsert(int vertexNum, double weight) {
	Edge *temp = new Edge();
	temp->vertexNum = vertexNum;
	temp->weight = weight;
	temp->next = NULL;
	if (head == NULL) {
		head = tail = temp;
		count++;
	}
	else {
		tail->next = temp;
		tail = temp;
		temp = NULL;
		count++;
	};
}

string EdgeList::toString() {
	Edge * cursor = head;
	string toReturn = "";
	toReturn += "Connected to:\n";
	while (cursor != NULL) {
		toReturn += "\tVertex " + to_string(cursor->vertexNum) + " with weight " + to_string(cursor->weight) + "\n";
		cursor = cursor->next;
	}
	return toReturn;
}

EdgeList::EdgeList() {
	head = NULL;
	tail = NULL;
}
void EdgeList::headRemove() {
	if (size() > 0) {
		head = head->next;
		count--;
	}
	else throw logic_error("Cannot remove from empty list");
}
void EdgeList::tailRemove() {
	if (size() > 0) {
		Edge *temp;
		temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		tail = temp;
		tail->next = NULL;
	}
	else throw logic_error("Cannot remove from empty list");
}
EdgeList::EdgeList(const EdgeList* copyLst) {
	const Edge *cpCurrent = copyLst->head;
	Edge *lsCurrent = NULL;
	if (cpCurrent != NULL) {
		head = new Edge();
		head->vertexNum = cpCurrent->vertexNum;
		head->weight = cpCurrent->weight;
		lsCurrent = head;
		cpCurrent = cpCurrent->next;
		count++;
	}
	while (cpCurrent != NULL) {
		Edge *newNode = new Edge();
		newNode->vertexNum = cpCurrent->vertexNum;
		newNode->weight = cpCurrent->weight;
		lsCurrent->next = newNode;
		lsCurrent = lsCurrent->next;
		cpCurrent = cpCurrent->next;
		count++;
	}
}


//used by insertion sort
void EdgeList::sortedInsert(Edge **head_ref, Edge *new_node) {
	Edge *current;
	if (*head_ref == NULL || (*head_ref)->weight >= new_node->weight)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		current = *head_ref;
		while (current->next != NULL && current->next->weight < new_node->weight) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void EdgeList::insertionSort(Edge **headRef) {
	Edge *sorted = NULL;
	Edge *current = *headRef;
	while (current != NULL)
	{
		Edge *next = current->next;
		sortedInsert(&sorted, current);
		current = next;
	}
	*headRef = sorted;
}


EdgeList::~EdgeList() {
	clear();
}

void EdgeList::headInsert(int vertexNum, double weight) {
	Edge *temp = new Edge();
	temp->vertexNum = vertexNum;
	temp->weight = weight;
	temp->next = head;
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		head = temp;
	}
	count++;
}

int EdgeList::size() {
	return count;
}

void EdgeList::clear() {
	head = NULL;
	count = 0;
}

bool EdgeList::empty() {
	return head == NULL;
}

void EdgeList::posInsert(int pos, int vertexNum, double weight) {
	if (pos > size()) {
		throw logic_error("Cannot position insert past the end of the list, it would leave holes");
	}
	Edge *pre = new Edge;
	Edge *cur = new Edge;
	Edge *temp = new Edge;
	cur = head;
	for (int i = 1; i<pos; i++) {
		pre = cur;
		cur = cur->next;
	}
	temp->vertexNum = vertexNum;
	temp->weight = weight;
	pre->next = temp;
	temp->next = cur;
	count++;
}


Edge EdgeList::retrieve(int pos) {
	pos -= 1;
	Edge *node = new Edge;
	node = head;
	if (pos > size()) {
		throw logic_error("Position entered is not yet filled in the list, retrieval would result in a garbage value. List size = " + to_string(size()));
	}
	else {
		for (int i = 0; i < pos; i++) {
			node = node->next;
		}
		return *node;
	}
}

void EdgeList::posRemove(int pos) {
	if (pos > 0)
		pos -= 1;
	if (pos > size()) {
		throw logic_error("Position entered is not yet filled in the list, retrieval would result in a garbage value. List size = " + to_string(size()));
	}
	if (head == NULL)
		return;

	Edge *temp = head;
	if (pos == 0)
	{
		head = temp->next;
		free(temp);
		count--;
		return;
	}
	for (int i = 0; temp != NULL && i<pos - 1; i++)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
		return;
	if (temp->next == tail) {
		tail = temp;
	}
	Edge *next = temp->next->next;
	free(temp->next);
	temp->next = next;
	count--;
}

EdgeList& EdgeList :: operator=(EdgeList &list) {
	const Edge *cpCurrent = list.head;
	Edge *lsCurrent = NULL;
	if (cpCurrent != NULL) {
		head = new Edge();
		head->vertexNum = cpCurrent->vertexNum;
		head->weight = cpCurrent->weight;
		lsCurrent = head;
		cpCurrent = cpCurrent->next;
		count++;
	}
	while (cpCurrent != NULL) {
		Edge *newNode = new Edge();
		newNode->vertexNum = cpCurrent->vertexNum;
		newNode->weight = cpCurrent->weight;
		lsCurrent->next = newNode;
		lsCurrent = lsCurrent->next;
		cpCurrent = cpCurrent->next;
		count++;
	}
	return *this;
}

void EdgeList::replace(int pos, int vertexNum, double weight) {
	pos -= 1;
	if (pos > size()) {
		throw logic_error("Position entered is not yet filled in the list, retrieval would result in a null pointer. List size = " + to_string(size()));
	}
	Edge *temp = head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	temp->vertexNum = vertexNum;
	temp->weight = weight;
}

