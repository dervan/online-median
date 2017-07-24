// tests.cpp
#include "array_median_calculator.cpp"
#include <gtest/gtest.h>
namespace {

class ArrayMedianCalculatorOrder: public ::testing::Test {
  protected:
    ArrayMedianCalculator array;
    ArrayMedianCalculatorOrder() {
      array.AddValue(2);
      array.AddValue(8);
      array.AddValue(4);
    }
};

TEST_F(ArrayMedianCalculatorOrder, InsertMiddle) {

  int desired_values[] = {2, 3, 4, 7, 8};
  int desired_size = 5;
  
  array.AddValue(3);
  array.AddValue(7);
  int * values = array.GetValues();

  ASSERT_EQ(desired_size, array.GetSize());

  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST_F(ArrayMedianCalculatorOrder, InsertBigger) {

  array.AddValue(16);
  int * values = array.GetValues();
  int desired_values[] = {2, 4, 8, 16};
  int desired_size = 4;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}


TEST_F(ArrayMedianCalculatorOrder, InsertSmaller) {

  array.AddValue(0);
  int * values = array.GetValues();
  int desired_values[] = {0, 2, 4, 8};
  int desired_size = 4;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}


TEST_F(ArrayMedianCalculatorOrder, SortedBase){
  int * values = array.GetValues();
  int desired_values[] = {2, 4, 8};
  int desired_size = 3;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST(ArrayMedianCalculatorBasics, FirstElementAdded) {
  
  const int added_test_value = 4;
  ArrayMedianCalculator array = ArrayMedianCalculator();

  array.AddValue(added_test_value);
  
  int * values = array.GetValues();
  ASSERT_EQ(1, array.GetSize());
  ASSERT_EQ(added_test_value, values[0]);
}
 
TEST(ArrayMedianCalculatorBasics, ZeroSizeOnStart) {
  ArrayMedianCalculator array = ArrayMedianCalculator();
  ASSERT_EQ(0, array.GetSize());
}

} 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

