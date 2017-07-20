#include <iostream>
#include "sorted_array.h"

using std::cin;
using std::cout;
using std::endl;

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
