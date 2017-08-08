class Vector {
  protected:
    int* values;
    int max_size;
    int size;
    void ExpandSize(int new_size);
  public:
    Vector();
    Vector(int size);
    Vector(const Vector &base_vector);
    ~Vector();
    int operator [](int i) const {return values[i];}
    int & operator [](int i) {return values[i];}
    void AddValue(int new_value);
};
