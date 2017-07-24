#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

class SortedArray {
  protected:
    int * values;
    int * copy_buffer;
    int size;
    int max_size;
    int LowerBound(int value) const;
    void ShiftUp(int position);
    void IncreaseSize(int new_size);
  public:
    SortedArray();
    int * GetValues() const;
    int GetSize() const {return size;};
    void AddValue(int value);
};

#endif
