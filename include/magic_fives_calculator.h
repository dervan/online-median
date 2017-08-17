#ifndef MAGIC_FIVES_CALCULATOR_H
#define MAGIC_FIVES_CALCULATOR_H

#include "median_calculator.h"
#include "vector.h"

class MagicFivesCalculator : public Vector, public MedianCalculator {
  private:
    int SimpleMedian(int * input_values, int count) const;
    int Select(int * const input_values, int count, int position) const;
    int * Partition(int * input_values, int size, int pivot, int * pivotPosition) const;
    int FindUpperMedian(int lower_median) const;
  public:
    /* Default constructor and destructor tasks are done in Vector class */
    MagicFivesCalculator() {};
    MagicFivesCalculator(const MagicFivesCalculator &base) : Vector(base) {};
    ~MagicFivesCalculator() {};
    void AddValue(int new_value) { Vector::AddValue(new_value); }
    double GetMedian();
};

#endif
