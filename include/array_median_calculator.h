#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H
#include "median_calculator.h"

class ArrayMedianCalculator : public MedianCalculator {
  protected:
    int * values;
    int * copy_buffer;
    int size;
    int max_size;
    int LowerBound(int value) const;
    void ShiftUp(int position);
    void IncreaseSize(int new_size);
  public:
    ArrayMedianCalculator();
    int * GetValues() const;
    int GetSize() const {return size;};
    void AddValue(int value);
    double GetMedian();
};

#endif
