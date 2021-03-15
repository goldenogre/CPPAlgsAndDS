#include "Linked.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList(int A[], int n) {
	int i;
	Node *t;
	Node *last = nullptr; // used for adding
	// creating first node
	first = new Node;
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
LinkedList::~LinkedList()
{
	Node *p = first;
	while (first) {
		first = first->next;
		delete p;
		p = first;
	}
}
void LinkedList::Display(){
	Node *p = first;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void LinkedList::Insert(int position, int d) {
	Node *t, *p;
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
int LinkedList::Delete(int index) {
	Node *p,*q = nullptr;
	int x = -1;
	// index must be valid
	if (index < 1 || index > Length()) {
		return x;
	}
	if (index == 1) {
		p = first;
		first = first->next;
		x = p->data;
		delete q;
	}
	else {
		p = first;
		for (int i = 0; i < index - 1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		
	}
	return x;
}
int LinkedList::Length() {
	Node *p = first;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}