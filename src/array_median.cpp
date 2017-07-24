#include "array_median.h"

float ArrayMedianCalculator::GetMedian(void) {
  if (size % 2 == 0) {
    return ((long long int)values[(size/2)-1] + values[size/2])/2.0;
  } else {
    return values[size/2];
  }
}


