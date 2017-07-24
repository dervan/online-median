#include "array_median_calculator.cpp"
#include <gtest/gtest.h>

class ArrayMedianCalculatorOrder: public ::testing::Test {
  protected:
    ArrayMedianCalculator test_array_calculator;
    ArrayMedianCalculatorOrder() {
      test_array_calculator.AddValue(2);
      test_array_calculator.AddValue(8);
      test_array_calculator.AddValue(4);
    }
};

TEST(ArrayMedianCalculatorBasics, ZeroSizeOnStart) {
  ArrayMedianCalculator test_array_calculator = ArrayMedianCalculator();
  ASSERT_EQ(0, test_array_calculator.GetSize());
}

TEST_F(ArrayMedianCalculatorOrder, SortedBase){
  int * values = test_array_calculator.GetValues();
  int desired_values[] = {2, 4, 8};
  int desired_size = 3;

  ASSERT_EQ(desired_size, test_array_calculator.GetSize());
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST(ArrayMedianCalculatorBasics, FirstElementAdded) {

  const int added_test_value = 4;
  ArrayMedianCalculator test_array_calculator = ArrayMedianCalculator();

  test_array_calculator.AddValue(added_test_value);

  int * values = test_array_calculator.GetValues();
  ASSERT_EQ(1, test_array_calculator.GetSize());
  ASSERT_EQ(added_test_value, values[0]);
}

TEST_F(ArrayMedianCalculatorOrder, InsertMiddle) {

  int desired_values[] = {2, 3, 4, 7, 8};
  int desired_size = 5;

  test_array_calculator.AddValue(3);
  test_array_calculator.AddValue(7);
  int * values = test_array_calculator.GetValues();

  ASSERT_EQ(desired_size, test_array_calculator.GetSize());
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST_F(ArrayMedianCalculatorOrder, InsertBigger) {

  test_array_calculator.AddValue(16);
  int * values = test_array_calculator.GetValues();
  int desired_values[] = {2, 4, 8, 16};
  int desired_size = 4;

  ASSERT_EQ(desired_size, test_array_calculator.GetSize());
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST_F(ArrayMedianCalculatorOrder, InsertSmaller) {

  test_array_calculator.AddValue(0);
  int * values = test_array_calculator.GetValues();
  int desired_values[] = {0, 2, 4, 8};
  int desired_size = 4;

  ASSERT_EQ(desired_size, test_array_calculator.GetSize());
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}


TEST(ArrayMedianCalculatorBasics, AverageOfElements) {
  ArrayMedianCalculator median_calculator;
  const int values[] = {1, 12, 14, 99, 14, 12, 0, 100};
  const int desired_median= 13;

  for (auto x : values) {
      median_calculator.AddValue(x);
  }
  ASSERT_EQ(desired_median, median_calculator.GetMedian());
}

TEST(ArrayMedianCalculatorBasics, AverageOfSameElements) {
  ArrayMedianCalculator median_calculator;
  const int values[] = {1, 2, 2, 2, 0, 10, 2, 11};
  const int desired_median = 2;

  for (auto x : values) {
    median_calculator.AddValue(x);
  }
  ASSERT_EQ(desired_median, median_calculator.GetMedian());
}



TEST(ArrayMedianCalculatorOverflows, NegativeIntegerOverflow) {
  ArrayMedianCalculator median_calculator;
  const int int_min = std::numeric_limits<int>::min();

  median_calculator.AddValue(int_min);
  median_calculator.AddValue(int_min+2);
  ASSERT_EQ(int_min+1, median_calculator.GetMedian());
}

TEST(ArrayMedianCalculatorOverflows, PositiveIntegerOverflow) {
  ArrayMedianCalculator median_calculator;
  const int int_max = std::numeric_limits<int>::max();

  median_calculator.AddValue(int_max);
  median_calculator.AddValue(int_max-2);
  ASSERT_EQ(int_max-1, median_calculator.GetMedian());
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

