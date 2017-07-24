#ifndef MEDIAN_CALCULATOR_H
#define MEDIAN_CALCULATOR_H
class MedianCalculator {
  public:
    virtual float GetMedian() = 0;
    virtual void AddValue(int value) = 0;
};
#endif
