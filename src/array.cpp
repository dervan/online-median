#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int x;

class SortedArray
{
    int * values;
    int size;
    public:
    SortedArray()
    {
        size = 0;
        values = new int[100];
    }

    int push(int value)
    {
        int idx = lower_bound(value);
        shift_up(idx);
        values[idx] = value;
    }

    void shift_up(int idx)
    {
        for(int i = size; i > idx;  i--)
        {
            values[i] = values[i-1];
        }
        size++;
    }

    int lower_bound(int value)
    {
        if(size == 0)
        {
            return 0;
        }
        int i = size-1;
        while(values[i] > value && i > 0)
        {
            i--;
        }
        return i+1;
    }

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    SortedArray arr;
    while(cin >> x){
        arr.push(x);
    }

    arr.print();

}
