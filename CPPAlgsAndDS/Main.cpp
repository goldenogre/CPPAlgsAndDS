#include <iostream>
#include "linkedlist.h"
using namespace std;
// self referential structure

int main() {
	cout << "Data Structures and Algorithms\n";
	int A[] = { 10,20,30,40,50}; // size 5
	int B[] = { 5,15,25,35,45};
	create(A, 5);
	create2(B, 5);   // (array,size)
	display(first);
	display(second);
	//concat(first, second);
	merge(first, second);
	cout << "\n\n";
	display(third);

	system("Pause");

	return 0;
}