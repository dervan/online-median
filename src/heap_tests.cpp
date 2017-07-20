// tests.cpp
#include "heap.cpp"
#include <gtest/gtest.h>
namespace {

TEST(HeapTestsBasics, ZeroSizeOnStart) {
  Heap<std::greater<int>> heap;
  ASSERT_EQ(0, heap.get_size());
}

TEST(HeapTestsBasics, InsertOne) {
  const int element = 42;
  Heap<std::greater<int>> heap;
  heap.push(element);
  
  ASSERT_EQ(1, heap.get_size());
  ASSERT_EQ(element, heap.get_top());
}

TEST(HeapMaxTest, InsertFour) {
  const int elements[] = { 9, -100, 42, 2};
  const int elements_count = 4;
  Heap<std::greater<int>> heap;
  for(auto element : elements){
    heap.push(element);
  }
  
  ASSERT_EQ(elements_count, heap.get_size());
  ASSERT_EQ(42, heap.get_top());
}


TEST(HeapMinTest, InsertFour) {
  const int elements[] = {10, 9, -100, 42 };
  const int elements_count = 4;
  Heap<std::less<int>> heap;
  for(auto element : elements){
    heap.push(element);
  }
  
  ASSERT_EQ(elements_count, heap.get_size());
  ASSERT_EQ(-100, heap.get_top());
}




} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

