#include "City.h"
#include <string.h>
#include <iostream>

City::City() { }

City::City(string name_in, double lat, double lon, int pop, float temp) {
	name = name_in;
	coords = make_pair(lat, lon);
	population = pop;
	avg_temp = temp;
}

City::~City()
{
}


string City::getName()
{
	return name;
}

ostream& operator<<(ostream& os, const City& city)
{
	os << "Name: " << city.name << "\tPopulation: " << city.population << "\nCo-ordinates: Latitude:" << city.coords.first << " Longitude: " << city.coords.second <<  endl;
	return os;
}