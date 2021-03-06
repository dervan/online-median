#include "heap.h"

#include <cstring>
#include <functional>

/* Adds new value to heap */
template <typename Comparator>
void Heap<Comparator>::AddValue(int new_value){
  Vector::AddValue(new_value);
  FixUp(size-1);
}

/* Deletes value on top of heap and restores heap properties */
template <typename Comparator>
int Heap<Comparator>::RemoveTop(){
  int ret = values[0];
  values[0] = values[size-1];
  size--;
  FixDown(0);
  return ret;
}

/* Returns index of left son in heap or -1 if this son does not exist */
template <typename Comparator>
int Heap<Comparator>::Left(int index) const {
  int left = 2*(index+1)-1;
  if (left >= size) {
    return -1;
  } else {
    return left;
  }
}

/* Returns index of right son in heap or -1 if this son does not exist */
template <typename Comparator>
int Heap<Comparator>::Right(int index) const {
  int right = 2*(index+1);
  if (right >= size) {
    return -1;
  } else {
    return right;
  }
}

/* Returns index of parent in heap */
template <typename Comparator>
int Heap<Comparator>::Parent(int index) const {
  return (index+1)/2 - 1;
}

/* Swap two values in heap */
template <typename Comparator>
void Heap<Comparator>::Swap(int a, int b) {
  int tmp = values[a];
  values[a] = values[b];
  values[b] = tmp;
}

/* Restores heap property by moving element lower if it's needed */
template <typename Comparator>
void Heap<Comparator>::FixDown(int index) {
  int largest = index;
  if (Left(index) != -1 &&
      Comparator()(values[Left(index)], values[largest])){
    largest = Left(index);
  }
  if (Right(index) != -1 && 
      Comparator()(values[Right(index)], values[largest])){
    largest = Right(index);
  }
  if (index != largest) {
    Swap(largest, index);
    FixDown(largest);
  }
  return;
}

/* Restores heap property by moving element higher if it's needed */
template <typename Comparator>
void Heap<Comparator>::FixUp(int index) {
  if (index == 0){
    return;
  }
  if (!Comparator()(values[Parent(index)], values[index])){
    Swap(Parent(index), index);
    return FixUp(Parent(index));
  }
}

/* Instances which helps to easlily integrate with other binaries */
template class Heap<std::greater<int> >;
template class Heap<std::less<int> >;
