#include "heap_median_calculator.cpp"
#include <gtest/gtest.h>
#include <limits>

TEST(HeapMedianBasic, OneElement) {
  HeapMedianCalculator median_calculator;
  const int element = 42;

  median_calculator.AddValue(element);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(HeapMedianBasic, MultipleOccurences) {
  HeapMedianCalculator median_calculator;
  const int element1 = 42;
  const int element2 = 22;

  median_calculator.AddValue(element1);
  median_calculator.AddValue(element1);
  median_calculator.AddValue(element2);
  ASSERT_EQ(element1, median_calculator.GetMedian());
}

TEST(HeapMedianBasic, SimpleThreeElements) {
  HeapMedianCalculator median_calculator;
  const int element = 42;

  median_calculator.AddValue(element);
  median_calculator.AddValue(element + 1);
  median_calculator.AddValue(element - 1);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(HeapMedianBasic, AverageOfElements) {
  HeapMedianCalculator median_calculator;
  const int values[] = {1, 12, 14, 99, 14, 12, 0, 100};
  const int desired_median= 13;

  for (auto x : values) {
      median_calculator.AddValue(x);
  }
  ASSERT_EQ(desired_median, median_calculator.GetMedian());
}

TEST(HeapMedianOverflows, NegativeIntegerOverflow) {
  HeapMedianCalculator median_calculator;
  const int int_min = std::numeric_limits<int>::min();

  median_calculator.AddValue(int_min);
  median_calculator.AddValue(int_min+2);
  ASSERT_EQ(int_min+1, median_calculator.GetMedian());
}

TEST(HeapMedianOverflows, PositiveIntegerOverflow) {
  HeapMedianCalculator median_calculator;
  const int int_max = std::numeric_limits<int>::max();

  median_calculator.AddValue(int_max);
  median_calculator.AddValue(int_max-2);
  ASSERT_EQ(int_max-1, median_calculator.GetMedian());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

