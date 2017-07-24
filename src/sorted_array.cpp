#include <iostream>
#include <cstring>
#include "sorted_array.h"

SortedArray::SortedArray() {
  size = 0;
  max_size = 1024;
  values = new int[max_size];
  copy_buffer = new int[max_size];
}

void SortedArray::IncreaseSize(int new_size) {
  int * new_values = new int[new_size];
  std::memcpy(new_values, values, sizeof(int)*size);
  delete values;
  delete copy_buffer;
  values = new_values;
  copy_buffer = new int[new_size];
  max_size = new_size;
}

void SortedArray::ShiftUp(int position) {
  int copy_length = size-position;
  std::memcpy(copy_buffer, &values[position], sizeof(int)*copy_length);
  std::memcpy(&values[position+1], copy_buffer, sizeof(int)*copy_length);
  size++;
}

int SortedArray::LowerBound(int value) const {
  if (size == 0) {
    return 0;
  }

  int position = 0;
  int left = 0; // first candidate for first bigger number
  int right = size; // last candidate ...
  /* During whole loop left is first number that possibly
   * may be bigger than value. On the other hand, right is
   * last possible value.
   * position just helps to decrease search space */
  while (right - left > 0) {
    position = (left + right) / 2;
    if (values[position] < value) {
      left = position + 1;//left is still smaller
    } else {
      right = position; //right is still bigger
    }
  }
  return left;
}

void SortedArray::AddValue(int value) {
  if (size==max_size) {
    IncreaseSize(2*max_size);
  }
  int position = LowerBound(value);
  ShiftUp(position);
  values[position] = value;
}

int * SortedArray::GetValues() const {
  int * return_values = new int[size];
  std::memcpy(return_values, values, sizeof(int)*size);
  return return_values;
}

