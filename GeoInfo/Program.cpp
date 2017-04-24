# include "BST.h"

# include <iostream>
# include <cstdlib>
# include <string>
using namespace std;

int main() {

	BST GPSTree;	// Tree of City information
	City Dublin("Dublin", 53.3498, -6.2603, 553000, 10.5);
	City Cork("Cork", 51.8969, -8.4863, 800000, 11.2);
	City Liverpool("Liverpool", 53.4084, -2.9916, 478600, 6.2);
	City ops("Oops", 53.4084, -2.9916, 478600, 6.2);

	cout << Dublin;
	cout << Cork;
	cout << Liverpool;

	GPSTree.insert(Dublin);
	GPSTree.insert(Cork);
	GPSTree.insert(Liverpool);
	GPSTree.insert(ops);
	system("pause");
}