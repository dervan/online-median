#include <iostream>
#include "heap_median.h"

bool HeapMedianCalculator::LowerIsBigger() const {
    return upper_heap.GetSize() < lower_heap.GetSize();
}

bool HeapMedianCalculator::UpperIsBigger() const {
    return upper_heap.GetSize() > lower_heap.GetSize();
}

void HeapMedianCalculator::Equalize() {
    if (upper_heap.GetSize() > lower_heap.GetSize()+1) {
       int shifted = upper_heap.RemoveTop();
       lower_heap.AddValue(shifted);
    } else if (lower_heap.GetSize() > upper_heap.GetSize()+1) {
       int shifted = lower_heap.RemoveTop();
       upper_heap.AddValue(shifted);
    }
}

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

float HeapMedianCalculator::GetMedian() {
    if (UpperIsBigger()) {
        return upper_heap.GetTop();
    }
    if (LowerIsBigger()) {
        return lower_heap.GetTop();
    }
    return ((long long int)lower_heap.GetTop() + upper_heap.GetTop()) / 2.0;
}
