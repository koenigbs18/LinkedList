/*
LinkedList.h
Author      : Brett Koenig
Email       : koenigbs18@uww.edu
Date        : 09/13/18
Description : A simple linked list with a focus on dynamic memory and useful
			  accessor functions and operators.
TODO        : Implement smart pointers to reduce overhead and prevent memory leaks.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <cstddef>

template <typename DataType>
class LinkedList {
private:
	/*
	Node struct contains two variables: pointer to the value stored 
	in the current node, and a pointer to another node in order to 
	iterate the linked list.
	*/
	template <typename DataType>
	struct Node {

		Node() : value(nullptr), next(nullptr) {};
		Node(DataType val) : next(nullptr) { value = new DataType;  *value = val; };

		DataType* value;
		Node* next;
	};
	Node<DataType>* list;
public:
	LinkedList();
	LinkedList(DataType);
	~LinkedList();

	DataType* front();
	DataType* back();

	void push_back(DataType);
	DataType pop_back();

	int size;

	DataType* operator[](const std::size_t index);
};

template<typename DataType>
inline DataType* LinkedList<DataType>::operator[](const std::size_t index){
	// access violation
	if (index > size-1 || size == 0) {
		throw std::out_of_range("index out of bounds");
		return NULL;
	}

	Node<DataType>* temp = list;
	for (int i = 0; i < index; i++)
		temp = temp->next;
	// return pointer to value
	return temp->value;
}


template <typename DataType>
LinkedList<DataType>::LinkedList() {
	list = new Node<DataType>();
	size = 0;
}

template <typename DataType>
LinkedList<DataType>::LinkedList(DataType val) {
	list = new Node<DataType>(val);
	size = 1;
}

// free memory of nodes upon calling delete on class
template <typename DataType>
LinkedList<DataType>::~LinkedList() {
	if (size == 0) {
		return;
	}
	Node<DataType>* n = list->next;
	while (n != nullptr) {
		delete list->value;
		delete list;
		list = n;
		n = n->next;
	}

	delete list->value;
	delete list;
	list = nullptr;
}

// add a node to the list
template <typename DataType>
void LinkedList<DataType>::push_back(DataType val) {
	if (size == 0) {
		list = new Node<DataType>(val);
		size++;
		return;
	}

	Node<DataType>* n = list;
	while (n->next != nullptr)
		n = n->next;
	n->next = new Node<DataType>(val);
	size++;
}

// remove a node from the list, returns the value popped
template <typename DataType>
DataType LinkedList<DataType>::pop_back() {
	if (size == 0) {
		throw std::out_of_range("no elements to pop from list");
		return NULL;
	}
	// get last node and save the value for return
	Node<DataType>* n = list;
	while (n->next->next != nullptr)
		n = n->next;
	DataType val = *n->next->value;
	// free memory of node
	delete n->next->value;
	delete n->next;
	n->next = nullptr;
	size--;
	return val;
}

template <typename DataType>
DataType* LinkedList<DataType>::front() {
	if (size == 0) {
		throw std::out_of_range("no elements in array");
		return NULL;
	}
	return list->value;
}

template <typename DataType>
DataType* LinkedList<DataType>::back() {
	if (size == 0) {
		throw std::out_of_range("no elements in array");
		return NULL;
	}
	return list[size];
}

#endif