#ifndef CITY_H_
#define CITY_H_
#pragma once
#include <string>
using namespace std;

class City
{
	friend class BST;
public:
	City();
	City(string name_in, double lat, double lon, int pop, float temp);
	~City();
	friend ostream& operator<<(ostream& os, const City& city);
	string getName();
protected:
	std::string name;
	std::pair <double, double> coords;
	int		population;
	float	avg_temp;
};
#endif