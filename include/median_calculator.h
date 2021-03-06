#ifndef MEDIAN_CALCULATOR_H
#define MEDIAN_CALCULATOR_H

class MedianCalculator {
  public:
    virtual double GetMedian() = 0;
    virtual void AddValue(int value) = 0;
    virtual ~MedianCalculator(){};
};

#endif
