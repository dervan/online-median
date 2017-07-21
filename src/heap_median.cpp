#include "heap_median.h"

#include "heap_median.h"

HeapMedian::HeapMedian() {
}

bool HeapMedian::lowerIsBigger() {
    return upper_heap.get_size() < lower_heap.get_size();
}

bool HeapMedian::upperIsBigger() {
    return upper_heap.get_size() > lower_heap.get_size();
}

void HeapMedian::equalize() {
    if (upper_heap.get_size() > lower_heap.get_size()+1) {
       int shifted = upper_heap.pop();
       lower_heap.push(shifted);
    } else if (lower_heap.get_size() > upper_heap.get_size()+1) {
       int shifted = lower_heap.pop();
       upper_heap.push(shifted);
    }
}

void HeapMedian::push(int value) {
    if (upper_heap.empty() && lower_heap.empty()){
        upper_heap.push(value);
        return;
    }
    int median = getMedian();
    if (value>median) {
        upper_heap.push(value);
    } else {
        lower_heap.push(value);
    }
    equalize();
}

int HeapMedian::getMedian() {
    if (upperIsBigger()) {
        return upper_heap.get_top();
    }
    if (lowerIsBigger()) {
        return lower_heap.get_top();
    }
    std::cout << "Lo: " << lower_heap.get_size() << " $ " << lower_heap.get_top() << "\n";
    std::cout << "Up: " << upper_heap.get_size() << " $ " << upper_heap.get_top() << "\n";
    return (lower_heap.get_top() + upper_heap.get_top()) / 2;
}
