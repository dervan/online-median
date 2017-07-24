#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int RandomInteger(int min, int max){
  int length = max-min;
  return std::rand()%length + min;
}

int main() {
  int count;
  int median;
  int spread;
  int requests_number;
  cin >> count >> median >> spread >> requests_number;
  std::vector<int> bottom_half((count-1)/2);
  std::vector<int> upper_half((count-1)/2);
  std::vector<int> values;
  values.reserve(count);

  /* Configure median value */
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

  /* Prepare random data */
  std::generate(bottom_half.begin(), bottom_half.end(),
      [&lower_median]{return RandomInteger(std::numeric_limits<int>::min(), lower_median);});
  std::generate(upper_half.begin(), upper_half.end(),
      [&upper_median]{return RandomInteger(upper_median, std::numeric_limits<int>::max());});

  values.insert(values.end(), bottom_half.begin(), bottom_half.end());
  values.insert(values.end(), upper_half.begin(), upper_half.end());
  std::random_shuffle(values.begin(), values.end());

  /* Generate median requests */
  std::vector<int> random_places(requests_number);
  if (requests_number > 0 ) {
    random_places[0] = count-1;
    std::generate(random_places.begin()+1, random_places.end(),
        [&count]{return RandomInteger(0, count-1);});
    std::sort(random_places.begin(), random_places.end());
  }

  /* Print generated data */
  std::vector<int>::iterator it = random_places.begin();
  for (int i=0; i<count; i++) {
    std::cout << values[i] << " ";
    if (it != random_places.end() && i >=(*it)) {
      std::cout << "m ";
      it++;
    }
  }
  std::cout << std::endl; 
  return 0;
}
