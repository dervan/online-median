#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char * argv[]) {
  std::vector<int> values;

  int new_number;
  /* Try to load an integer */
  cin >> new_number;
  while (!cin.eof()) {
    if (cin.fail()) {
      /* It's not an integer. Maybe it's median request? */
      char input_letter;
      cin.clear();
      cin >> input_letter;
      if (input_letter == 'm') {
        int size = values.size();
        std::nth_element(values.begin(), values.begin()+(size-1)/2, values.end());
        float median;
        if (size % 2){
          median = values[(size-1)/2];
        } else {
          std::nth_element(values.begin(), values.begin()+(size-1)/2+1, values.end());
          median = ((long long int)values[(size-1)/2] + values[(size-1)/2 + 1])/2.0;
        }
        cout << median << " ";
      } else {
        /* Input is incorrect, return error */
        std::cerr << "Incorrect input: " << input_letter << " ";
        std::cerr << "Expected number or letter 'm'" << endl;
        return 1;
      }
    } else {
      values.push_back(new_number);
    }
    cin >> new_number;
  }
  cout << endl;
  return 0;
}
