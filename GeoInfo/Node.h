// Node that stores City object and left, right pointers 

#pragma once
#include <stddef.h>
#include "City.h"


class Node
{
	friend class BST;
public:
	Node();
	Node(City val);
	~Node();
	Node *left;
	Node *right;
	bool isLeaf();
	string getName();
protected:
	City data;
};


