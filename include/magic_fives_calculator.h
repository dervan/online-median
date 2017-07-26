#ifndef MAGIC_FIVES_CALCULATOR_H
#define MAGIC_FIVES_CALCULATOR_H
#include "median_calculator.h"

class MagicFivesCalculator : public MedianCalculator {
  private:
    int max_size;
    int size;
    int * values;
    int SimpleMedian(int * input_values, int count);
    int Select(int * const input_values, int count, int position);
    int * Partition(int * input_values, int size, int pivot, int * pivotPosition);
    int FindUpperMedian(int lower_median);
    void IncreaseSize(int new_size);
  public:
    MagicFivesCalculator();
    ~MagicFivesCalculator();
    void AddValue(int value);
    double GetMedian();
};

#endif
