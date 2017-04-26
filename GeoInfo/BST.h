// Template Binary Search Tree
#pragma once
#include "Node.h"
//#include "City.h"
#include <stddef.h>
#include <iostream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
# include <cmath>

class BST
{
public:
	BST();
	~BST();
	void insert(City & key);
	bool deleteByName(string val);
	bool deleteByCoords(double lat, double lon);
	Node * searchByName(string name); 
	Node * searchByCoords(double lat, double lon);
	void printInOrder();
	void printWithinDistance(std::pair<double, double> loc, int distance); 
	int height();
	
protected:
	void insert(Node *leaf, City key);
	Node * deleteByName(string val, Node *parent, Node *child);
	City minValue();
	City minValue(Node * node);
	int height(Node *node);
	Node * searchByName(string name, Node * leaf);
	Node * searchByCoords(std::pair<double, double> loc, Node * node); 
	void printInOrder(Node *node);
	void printWithinDistance(Node *node, std::pair<double, double> point, int distance);
	Node *root;	// pointer to the root of the node

/***************************************************************************************

*    Usage: Copied
*    Title: Calculating the distance between 2 latitudes and longitudes that are saved in a text file?
*    Author: MrTJ
*    Date: 22/04/2017
*    Availability: http://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a */

	const double earthRadiusKm = 6371.0;
	inline double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
		double lat1r, lon1r, lat2r, lon2r, u, v;
		lat1r = deg2rad(lat1d);
		lon1r = deg2rad(lon1d);
		lat2r = deg2rad(lat2d);
		lon2r = deg2rad(lon2d);
		u = sin((lat2r - lat1r) / 2);
		v = sin((lon2r - lon1r) / 2);
		return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
	};

	// This function converts decimal degrees to radians
	inline double deg2rad(double deg) {
		return (deg * M_PI / 180);
	}

	//  This function converts radians to decimal degrees
	double rad2deg(double rad) {
		return (rad * 180 / M_PI);
	}
//***************************************************************************************/
};