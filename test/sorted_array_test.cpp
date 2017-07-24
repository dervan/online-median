// tests.cpp
#include "sorted_array.cpp"
#include <gtest/gtest.h>
namespace {

class SortedArrayOrder: public ::testing::Test {
  protected:
    SortedArray array;
    SortedArrayOrder() {
      array.AddValue(2);
      array.AddValue(8);
      array.AddValue(4);
    }
};

TEST_F(SortedArrayOrder, InsertMiddle) {

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

TEST_F(SortedArrayOrder, InsertBigger) {

  array.AddValue(16);
  int * values = array.GetValues();
  int desired_values[] = {2, 4, 8, 16};
  int desired_size = 4;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}


TEST_F(SortedArrayOrder, InsertSmaller) {

  array.AddValue(0);
  int * values = array.GetValues();
  int desired_values[] = {0, 2, 4, 8};
  int desired_size = 4;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}


TEST_F(SortedArrayOrder, SortedBase){
  int * values = array.GetValues();
  int desired_values[] = {2, 4, 8};
  int desired_size = 3;
  
  for(int i=0; i<desired_size; i++){
    ASSERT_EQ(desired_values[i], values[i]);
  }
}

TEST(SortedArrayBasics, FirstElementAdded) {
  
  const int added_test_value = 4;
  SortedArray array = SortedArray();

  array.AddValue(added_test_value);
  
  int * values = array.GetValues();
  ASSERT_EQ(1, array.GetSize());
  ASSERT_EQ(added_test_value, values[0]);
}
 
TEST(SortedArrayBasics, ZeroSizeOnStart) {
  SortedArray array = SortedArray();
  ASSERT_EQ(0, array.GetSize());
}

} 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

