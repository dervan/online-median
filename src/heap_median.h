#ifndef HEAP_MEDIAN_H
#define HEAP_MEDIAN_H

#include "heap.h"
#include "iostream"

class HeapMedian {
  private:
    Heap<std::less<int>> upper_heap;
    Heap<std::greater<int>> lower_heap;
    bool lowerIsBigger();
    bool upperIsBigger();
    void equalize();
  public:
    HeapMedian();
    int getMedian();
    void push(int);
};

#endif
