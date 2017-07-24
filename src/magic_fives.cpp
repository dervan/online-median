#include "magic_fives.h"
#include "iostream"
#include "limits"

MagicFivesCalculator::MagicFivesCalculator(){
  size = 0;
  max_size = 1024;
  values = new int[max_size];
}

void MagicFivesCalculator::IncreaseSize(int new_size) {
  int * new_values = new int[new_size];
  std::memcpy(new_values, values, sizeof(int)*size);
  delete values;
  values = new_values;
  max_size = new_size;
}

int * MagicFivesCalculator::Partition(int * input_values, int size, int pivot, int * pivotPosition){
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
  if(left > right) {
    
    std::cout << "ALERT: piv " << pivot << "L " << left << "R " << right << "eq "<< equal_count << "s " << size << std::endl;
  for(int i = 0; i<size; i++){ std::cout << input_values[i] << " "; } std::cout << std::endl;
  for(int i = 0; i<size; i++){ std::cout << parted[i] << " "; } std::cout << std::endl;
  }
  *pivotPosition = left;
  
  return parted;
}

int MagicFivesCalculator::SimpleMedian(int * input_values, int count) {
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

int MagicFivesCalculator::Select(int * const input_values, int count, int position){
  int groups = count/5;
  if ((count%5)!=0) {
    groups++;
  }
  int * medians = new int[groups];
  int i = 0;
  while (i<count/5) {
    medians[i] = SimpleMedian(&input_values[5*i], 5);
    i++;
  }
  if (count % 5) {
    medians[i] = SimpleMedian(&input_values[5*(count/5)], count%5);
  }
  if (count <= 5 ) {
    delete[] medians;
    return input_values[position];
  }
  int pivot = Select(medians, groups, (groups-1)/2);
  int pivotPosition;
  int * parted = Partition(input_values, count, pivot, &pivotPosition);
  int selected_value;
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

void MagicFivesCalculator::AddValue(int new_value) {
  if (size==max_size) {
    IncreaseSize(2*max_size);
  }
  values[size] = new_value;
  size++;
}

int MagicFivesCalculator::FindUpperMedian(int lower_median) {
  int upper_median_guess = std::numeric_limits<int>::max();
  for (int i = 0; i < size; i++) {
    if (values[i]>lower_median && upper_median_guess > values[i]) {
      upper_median_guess = values[i];
    }
  }
  return upper_median_guess;
}

double MagicFivesCalculator::GetMedian(){
  int lower_median = Select(values, size, (size-1)/2);
  if (!(size % 2)) {
    int upper_median = FindUpperMedian(lower_median);
    return ((long long int)lower_median + upper_median)/2.0;
  } else {
    return lower_median;
  }
}
