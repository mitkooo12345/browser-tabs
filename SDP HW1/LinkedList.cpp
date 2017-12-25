#include "LinkedList.h"

LinkedList::LinkedList() {
	createEmptyNode();
}

LinkedList::LinkedList(const LinkedList &list) {
	this->currentNode = list.currentNode;
	this->lastNode = list.lastNode;
	this->root = list.root;
	this->size = list.size;
}

LinkedList& LinkedList::operator=(const LinkedList& list) {
	if (this != &list) {
		this->currentNode = list.currentNode;
		this->lastNode = list.lastNode;
		this->root = list.root;
		this->size = list.size;
	}
	
	return *this;
}

LinkedList::~LinkedList() {
	deleteList();
}

void LinkedList::back() {
	if (currentNode->prevNode != nullptr) {
		currentNode = currentNode->prevNode;
	}
}

void LinkedList::forward() {
	if (currentNode->nextNode != nullptr) {
		currentNode = currentNode->nextNode;
	}
}

void LinkedList::go(char* url) {
	currentNode->timestamp = time(NULL);
	delete[] currentNode->url;
	currentNode->url = url;
}

void LinkedList::remove() {
	--size;

	if ((currentNode->nextNode != nullptr) && (currentNode->prevNode != nullptr)) {
		Node* prev = currentNode->prevNode;
		Node* next = currentNode->nextNode;

		delete[] currentNode;

		prev->nextNode = next;
		next->prevNode = prev;

		currentNode = next;

	} else if ((currentNode->nextNode != nullptr) && (currentNode->prevNode == nullptr)) {
		Node* next = currentNode->nextNode;

		delete[] currentNode;

		next->prevNode = nullptr;
		currentNode = next;
		root = next;

	} else if ((currentNode->nextNode == nullptr) && (currentNode->prevNode != nullptr)) {
		Node* prev = currentNode->prevNode;

		delete[] currentNode;

		prev->nextNode = nullptr;
		currentNode = prev;
		lastNode = prev;

	} else {
		delete[] currentNode;
		createEmptyNode();
	}
}

void LinkedList::insert(char* url) {
	++size;

	if (currentNode->nextNode == nullptr) {
		Node* newNode = new Node();
		newNode->nextNode = nullptr;
		newNode->prevNode = currentNode;
		newNode->timestamp = time(NULL);
		newNode->url = url;
		currentNode->nextNode = newNode;

		currentNode = newNode;
		lastNode = newNode;

	} else {
		Node* next = currentNode->nextNode;
		Node* newNode = new Node();

		currentNode->nextNode = newNode;
		next->prevNode = newNode;

		newNode->nextNode = next;
		newNode->prevNode = currentNode;
		newNode->timestamp = time(NULL);
		newNode->url = url;

		currentNode = newNode;
	}
}

void LinkedList::print() {
	Node* tmp = root;
	for (int i = 0; i < size; ++i) {
		if (tmp == currentNode) {
			std::cout << "> ";
		}

		std::cout << tmp->url << " " << tmp->timestamp << '\n';
		tmp = tmp->nextNode;
	}
}

void LinkedList::deleteList() {
	currentNode = root;
	for (int i = 0; i < size; ++i) {
		Node* nextNode = currentNode->nextNode;
		delete[] currentNode;
		currentNode = nextNode;
	}
	size = 0;
}

LinkedList::Node* LinkedList::getNode(int pos) {
	Node* tmp = root;
	for (int i = 0; i < pos; ++i) {
		tmp = tmp->nextNode;
	}

	return tmp;
}


void LinkedList::createEmptyNode() {
	root = new Node();
	root->nextNode = nullptr;
	root->prevNode = nullptr;
	currentNode = root;
	root->timestamp = time(NULL);

	char* defaultPage = "about:blank";
	int size = strlen(defaultPage) + 1;

	char* urlArr = new char[size];
	for (int i = 0; i < size; ++i) {
		urlArr[i] = defaultPage[i];
	}

	root->url = urlArr;

	this->size+=1;
}

