#ifndef HEAP_H
#define HEAP_H

#include "vector.h"

template <typename Comparator>
class Heap: public Vector {
  protected:
    int Parent(int i) const;
    int Left(int i) const;
    int Right(int i) const;
    void FixUp(int i);
    void FixDown(int i);
    void Swap(int a, int b);
  public:
    /* Constructor and destructor tasks are done in Vector class */
    Heap() {};
    ~Heap() {};
    int GetTop() const {return values[0];};
    int GetSize() const {return size;};
    void AddValue(int value);
    int RemoveTop();
    bool Empty() const {return size==0;}
};

#endif
