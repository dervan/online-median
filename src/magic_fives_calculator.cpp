#include "magic_fives_calculator.h"

#include <cstring>
#include <iostream>
#include <limits>

/* Does the partition of given array based on pivot values. Returns 
 * array of values where values [0..pivotPosition-1] are smaller than pivot
 * and [pivotPosition..size-1] are bigger or equal (pivot values are always
 * on beginning of second part of array ) 
 * This function returns allocated array, you have to remember to free it later */
int * MagicFivesCalculator::Partition(int * input_values, int size, int pivot, int * pivotPosition) const {
  int * parted = new int[size];
  int left = 0;
  int right = size-1;
  int equal_count = 0;

  for(int i = 0; i < size; i++){
    if (input_values[i] > pivot) {
      parted[right] = input_values[i];
      right--;
    } else if (input_values[i] < pivot) { 
      parted[left] = input_values[i];
      left++;
    } else {
      equal_count++;
    }
  }

  for(int i = 0; i < equal_count; i++){
    parted[left+i] = pivot;
  }

  *pivotPosition = left;
  return parted;
}

/* Calculates median of short array via ordinary insert sort */
int MagicFivesCalculator::SimpleMedian(int * input_values, int count) const {
  for(int i = 1; i<count; i++){
    int j = i;
    while (j>0 && input_values[j-1]>input_values[j]) {
      int tmp = input_values[j];
      input_values[j] = input_values[j-1];
      input_values[j-1] = tmp;
      j--;
    }
  }
  return input_values[(count-1)/2];
}

/* This is essence of MagicFives algorithm. It selects position-th biggest value
 * from input_values array. It runs in pesimistic linear time. */
int MagicFivesCalculator::Select(int * const input_values,
                                 int count, int position) const {

  /* Firstly divide array into constant size buckets */
  int groups = count/5;
  if ((count%5)!=0) {
    groups++;
  }
  int * medians = new int[groups];
  int i = 0;

  /* From every group select median via insertion sort */
  while (i<count/5) {
    medians[i] = SimpleMedian(&input_values[5*i], 5);
    i++;
  }
  if (count % 5) {
    medians[i] = SimpleMedian(&input_values[5*(count/5)], count%5);
  }
  /* And if it's very small chunk of array return directly answer */
  if (count <= 5 ) {
    delete[] medians;
    return input_values[position];
  }

  /* Select median of medians as pivot and do the partition */
  int pivot = Select(medians, groups, (groups-1)/2);
  int pivotPosition;
  int * parted = Partition(input_values, count, pivot, &pivotPosition);
  int selected_value;

  /* And do the recursive call */
  if (position == pivotPosition) {
    selected_value = pivot;
  } else {
    if (pivotPosition > position) {
      selected_value = Select(parted, pivotPosition, position);
    } else {
      selected_value = Select(&parted[pivotPosition+1], count-pivotPosition-1, position-pivotPosition-1);
    }
  }
  delete[] parted;
  delete[] medians;
  return selected_value;
}

/* Select algorithm finds lower median. If array have even length
 * we have to find also upper median - next bigger value or same
 * value - depends on positions of lower_median occurences */
int MagicFivesCalculator::FindUpperMedian(int lower_median) const {
  int upper_median_guess = std::numeric_limits<int>::max();
  int smaller_or_equal = 0;
  for (int i = 0; i < size; i++) {
    if (values[i]<=lower_median) {
      smaller_or_equal++;
    } else if (upper_median_guess > values[i]) {
      upper_median_guess = values[i];
    }
  }
  if (smaller_or_equal > ((size-1)/2 + 1)) {
    return lower_median;
  } else {
    return upper_median_guess;
  }
}

/* It just simply selects median with Select algorithm */
double MagicFivesCalculator::GetMedian() {
  int lower_median = Select(values, size, (size-1)/2);
  if (!(size % 2)) {
    int upper_median = FindUpperMedian(lower_median);
    return ((long long int)lower_median + upper_median)/2.0;
  } else {
    return lower_median;
  }
}
