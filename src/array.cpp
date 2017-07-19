#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class SortedArray {
    int * values;
    int * tmp_buffer;
    int size;
    int max_size = 1024;

    public:
    SortedArray() {
        size = 0;
        values = new int[max_size];
        tmp_buffer = new int[max_size];
    }

    void increase_size(int new_size) {
        int * new_values = new int[new_size];
        std::memcpy(new_values, values, sizeof(int)*size);
        delete values;
        delete tmp_buffer;
        values = new_values;
        tmp_buffer = new int[new_size];
        cout << "Resizing to " << new_size << "\n";
        max_size = new_size;
    }

    int push(int value) {
        if (size==max_size) {
            increase_size(2*max_size);
        }
        int idx = lower_bound(value);
        shift_up(idx);
        values[idx] = value;
        print();
    }

    void shift_up(int idx) {
        int copy_length = size-idx;
        std::memcpy(tmp_buffer, &values[idx], sizeof(int)*copy_length);
        std::memcpy(&values[idx+1], tmp_buffer, sizeof(int)*copy_length);
        //for (int i = size; i > idx;  i--) { values[i] = values[i-1]; }
        size++;
    }

    int lower_bound(int value) {
        if (size == 0) {
            return 0;
        }
        int idx = 0;
        int left = 0;
        int right = size;
        while (right - left > 1) {
            idx = (left + right) / 2;
            if (values[idx] > value) {
                right = idx - 1;
            } else {
                left = idx + 1;
            }
        }
        cout << "Inserting: " << left << " " << idx << " "<< right << " "<< value << "\n";
        return left;
    }

    float median(void) {
        if (size % 2 == 0) {
            return ((long long int)values[(size/2)-1] + values[size/2])/2.0;
        } else {
            return values[size/2];
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int x;
    SortedArray arr;
    while (cin >> x) {
        arr.push(x);
    }
    cout << arr.median() << " ";
    cout << "\n";
    //cout << "\nTable:\n";
    //arr.print();
    return 0;
}
