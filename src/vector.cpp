#include <cstring>
#include <iostream>
#include <stdexcept>
#include "vector.h"

Vector::Vector(int start_size) {
  max_size = start_size;
  size = 0;
  values = new int[max_size];
}

Vector::~Vector() {
  delete[] values;
}

Vector::Vector(const Vector &base_vector) {
  max_size = base_vector.max_size;
  size = base_vector.size;
  std::memcpy(values, base_vector.values, size);
}

/* Increases size of vector. Should print error and 
 * do nothing if new size is too smal */
void Vector::ExpandSize(int new_size){
  if (new_size < size) {
    std::cerr << "Invalid resize of vector with size " << size << " to size"
      << new_size << std::endl;
    return;
  }
  int * new_values = new int[new_size];
  std::memcpy(values, new_values, size);
  delete[] values;
  values = new_values;
}

/* Adds new value on end of actual vector and resizes it if needed */
void Vector::AddValue(int new_value) {
  values[size] = new_value;
  size++;
  if (size==max_size) {
    ExpandSize(2*max_size);
  }
}
