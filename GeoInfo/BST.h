// Template Binary Search Tree
#pragma once
#include "Node.h"
//#include "City.h"
#include <stddef.h>
#include <iostream>
#include <algorithm>

class BST
{
public:
	BST();
	~BST();
	void insert(City & key);
	bool deleteName(string val);
	// int height();
	
protected:
	void insert(Node *leaf, City key);
	Node * deleteName(string val, Node *parent, Node *child);
	City minValue();
	City minValue(Node * node);
	// int height(Node *node);
	Node *root;	// pointer to the root of the node
};