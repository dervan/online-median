
class SortedArray {
  protected:
    int * values;
    int * copy_buffer;
    int size;
    int max_size;
    int lower_bound(int value);
    void shift_up(int idx);
    void increase_size(int new_size);
  public:
    SortedArray();
    ~SortedArray();
    int * get_values();
    int get_size();
    int push(int value);
    float median();
    void print();
};
