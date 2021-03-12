#include <iostream>
#include "linkedlist.h"
using namespace std;
// self referential structure

int main() {
	cout << "Data Structures and Algorithms\n";
	int A[] = { 10,20,30,40,50}; // size 5
	create(A, 5);								// (array,size)
	display(first);
	cout << "\n\n";
	
	reverseLinks(first);

	display(first);
	system("Pause");

	return 0;
}