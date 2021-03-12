#pragma once
#include <iostream>
//#include <limits.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
}*first = nullptr, *last = nullptr; // global pointer
int count(struct Node *p) {
	int c = 0;
	while (p) {
		c++;
		p = p->next;
	}
	return c;
}
int rCount(struct Node *p) {
	if (!p) {
		return 0;
	}
	else {
		return rCount(p->next) + 1;
	}
}
void create(int A[], int n) {
	int i;
	struct Node *t;
	//struct Node *last; // used for adding
	// creating first node
	first = new struct Node;
	first->data = A[0];
	first->next = nullptr;
	last = first;
	// it with forloop
	for (i = 1; i < n; i++) {
		t = new Node;			// 1. New node
		t->data = A[i];			// 2. Assign new value
		t->next = nullptr;		// 3. Assign *next as null
		last->next = t;			// 4. previous last node.next value points to new node
		last = t;				// 5. last changed top new node
	}

}
int max(struct Node *p) {
	int max = INT32_MIN; // smallest possible int
	while (p) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}
int rMax(struct Node *p) {
	int x = 0;
	if (!p) {
		return INT32_MIN;
	}
	x = rMax(p->next);
	if (x > p->data) {
		return x;
	}
	else {
		return p->data;
	}
}
int sum(struct Node *p) {
	int sum = 0;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}
int rSum(struct Node *p) {

	if (!p) {
		return 0;
	}
	else {
		return rSum(p->next) + p->data;
	}
}
void display(struct Node *p) {
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "null\n";
}
void rDisplay(struct Node *p) {
	// terminate
	if (p) {
		rDisplay(p->next);
		cout << p->data << endl;

	}
}
Node* rSearch(struct Node *p, int key) {
	if (!p) {
		return nullptr;
	}
	if (key == p->data) {
		return p;
	}
	return rSearch(p->next, key);
}
Node* rImprovedSearch(struct Node *p, int key) {
	
	if(!p) {
		return nullptr;
	}
	if (key == p->data) {
		return p;
	}
	return rImprovedSearch(p->next, key);
}
Node* improvedSearch(struct Node *p, int key) {
	Node *q = nullptr;
	while (p) {
		if (p->data == key) {
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return nullptr;
	
}
Node* search(struct Node *p, int key) {
	while (p){
		if (p->data == key) {
			//return and stop
			return p; // address pof node
		}
		p = p->next;
	}
	return NULL;
}
void insertFirstNode(int d) {
	struct Node *newNode = new Node;
	newNode->data = d;
	newNode->next = first;
	first = newNode;
}

void insertAfterNode(int position, int d) {
	struct Node *t,*p;
	if (position == 0) {
		t = new Node;
		t->data = d;
		t->next = first;
		first = t;
	}
	else if (position > 0) {
		
		p = first;
		for (int i = 0; i < position - 1 && p; i++) {
			p = p->next;
		}
		t = new Node;
		t->data = d;
		t->next = nullptr;
		t->next = p->next;
		p->next = t;
	}
}
void insertLast(int d) {
	struct Node *t = new Node;
	t->data = d;
	t->next = nullptr;
	if (first == nullptr) {
		first = last = t; // means list is empty. 
	}
	else {
		last->next = t;
		last = t;
	}
	
}
void sortedInsert(struct Node *p, int d) {
	struct Node *t, *q=nullptr;
	t = new Node;
	t->data = d;
	t->next = nullptr;
	// no nodes case 1
	if (!first) {
		first = t;
	}
	else {
		while (p && p->data < d) {
			q = p;
			p = p->next;

		}
		// if data is the smallest case 2
		if (p == first) {
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;

		}
	}

}
// move pointers, but deallocate that node!
int deleteNode(struct Node *p, int index) {
	struct Node *q = nullptr;
	int x = -1;
	// index must be valid
	if (index < 0 || index > count(p)) {
		return x;
	}
	if (index == 1) {
		q = first;
		x = first->data;
		first = first->next;
		delete q;
	}
	else {
		for (int i = 0; i < index-1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}
bool isSorted(struct Node *p) {
	int x = INT32_MIN;
	while (p) {
		if(p->data < x){
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;

}
void removeDuplicates(struct Node *p) {
	struct Node *q = p->next;
	while (q) { // a nullptr on q means end of list
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			delete q;
			q = p->next;
		}
		
		
	}

}
void reverseListElements(struct Node *p) {
	
}
void reverseLinks(struct Node *p) {
	struct Node *r, *q;
	p = first;
	q = nullptr;
	r = nullptr;
	while (p) {
		// sliding r q p
		r = q;
		q = p;
		p = p->next;
		// q take linke and points it to r instead of where p is (next);
		q->next = r;
	}
	first = q;
}