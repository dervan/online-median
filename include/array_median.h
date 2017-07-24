#ifndef ARRAY_MEDIAN_H
#define ARRAY_MEDIAN_H
#include "median_calculator.h"
#include "sorted_array.h"

class ArrayMedianCalculator : public MedianCalculator, public SortedArray {
  public:
    void AddValue(int value) {
      SortedArray::AddValue(value);
    }
    double GetMedian();
};
#endif
