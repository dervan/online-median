#ifndef ARRAY_MEDIAN_CALCULATOR_H 
#define ARRAY_MEDIAN_CALCULATOR_H

#include "median_calculator.h"
#include "vector.h"

class ArrayMedianCalculator : public MedianCalculator, public Vector {
  protected:
    int LowerBound(int value) const;
    void ShiftUp(int position);
  public:
    /* Default constructor and destructor tasks are done in Vector class */
    ArrayMedianCalculator() {};
    ArrayMedianCalculator(const ArrayMedianCalculator &base) : Vector(base) {};
    ~ArrayMedianCalculator() {};
    int * GetValues() const;
    void AddValue(int value);
    double GetMedian();
};

#endif
