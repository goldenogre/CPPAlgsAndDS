#include <iostream>
//#include "linkedlist.h"
#include "Linked.h"
using namespace std;
// self referential structure


int main() {
	cout << "Using class LL\nData Structures and Algorithms\n";
	int A[] = { 10,20,30,40,50}; // size 5
	int B[] = { 5,15,25,35,45};
	LinkedList list(A,5);
	
	// cout <<
	list.Insert(0, 1);// << endl;
	list.Display();
	system("Pause");

	return 0;
}