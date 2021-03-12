#include <iostream>
#include "linkedlist.h"
using namespace std;
// self referential structure

int main() {
	cout << "Data Structures and Algorithms\n";
	int A[] = { 10,20,30,40,50 };
	create(A, 5);
	display(first);
	cout << "\n\n";
	cout << "Sorted: " << isSorted(first) << endl;
	display(first);
	system("Pause");

	return 0;
}