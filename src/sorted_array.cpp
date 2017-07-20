#include <iostream>
#include <cstring>
#include "sorted_array.h"

using std::cin;
using std::cout;
using std::endl;

void SortedArray::increase_size(int new_size) {
    int * new_values = new int[new_size];
    std::memcpy(new_values, values, sizeof(int)*size);
    delete values;
    delete copy_buffer;
    values = new_values;
    copy_buffer = new int[new_size];
    cout << "Resizing to " << new_size << "\n";
    max_size = new_size;
}

void SortedArray::shift_up(int idx) {
    int copy_length = size-idx;
    std::memcpy(copy_buffer, &values[idx], sizeof(int)*copy_length);
    std::memcpy(&values[idx+1], copy_buffer, sizeof(int)*copy_length);
    //for (int i = size; i > idx;  i--) { values[i] = values[i-1]; }
    size++;
}

int SortedArray::lower_bound(int value) {
    if (size == 0) {
        return 0;
    }

    int idx = 0;
    int left = 0; // first candidate for first bigger number
    int right = size; // last candidate ...
    /* During whole loop left is first number that possibly
     * may be bigger than value. On the other hand, right is
     * last possible value.
     * idx just helps to decrease search space */
    while (right - left > 0) {
        idx = (left + right) / 2;
        if (values[idx] < value) {
            left = idx + 1;//left is still smaller
        } else {
            right = idx; //right is still bigger
        }
    }
    //cout << "Inserting: " << left << " " << idx << " "<< right << " "<< value << "\n";
    return left;
}

SortedArray::SortedArray() {
    size = 0;
    max_size = 1024;
    values = new int[max_size];
    copy_buffer = new int[max_size];
}

SortedArray::~SortedArray() {
}

int SortedArray::push(int value) {
    if (size==max_size) {
        increase_size(2*max_size);
    }
    int idx = lower_bound(value);
    shift_up(idx);
    values[idx] = value;
}
float SortedArray::median(void) {
    if (size % 2 == 0) {
        return ((long long int)values[(size/2)-1] + values[size/2])/2.0;
    } else {
        return values[size/2];
    }
}

int * SortedArray::get_values() {
  int * return_values = new int[size];
  std::memcpy(return_values, values, sizeof(int)*size);
  return return_values;
}

int SortedArray::get_size() {
  return size;
}

void SortedArray::print() {
  for (int i = 0; i < size; i++) {
    cout << values[i] << " ";
  }
  cout << endl;
}
