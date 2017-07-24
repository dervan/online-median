// tests.cpp
#include "heap.cpp"
#include <gtest/gtest.h>
namespace {

template <typename Comparator> 
class ExampleHeap {
  public:
  Heap<Comparator> heap;
  ExampleHeap(){
    heap.AddValue(9);
    heap.AddValue(-100);
    heap.AddValue(42);
    heap.AddValue(2);
    heap.AddValue(33);
  }
  const int size = 5;
  const int sorted_values[5] = {-100, 2, 9, 33, 42};
};

TEST(HeapTestsBasics, ZeroSizeOnStart) {
  Heap<std::greater<int>> heap;
  ASSERT_EQ(0, heap.GetSize());
}

TEST(HeapTestsBasics, InsertOne) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.AddValue(42);

  ASSERT_EQ(1, heap.GetSize());
  ASSERT_EQ(element, heap.GetTop());
}

TEST(HeapTestsBasics, PopsOnlyElement) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.AddValue(42);
  heap.RemoveTop();
  ASSERT_EQ(0, heap.GetSize());
}

TEST(HeapTestsBasics, HoldDuplicates) {
  Heap<std::greater<int>> heap;
  const int element = 42;
  heap.AddValue(42);
  heap.AddValue(42);
  heap.RemoveTop();
  ASSERT_EQ(1, heap.GetSize());
  ASSERT_EQ(42, heap.GetTop());
}

TEST(HeapMaxTest, SelectMaxAfterBuilding) {
  ExampleHeap<std::greater<int>> example;

  ASSERT_EQ(example.size, example.heap.GetSize());
  ASSERT_EQ(example.sorted_values[example.size-1], example.heap.GetTop());
}

TEST(HeapMaxTest, SelectMaxDuringPopping) {
  ExampleHeap<std::greater<int>> example;
  
  ASSERT_EQ(example.size, example.heap.GetSize());
  int i = 1;
  while(example.heap.GetSize() > 0) {
      ASSERT_EQ(example.sorted_values[example.size-i], example.heap.GetTop());
      i++;
      example.heap.RemoveTop();
  }
}


TEST(HeapMinTest, SelectMinAfterBuilding) {
  ExampleHeap<std::less<int>> example;

  ASSERT_EQ(example.size, example.heap.GetSize());
  ASSERT_EQ(example.sorted_values[0], example.heap.GetTop());
}

TEST(HeapMinTest, SelectMinDuringPopping) {
  ExampleHeap<std::less<int>> example;
  
  ASSERT_EQ(example.size, example.heap.GetSize());
  int i = 0;
  while(example.heap.GetSize() > 0) {
      ASSERT_EQ(example.sorted_values[i], example.heap.GetTop());
      i++;
      example.heap.RemoveTop();
  }
}

} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

