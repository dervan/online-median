// tests.cpp
#include "sorted_array.cpp"
#include <gtest/gtest.h>
namespace {

class SortedArrayOrder: public ::testing::Test {
  protected:
    SortedArray array;
    SortedArrayOrder() {
      array.push(2);
      array.push(8);
      array.push(4);
    }
};

TEST_F(SortedArrayOrder, InsertMiddle) {

  array.push(3);
  array.push(7);

  int * values = array.get_values();
  int model_values[] = {2, 3, 4, 7, 8};
  int model_size = 5;
  
  for(int i=0; i<model_size; i++){
    ASSERT_EQ(model_values[i], values[i]);
  }
}

TEST_F(SortedArrayOrder, InsertBigger) {

  array.push(16);
  int * values = array.get_values();
  int model_values[] = {2, 4, 8, 16};
  int model_size = 4;
  
  for(int i=0; i<model_size; i++){
    ASSERT_EQ(model_values[i], values[i]);
  }
}


TEST_F(SortedArrayOrder, InsertSmaller) {

  array.push(0);
  int * values = array.get_values();
  int model_values[] = {0, 2, 4, 8};
  int model_size = 4;
  
  for(int i=0; i<model_size; i++){
    ASSERT_EQ(model_values[i], values[i]);
  }
}


TEST_F(SortedArrayOrder, SortedBase){
  int * values = array.get_values();
  int model_values[] = {2, 4, 8};
  int model_size = 3;
  
  for(int i=0; i<model_size; i++){
    ASSERT_EQ(model_values[i], values[i]);
  }
}

TEST(SortedArrayBasics, FirstElementAdded) {
  
  const int added_test_value = 4;
  SortedArray array = SortedArray();

  array.push(added_test_value);
  
  int * values = array.get_values();
  ASSERT_EQ(1, array.get_size());
  ASSERT_EQ(added_test_value, values[0]);
}
 
TEST(SortedArrayBasics, ZeroSizeOnStart) {
  SortedArray array = SortedArray();
  ASSERT_EQ(0, array.get_size());
}

} 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

