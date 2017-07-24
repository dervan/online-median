// tests.cpp
#include "heap_median.cpp"
#include <gtest/gtest.h>
namespace {

TEST(HeapMedianBasic, SimpleThreeElements) {
  HeapMedianCalculator median_calculator;
  const int element = 42 ;

  median_calculator.AddValue(element);
  median_calculator.AddValue(10);
  median_calculator.AddValue(60);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(HeapMedianBasic, OneElement) {
  HeapMedianCalculator median_calculator;
  const int element = 42;

  median_calculator.AddValue(element);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(HeapMedianBasic, AverageOfElements) {
  HeapMedianCalculator median_calculator;
  const int elements[] = {1, 12, 14, 99, 14, 12, 0 , 100};
  for(auto x : elements) {
      median_calculator.AddValue(x);
  }
  ASSERT_EQ(13, median_calculator.GetMedian());
}
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

