#ifndef VECTOR_H
#define VECTOR_H

class Vector {
  protected:
    int* values;
    int max_size;
    int size;
    void ExpandSize(int new_size);
  public:
    Vector(int size=1024);
    Vector(const Vector &base_vector);
    ~Vector();
    int operator [](int i) const { return values[i]; }
    int & operator [](int i) { return values[i]; }
    void AddValue(int new_value);
    int GetSize() const { return size;}
};

#endif
