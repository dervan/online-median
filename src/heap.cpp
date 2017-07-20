#include "heap.h"
#include "cstring"
#include "iostream"

template <typename Comparator>
Heap<Comparator>::Heap() {
  size = 0;
  max_size = 1024;
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
void Heap<Comparator>::fix_up(int index) {
  if (index == 0){
    return;
  }
  if (!Comparator()(values[parent(index)], values[index])){
    swap(parent(index), index);
    return fix_up(parent(index));
  }

}
