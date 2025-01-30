/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

void printList(Node* head);

int main(int argc, char* argv[])
{
  Node* in = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));

  Node* odds;
  Node* evens;

  split(in, odds, evens);

  printList(in);
  printList(odds);
  printList(evens);
}

void printList(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->value << " -> ";
		temp = temp->next;
	}
	std::cout << "nullptr" << std::endl;
}