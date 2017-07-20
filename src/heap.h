
template <typename Comparator>
class Heap{
  protected:
    int * values;
    int size;
    int max_size;
    int parent(int i);
    int left(int i);
    int right(int i);
    void fix_up(int i);
    void increase_size(int new_size);
    void swap(int a, int b);
  public:
    Heap();
    int get_top();
    int get_size();
    void push(int value);
    int pop();
};
