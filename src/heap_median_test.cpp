// tests.cpp
#include "heap.cpp"
#include "heap_median.cpp"
#include <gtest/gtest.h>
namespace {

TEST(HeapMedianBasic, SimpleThreeElements) {
  HeapMedian median_calculator;
  const int element = 42 ;

  median_calculator.push(element);
  median_calculator.push(10);
  median_calculator.push(60);
  ASSERT_EQ(element, median_calculator.getMedian());
}

TEST(HeapMedianBasic, OneElement) {
  HeapMedian median_calculator;
  const int element = 42;

  median_calculator.push(element);
  ASSERT_EQ(element, median_calculator.getMedian());
}

TEST(HeapMedianBasic, AverageOfElements) {
  HeapMedian median_calculator;
  const int elements[] = {1, 12, 14, 99, 14, 12, 0 , 100};
  for(auto x : elements) {
      median_calculator.push(x);
  }
  ASSERT_EQ(13, median_calculator.getMedian());
}
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

