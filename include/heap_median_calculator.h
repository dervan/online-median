#ifndef HEAP_MEDIAN_CALCULATOR_H
#define HEAP_MEDIAN_CALCULATOR_H

#include "median_calculator.h"
#include "heap.h"
#include "functional"

class HeapMedianCalculator : public MedianCalculator {
  private:
    Heap<std::less<int> > upper_heap;
    Heap<std::greater<int> > lower_heap;
    bool LowerIsBigger() const;
    bool UpperIsBigger() const;
    void Equalize();
  public:
    double GetMedian();
    void AddValue(int);
};

#endif
