#include <iostream>
#include <string>
#include "median_calculator.h"
#include "array_median_calculator.h"
#include "heap_median_calculator.h"
#include "magic_fives_calculator.h"

using std::cin;
using std::cout;
using std::endl;

/* This function checks if string option appears somewhere in argv */
bool OptionSelected(const std::string& option, int argc, char * argv[]) {
  for(int i=1; i<argc; i++) {
    if (option.compare(argv[i]) == 0) {
      return true;
    }
  }
  return false;
}

int main(int argc, char * argv[]) {

  /* Configure options of program */
  MedianCalculator* median_calculator;
  bool print_on_every_number = OptionSelected("-e", argc, argv);
  if (OptionSelected("-a", argc, argv)) {
    median_calculator = new ArrayMedianCalculator();
  } else if (OptionSelected("-f", argc, argv)) {
    median_calculator = new MagicFivesCalculator();
  } else {
    median_calculator = new HeapMedianCalculator();
  }

  /* Configure cout to get pretty output */
  cout.precision(20);
  cout << std::noshowpoint;

  /* Start with loading first integer */
  int new_number;
  cin >> new_number;
  if (print_on_every_number) {
    /* Ends if reaches end of file or illegal input appears */
    while (cin.good()) {
      median_calculator->AddValue(new_number);
      cout << median_calculator->GetMedian() << " ";
      cin >> new_number;
    }
  } else {
    /* Ends just when end of file is reached */
    while (!cin.eof()) {
      if (cin.fail()) {
        /* It's not an integer. Maybe it's median request? */
        char input_letter;
        cin.clear();
        cin >> input_letter;
        if (input_letter == 'm') {
          cout << median_calculator->GetMedian() << " ";
        } else {
          /* Input is incorrect, return error */
          std::cerr << "Incorrect input: " << input_letter << " ";
          std::cerr << "Expected number or letter 'm'" << endl;
          return 1;
        }
      } else {
        median_calculator->AddValue(new_number);
      }
      cin >> new_number;
    }
  }
  cout << endl;
  return 0;
}
