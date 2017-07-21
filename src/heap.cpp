#include "heap.h"
#include "cstring"
#include "iostream"

template <typename Comparator>
Heap<Comparator>::Heap() {
  size = 0;
  max_size = 4;
  values = new int[max_size];
}

template <typename Comparator>
int Heap<Comparator>::get_size(){
  return size;
}

template <typename Comparator>
int Heap<Comparator>::get_top() {
  return values[0];
}

template <typename Comparator>
void Heap<Comparator>::increase_size(int new_size) {
    int * new_values = new int[new_size];
    std::memcpy(new_values, values, sizeof(int)*size);
    delete values;
    values = new_values;
    std::cout << "Resizing to " << new_size << "\n";
    max_size = new_size;
}

template <typename Comparator>
void Heap<Comparator>::push(int value){
  if(size==max_size){
    increase_size(2*max_size);
  }
  values[size] = value;
  fix_up(size);
  size++;
}

template <typename Comparator>
int Heap<Comparator>::pop(){
  int ret = values[0];
  values[0] = values[size-1];
  size--;
  fix_down(0);
  return ret;
}

template <typename Comparator>
int Heap<Comparator>::left(int index){
  int left = 2*(index+1)-1;
  if (left >= size) {
    return -1;
  } else {
    return left;
  }
}

template <typename Comparator>
int Heap<Comparator>::right(int index){
  int right = 2*(index+1);
  if (right >= size) {
    return -1;
  } else {
    return right;
  }
}


template <typename Comparator>
int Heap<Comparator>::parent(int index){
  return index/2;
}

template <typename Comparator>
void Heap<Comparator>::swap(int a, int b) {
  int tmp = values[a];
  values[a] = values[b];
  values[b] = tmp;
}

template <typename Comparator>
void Heap<Comparator>::fix_down(int index) {
  int largest = index;
  if (left(index) != -1 &&
      Comparator()(values[left(index)], values[largest])){
    largest = left(index);
  }
  if (right(index) != -1 && 
      Comparator()(values[right(index)], values[largest])){
    largest = right(index);
  }
  if (index != largest) {
    swap(largest, index);
    fix_down(largest);
  }
  return;
}
template <typename Comparator>
void Heap<Comparator>::fix_up(int index) {
  if (index == 0){
    return;
  }
  if (!Comparator()(values[parent(index)], values[index])){
    swap(parent(index), index);
    return fix_up(parent(index));
  }
}

template class Heap<std::greater<int> >;
template class Heap<std::less<int> >;
