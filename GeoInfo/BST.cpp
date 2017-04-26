#include "BST.h"
#include <string.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
# include <cmath>
# include <limits>



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
bool BST::deleteByName(string val)
{
	if (root == NULL) {
		return false;
	}
	else if (root->data.name == val) {
		//delete root
		Node *tempNode = new Node();
		tempNode->left = root;
		Node *nodeToRemove = deleteByName(val, tempNode, root);
		root = tempNode->left;
		if (nodeToRemove != NULL) {
			delete nodeToRemove;
			return true;
		}
		return false;
	}
	else {
		Node *nodeToRemove = deleteByName(val, NULL, root);
		if (nodeToRemove != NULL) {
			delete nodeToRemove;
			return true;
		}
		return false;
	}
}

// recursive function to delete a city by name
Node * BST::deleteByName(string data, Node * parent, Node * child)
{
	if (data < child->data.name) {
		if (child->left != NULL) {
			return deleteByName(data, child, child->left);
		}
		return NULL;
	}
	else if (data > child->data.name) {
		if (child->right != NULL) {
			return deleteByName(data, child, child->right);
		}
		return NULL;
	}
	else {
		if (child->left != NULL && child->right != NULL) {
			child->data = minValue(child->right);
			return deleteByName(child->data.name, child, child->right);
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

// non-recursive function to delete a node by its coordinates
bool BST::deleteByCoords(double lat, double lon)
{
	// create coords pair from the lat and lon values
	std::pair  <double, double> val = make_pair(lat, lon);
	if (root == NULL) {
		return false;
	}
	else {
		// We need to find the correct city and then perform a delete
		Node *nodeToFind = searchByCoords(lat, lon);
		if(nodeToFind)
			deleteByName(nodeToFind->data.name);
		else
			return false;
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

// non-recursive function to search for a city by name  
Node * BST::searchByName(string name)
{
	return searchByName(name, root);
}

// recursive function to search for a city by name 
Node * BST::searchByName(string name, Node * leaf)
{
	if (leaf != NULL)
	{
		if (name == leaf->data.name)
			return leaf;
		if (name < leaf->data.name)
			return searchByName(name, leaf->left);
		else
			return searchByName(name, leaf->right);
	}
	else return NULL;
}

// non-recusrive function to search for a city using its coords
Node * BST::searchByCoords(double lat, double lon)
{
	pair <double, double> loc = make_pair(lat, lon);
	return searchByCoords(loc, root);
}
// recusrive function to search for a city using its coords
Node * BST::searchByCoords(pair<double, double> loc, Node * node)
{
	if (!node) {
		return NULL;
	}

	if (node->data.coords == loc) {
		return node;
	}

	Node *left = searchByCoords(loc, node->left);
	Node *right = searchByCoords(loc, node->right);

	if (left != NULL) {
		return left;
	}
	else if (right != NULL) {
		return right;
	}
}


// non-recusrive function to print nodes in order
void BST::printInOrder()
{
	if (root == NULL) {
		printf("Tree is empty!!");
	}
	else {
		printInOrder(root);
	}
}

// recusrive function to print nodes in order
void BST::printInOrder(Node * node)
{
	if (!node) // end the recursion if node == nullptr
		return;

	printInOrder(node->left);
	cout << node->data;
	printInOrder(node->right);

}
//	-----   Print cities within a distance
// non-recusrive function to print nodes in order
void BST::printWithinDistance(std::pair<double, double> point, int distance) 
{
	if (root == NULL) {
		printf("Tree is empty!!");
	}
	else {
		printWithinDistance(root, point, distance);
	}
}

// recusrive function to print nodes in order
void BST::printWithinDistance(Node * node, std::pair<double, double> point, int distance)
{
	if (!node) // end the recursion if node == nullptr
		return;

	printWithinDistance(node->left, point, distance);
	// Perform logic here  distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d)
	double point1 = distanceEarth(node->data.coords.first, node->data.coords.second, point.first, point.second);
	if (point1 < distance)
		cout << node->data;
	printWithinDistance(node->right, point, distance);

}

// Non-recursive public function to obtain the hegiht of the tree
int BST::height(Node * node)
{
	if (node == NULL) {
		return 0;
	}
	int left = height(node->left);
	int right = height(node->right);

	return max(left, right);
}
// Recursive function to obtain the height of the tree
int BST::height()
{
	if (root == NULL)
	{
		return -1;
	}
	else
		return height(root);
}






