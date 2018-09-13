/*
main.cpp
Author      : Brett Koenig
Email       : koenigbs18@uww.edu
Date        : 09/13/18
Description : Example usage of functions contained in "LinkedList.h"
TODO        : Implement smart pointers to reduce overhead and prevent memory leaks.
*/

#include <iostream>
#include <Windows.h>
#include "LinkedList.h"

int main() {
	LinkedList<double> test(1.0);
	test.push_back(2.4);
	test.push_back(24.3);
	test.push_back(7932.123);
	test.push_back(90412.31290);
	*test[0] = 3.65;
	std::cout << "Front: " << *test.front();
	std::cout << "\nPos[3]: " << *test[3];
	std::cout << "\nSize: " << test.size;
	std::cout << "popped value: " << test.pop_back();
	return 0;
}