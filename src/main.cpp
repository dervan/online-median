#include <iostream>
#include "heap_median.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;
    HeapMedian hm;
    
    while (cin >> x) {
        hm.push(x);
    }
    cout << hm.getMedian() << " ";
    cout << "\n";
    //cout << "\nTable:\n";
    //arr.print();
    return 0;
}
