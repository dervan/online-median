#include "magic_fives_calculator.cpp"
#include <gtest/gtest.h>

TEST(MagicFivesBasic, OneElement) {
  MagicFivesCalculator median_calculator;
  const int element = 42;

  median_calculator.AddValue(element);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(MagicFivesBasic, HandlesMultipleOccurences) {
  MagicFivesCalculator median_calculator;
  const int element1 = 42;
  const int element2 = 22;

  median_calculator.AddValue(element1);
  median_calculator.AddValue(element1);
  median_calculator.AddValue(element2);
  ASSERT_EQ(element1, median_calculator.GetMedian());
}

TEST(MagicFivesBasic, SimpleThreeElements) {
  MagicFivesCalculator median_calculator;
  const int element = 42;

  median_calculator.AddValue(element);
  median_calculator.AddValue(element + 1);
  median_calculator.AddValue(element - 1);
  ASSERT_EQ(element, median_calculator.GetMedian());
}

TEST(MagicFivesBasic, AverageOfElements) {
  MagicFivesCalculator median_calculator;
  const int values[] = {1, 12, 14, 99, 14, 12, 0, 100};
  const int desired_median = 13;

  for (auto x : values) {
    median_calculator.AddValue(x);
  }
  ASSERT_EQ(desired_median, median_calculator.GetMedian());
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

