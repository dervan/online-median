#ifndef HEAP_H
#define HEAP_H

template <typename Comparator>
class Heap{
  protected:
    int * values;
    int size;
    int max_size;
    int Parent(int i) const;
    int Left(int i) const;
    int Right(int i) const;
    void FixUp(int i);
    void FixDown(int i);
    void IncreaseSize(int new_size);
    void Swap(int a, int b);
  public:
    Heap();
    Heap(const Heap<Comparator> &base_heap);
    ~Heap();
    int GetTop() const {return values[0];};
    int GetSize() const {return size;};
    void AddValue(int value);
    int RemoveTop();
    bool Empty() const {return size==0;}
};

#endif
