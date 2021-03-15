#pragma once
class Node {
public:
	int data;
	Node *next;
};
class LinkedList {
private:
	Node *first;
public:
	LinkedList() { first = nullptr; }
	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	void Insert(int index, int x);
	int Delete(int index);
	int Length();
};