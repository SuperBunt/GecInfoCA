#include "BST.h"
#include <string.h>
#include <iostream>

/***************************************************************************************

*    Usage: Based on
*    Title: Binary Trees in C++: Part 1
*    Author: Alex Allain
*    Date: ?
*    Availability: http://elearning.it-tallaght.ie/mod/page/view.php?id=242177
*
***************************************************************************************/

// Default Constructor
BST::BST()
{
}

// Destructor
BST::~BST()
{
}

// non recursive insert 
void BST::insert(City & data)
{
	if (root == NULL) {
		root = new Node(data);
	}
	else
	{
		insert(root, data);
	}
}


// recursive insert which checks for unique co-ordinates
void BST::insert(Node * leaf, City val)
{
	if (val.name <= leaf->data.name && val.coords != leaf->data.coords) {
		if (leaf->left != NULL)
			insert(leaf->left, val);
		else {
			leaf->left = new Node(val);
		}
	}
	else if (val.name > leaf->data.name && val.coords != leaf->data.coords) {
		if (leaf->right != NULL)
			insert(leaf->right, val);
		else {
			leaf->right = new Node(val);
		}
	}
	else if (val.coords == leaf->data.coords) {
		return;
	}
}



// Non recursive function to delete a city by name
bool BST::deleteName(string val)
{
	if (root == NULL) {
		return false;
	}
	else if (root->data.name == val) {
		//delete root
		Node *tempNode = new Node();
		tempNode->left = root;
		Node *nodeToRemove = deleteName(val, tempNode, root);
		root = tempNode->left;
		if (nodeToRemove != NULL) {
			delete nodeToRemove;
			return true;
		}
		return false;
	}
	else {
		Node *nodeToRemove = deleteName(val, NULL, root);
		if (nodeToRemove != NULL) {
			delete nodeToRemove;
			return true;
		}
		return false;
	}
}
// recursive function to delete a city by name
Node * BST::deleteName(string data, Node * parent, Node * child)
{
	if (data < child->data.name) {
		if (child->left != NULL) {
			return deleteName(data, child, child->left);
		}
		return NULL;
	}
	else if (data > child->data.name) {
		if (child->right != NULL) {
			return deleteName(data, child, child->right);
		}
		return NULL;
	}
	else {
		if (child->left != NULL && child->right != NULL) {
			child->data = minValue(child->right);
			return deleteName(child->data.name, child, child->right);
		}
		else if (parent->left == child) {
			if (child->left != NULL)
			{
				parent->left = child->left;
			}
			else {
				parent->left = child->right;
			}
			return child;
		}
		else if (parent->right == child) {
			if (child->left != NULL) {
				parent->right = child->left;
			}
			else {
				parent->right = child->right;
			}
			return child;
		}
	}
}


City BST::minValue()
{
	return (minValue(root));
}

City BST::minValue(Node * node)
{
	if (node->left != NULL) {
		return minValue(node->left);
	}
	return node->data;
}



