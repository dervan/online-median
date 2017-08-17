#include "heap_median_calculator.h"

#include <iostream>

HeapMedianCalculator::HeapMedianCalculator(const HeapMedianCalculator &base) {
  upper_heap = Heap<std::less<int> >(base.upper_heap);
  lower_heap = Heap<std::greater<int> >(base.lower_heap);
}

bool HeapMedianCalculator::LowerIsBigger() const {
  return upper_heap.GetSize() < lower_heap.GetSize();
}

bool HeapMedianCalculator::UpperIsBigger() const {
  return upper_heap.GetSize() > lower_heap.GetSize();
}

/* In HeapMedianCalculator both heaps can different in size at most
 * by one. Because of that after every addition we need to equalize 
 * them. */
void HeapMedianCalculator::Equalize() {
  if (upper_heap.GetSize() > lower_heap.GetSize()+1) {
    int carried = upper_heap.RemoveTop();
    lower_heap.AddValue(carried);
  } else if (lower_heap.GetSize() > upper_heap.GetSize()+1) {
    int carried = lower_heap.RemoveTop();
    upper_heap.AddValue(carried);
  }
}

/* Add new value to proper heap - with bigger or smaller values.
 * Because potentially balance is broken, restore it with Equalize() call */
void HeapMedianCalculator::AddValue(int value) {
  if (upper_heap.Empty() && lower_heap.Empty()){
    upper_heap.AddValue(value);
    return;
  }
  int median = GetMedian();
  if (value>median) {
    upper_heap.AddValue(value);
  } else {
    lower_heap.AddValue(value);
  }
  Equalize();
}

/* Returns median in constant time. Thanks to equal heaps we always know
 * a median of our values */
double HeapMedianCalculator::GetMedian() {
  if (UpperIsBigger()) {
    return upper_heap.GetTop();
  }
  if (LowerIsBigger()) {
    return lower_heap.GetTop();
  }
  return ((long long int)lower_heap.GetTop() + upper_heap.GetTop()) / 2.0;
}
