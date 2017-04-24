#include "Node.h"
#include <string.h>
#include <iostream>

Node::Node()
{
	left = right = NULL;
}

Node::Node(City val)
{
	data = val;
}

Node::~Node()
{
}

bool Node::isLeaf()
{
	return false;
}
