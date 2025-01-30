/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in != nullptr) {

    Node * restOfList = in -> next;
    in -> next = nullptr;

	  //even
    if (in->value % 2 == 0) {
      evens = in;
      split(restOfList, odds, evens -> next);
    }

    //odd
    else {
      odds = in;
      split(restOfList, odds -> next, evens);
    }
  }
  in = nullptr;
}