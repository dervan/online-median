#include "heap.h"
#include "cstring"
#include "functional"

template <typename Comparator>
Heap<Comparator>::Heap() {
  size = 0;
  max_size = 4;
  values = new int[max_size];
}

template <typename Comparator>
void Heap<Comparator>::IncreaseSize(int new_size) {
    int * new_values = new int[new_size];
    std::memcpy(new_values, values, sizeof(int)*size);
    delete[] values;
    values = new_values;
    max_size = new_size;
}

template <typename Comparator>
void Heap<Comparator>::AddValue(int value){
  if(size==max_size){
    IncreaseSize(2*max_size);
  }
  values[size] = value;
  FixUp(size);
  size++;
}

template <typename Comparator>
int Heap<Comparator>::RemoveTop(){
  int ret = values[0];
  values[0] = values[size-1];
  size--;
  FixDown(0);
  return ret;
}

template <typename Comparator>
int Heap<Comparator>::Left(int index) const {
  int left = 2*(index+1)-1;
  if (left >= size) {
    return -1;
  } else {
    return left;
  }
}

template <typename Comparator>
int Heap<Comparator>::Right(int index) const {
  int right = 2*(index+1);
  if (right >= size) {
    return -1;
  } else {
    return right;
  }
}


template <typename Comparator>
int Heap<Comparator>::Parent(int index) const {
  return (index+1)/2 - 1;
}

template <typename Comparator>
void Heap<Comparator>::Swap(int a, int b) {
  int tmp = values[a];
  values[a] = values[b];
  values[b] = tmp;
}

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

template class Heap<std::greater<int> >;
template class Heap<std::less<int> >;
