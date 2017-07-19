#include <iostream>
#include <vector>
#include <experimental/random>
#include <limits>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int count;
    int median;
    int spread;
    cin >> count >> median >> spread;
    std::vector<int> bottom_half((count-1)/2);
    std::vector<int> upper_half((count-1)/2);
    std::vector<int> values;
    values.reserve(count);

    int lower_median;
    int upper_median;
    if (count % 2) {
        lower_median = median;
        upper_median = median;
        values.push_back(median);
    } else {
        lower_median = median - spread;
        upper_median = median + spread;
        values.push_back(lower_median);
        values.push_back(upper_median);
    }
    std::generate(bottom_half.begin(), bottom_half.end(),
            [&lower_median]{return std::experimental::randint(std::numeric_limits<int>::min(), lower_median);});
    std::generate(upper_half.begin(), upper_half.end(),
            [&upper_median]{return std::experimental::randint(upper_median, std::numeric_limits<int>::max());});

    values.insert(values.end(), bottom_half.begin(), bottom_half.end());
    values.insert(values.end(), upper_half.begin(), upper_half.end());

    std::random_shuffle(values.begin(), values.end());
    for (auto i : values) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
