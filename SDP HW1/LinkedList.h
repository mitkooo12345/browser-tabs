#include <time.h>
#include <iostream>

#pragma once
class LinkedList {

public:
	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	~LinkedList();

public:
	void back();
	void forward();
	void go(char*);
	void remove();
	void insert(char*);
	void print();

private:
	struct Node {
		char* url;
		time_t timestamp;
		Node* nextNode;
		Node* prevNode;
	};

private:
	void deleteList();
	void createEmptyNode();
	Node* getNode(int);

private:
	Node* root;
	Node* currentNode;
	Node* lastNode;
	int size;
};

