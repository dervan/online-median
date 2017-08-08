#include "array_median_calculator.h"

#include <cstring>
#include <iostream>

ArrayMedianCalculator::ArrayMedianCalculator() {
}

ArrayMedianCalculator::~ArrayMedianCalculator() {
}

/* Moves all values on range [postion..size-1] to next place in array.
 * It increases size of array by one - so array cannot be full when this
 * function is called. But that check is done in AddValue function. */
void ArrayMedianCalculator::ShiftUp(int position) {
  int copy_length = size-position;
  std::memmove(&values[position+1], &values[position], sizeof(int)*copy_length);
  size++;
}

/* Finds the first value that is bigger than given as argument.
 * It uses binsearch (ShiftUp is linear anyway, but it's always some speedup) */
int ArrayMedianCalculator::LowerBound(int value) const {
  if (size == 0) {
    return 0;
  }
  int middle = 0;
  int left = 0; /* first candidate for first bigger number */
  int right = size; /* last candidate (if all are smaller) */
  /* During whole loop left is first number that possibly
   * may be bigger than value. On the other hand, right is
   * last possible value.
   * middle just helps to decrease search space */
  while (right - left > 0) {
    middle = (left + right) / 2;
    if (values[middle] < value) {
      left = middle + 1; /* left is still smaller */
    } else {
      right = middle; /* right is still bigger */
    }
  }
  return left;
}

/* Adds value to sorted array. Also increases size of values array if needed */
void ArrayMedianCalculator::AddValue(int value) {
  if (size==max_size) {
    ExpandSize(2*max_size);
  }
  int proper_position = LowerBound(value);
  ShiftUp(proper_position);
  values[proper_position] = value;
}

/* Returns copy of array with all values */
int * ArrayMedianCalculator::GetValues() const {
  int * return_values = new int[size];
  std::memcpy(return_values, values, sizeof(int)*size);
  return return_values;
}

/* Returns correct, mathematical median of array. It have to be
 * double because average of two integers may have fraction part. */
double ArrayMedianCalculator::GetMedian(void) {
  if (size % 2 == 0) {
    /* Cast to double to prevent integer overflow */
    return ((double)values[(size/2)-1] + (double)values[size/2])/2.0;
  } else {
    return values[size/2];
  }
}

