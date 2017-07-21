// tests.cpp
#include "heap.cpp"
#include <gtest/gtest.h>
namespace {

template <typename Comparator> 
class ExampleHeap {
  public:
  Heap<Comparator> heap;
  ExampleHeap(){
    heap.push(9);
    heap.push(-100);
    heap.push(42);
    heap.push(2);
    heap.push(33);
  }
  const int size = 5;
  const int sorted_values[5] = {-100, 2, 9, 33, 42};
};

TEST(HeapTestsBasics, ZeroSizeOnStart) {
  Heap<std::greater<int>> heap;
  ASSERT_EQ(0, heap.get_size());
}

TEST(HeapTestsBasics, InsertOne) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.push(42);

  ASSERT_EQ(1, heap.get_size());
  ASSERT_EQ(element, heap.get_top());
}

TEST(HeapTestsBasics, PopsOnlyElement) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.push(42);
  heap.pop();
  ASSERT_EQ(0, heap.get_size());
}

TEST(HeapTestsBasics, HoldDuplicates) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.push(42);
  heap.push(42);
  heap.pop();
  ASSERT_EQ(1, heap.get_size());
  ASSERT_EQ(42, heap.get_top());
}

TEST(HeapMaxTest, SelectMaxAfterBuilding) {
  ExampleHeap<std::greater<int>> example;

  ASSERT_EQ(example.size, example.heap.get_size());
  ASSERT_EQ(example.sorted_values[example.size-1], example.heap.get_top());
}

TEST(HeapMaxTest, SelectMaxDuringPopping) {
  ExampleHeap<std::greater<int>> example;
  
  ASSERT_EQ(example.size, example.heap.get_size());
  int i = 1;
  while(example.heap.get_size() > 0) {
      ASSERT_EQ(example.sorted_values[example.size-i], example.heap.get_top());
      i++;
      example.heap.pop();
  }
}


TEST(HeapMinTest, SelectMinAfterBuilding) {
  ExampleHeap<std::less<int>> example;

  ASSERT_EQ(example.size, example.heap.get_size());
  ASSERT_EQ(example.sorted_values[0], example.heap.get_top());
}

TEST(HeapMinTest, SelectMinDuringPopping) {
  ExampleHeap<std::less<int>> example;
  
  ASSERT_EQ(example.size, example.heap.get_size());
  int i = 0;
  while(example.heap.get_size() > 0) {
      ASSERT_EQ(example.sorted_values[i], example.heap.get_top());
      i++;
      example.heap.pop();
  }
}

} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

