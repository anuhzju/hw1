#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if (empty()){
    Item *newItem = new Item;
    head_ = tail_ = newItem;
    newItem -> val[tail_ -> last] = val;
    newItem -> last++;
  }
  else {
    if (tail_ -> last == 10){
      Item *newItem = new Item;
      newItem -> prev = tail_;
      newItem -> next = nullptr;
      tail_ -> next = newItem;
      tail_= newItem;

      newItem -> val[tail_ -> last] = val;
      newItem -> last++;
    }
    else {
      tail_ -> val[tail_ -> last] = val;
      tail_ -> last++;
    }
  }
  size_++;
}

void ULListStr::pop_back()
{
  if (tail_ -> last == 1){
    Item *temp = tail_;
    if (tail_ -> prev != nullptr){
      tail_ = tail_ -> prev;
      tail_ -> next = nullptr;
    }
    else {
      head_ = tail_ = nullptr;
    }
    delete temp;
  }
  else {
    tail_ -> last--;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ != nullptr){
    if (head_ -> first == 0){
      Item *newItem = new Item;

      newItem -> next = head_;
      newItem -> prev = nullptr;
      head_ -> prev = newItem;
      head_ = newItem;
    
      newItem -> first = 9;
      newItem -> last = 10;
      newItem -> val[newItem -> first] = val;
    }
    else {
      head_ -> first--;
      head_ -> val[head_ -> first] = val;
    }
  }
  else {
    Item *newItem = new Item;
    newItem -> last = 10;
    newItem -> first = 9;
    newItem -> val[newItem -> first] = val;
    head_ = tail_ = newItem;
  }
  size_++;
}

void ULListStr::pop_front()
{ 
  if (head_ != nullptr && size_ > 0){
    if (head_ -> first == head_ -> last -1){
      Item *temp = head_;
      if (head_ -> next == nullptr){
        head_ = tail_ = nullptr;
      }
      else{
        head_ = head_ -> next; 
        head_ -> prev = nullptr;
      }
      temp -> next = temp -> prev = nullptr;
      delete temp;
    }
    else{
      head_ -> first++;
    }
    size_--;
  }
  else{
    size_ = 0;
  }
}

std::string const & ULListStr::back() const
{
  return tail_ -> val[(tail_->last) - 1];
}

std::string const & ULListStr::front() const
{
  return head_ -> val[head_ -> first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc < size_){
    Item *temp = head_;
    while (temp != nullptr){

      size_t ind = temp -> last - temp -> first;
      if (loc < ind){
        return &temp -> val[temp -> first + loc];
      }

      loc-= ind; 
      temp = temp -> next;
    }
  }
  return nullptr;
}