# include "BST.h"

# include <iostream>
# include <cstdlib>
# include <string>
# include <math.h>
using namespace std;

int main() {

	BST GPSTree;	// Tree of City information
	City Dublin("Dublin", 53.3498, -6.2603, 553000, 10.5);
	City Cork("Cork", 51.8969, -8.4863, 800000, 11.2);
	City Liverpool("Liverpool", 53.4084, -2.9916, 478600, 6.2);
	City NewYork("New York",40.7128, -74.0054, 8478600, 16.2);
	City LA("Los Angeles", 34.03, -118.15, 3900000, 18.6);
	City Toronto("Toronto", 43.42, -79.24, 2731571, 9);
	City Vegas("Las Vegas", 36.1699, -115.1398, 603488,18.3);
	City Belfast("Belfast", 1700000, 54.5973, 5.9301, 1.5);
	City Vancouver("Vancouver", 1700000, 23.4326, 99.1332, 15.5);
	City Texas("Texas", 1700000, 90.7326, 99.1332, 15.5);


	cout << "Tree height before any inserts: " << GPSTree.height() << endl;
	GPSTree.insert(Liverpool);
	cout << "Tree height before after 1 insert: " << GPSTree.height() << endl;


	GPSTree.insert(Dublin);
	GPSTree.insert(Cork);
	GPSTree.insert(NewYork);
	GPSTree.insert(LA);
	GPSTree.insert(Toronto);
	GPSTree.insert(Vegas);
	GPSTree.insert(Belfast);
	GPSTree.insert(Vancouver);
	GPSTree.insert(Texas);

	string input; // used for search querys
	double lat, lon;
	//
	GPSTree.printWithinDistance(make_pair(53.3498, -6.2603), 800);
	GPSTree.printInOrder();
	// Search for a city by name
	cout << "		---------" << endl;
	cout << "Enter name to search for a city: " << endl;
	input = "Liverpool";
	Node* nameCity = GPSTree.searchByName(input);
	cout << "\nSearching for " << input << endl;
	if (nameCity != NULL) {
		cout << "Found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	
	// Search for a city by coordinates
	
	cout << "		---------\nNext, lets search by coordinates!\n" << endl;
	lat = 34.03;
	lon = -118.15;
	cout << "\nSearching for city at " << lat << ", " << lon << endl;

	Node* coordCity = GPSTree.searchByCoords(lat, lon);
	
	if (coordCity != NULL) {
		cout << "Found: " << coordCity->getName() << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	//Delete a city by name
	cout << "		---------" << endl;
	input = "Las Vegas";
	cout << "Lets delete " << input << endl;
	
	if (GPSTree.deleteByName(input) == true) {
		cout << "Deleted " << input << endl;
	}
	else
	{
		cout << input << " not found!!" << endl;
	}
	input = "Las Vegas";
	cout << "Lets try delete Berlin: " << endl;	
	if (GPSTree.deleteByName(input) == true) {
		cout << "Deleted " << input << endl;
	}
	else
	{
		cout << input << " not found!!" << endl;
	}
	
	// Delete a city by coordinates
	cout << "		---------\nNext, lets delete a city by coordinates!\n" << endl;
	lat = 34.03;
	lon = -118.15;	// 34.03, -118.15 = Los Angeles
	coordCity = GPSTree.searchByCoords(lat, lon);
	string name = coordCity->getName();	// Store the name of the city before we delete the node
	if( GPSTree.deleteByCoords(lat,lon) == true) {
		cout << "Deleteted : " << name << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	cout << "	----------" << endl;
	GPSTree.printInOrder();

	
	system("pause");
}