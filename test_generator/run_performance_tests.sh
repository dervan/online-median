#!/bin/bash
TEST_FILES_DIR=./test_data
mkdir -p $TEST_FILES_DIR

#continous median tests
for size in 1000 10000; do
  echo "$size 42 656 0" | ./test_generator >$TEST_FILES_DIR/test$size 
  for flags in "-f" "-a" "-h"; do
    echo "==========================================================="
    echo "./median_calculator -e $flags with size $size"
    time ./median_calculator -e $flags <$TEST_FILES_DIR/test$size >$TEST_FILES_DIR/output.size$size.-e$flags
  done;
done;

#only median tests
for size in 1000 100000 1000000; do
  echo "$size 42 656 1" | ./test_generator >$TEST_FILES_DIR/test$size 
  for flags in "-f" "-a" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test$size >$TEST_FILES_DIR/output.size$size.$flags
  done;
done;

#big input tests
for size in 10000000 100000000; do
  echo "$size 42 656 1" | ./test_generator >$TEST_FILES_DIR/test$size 
  for flags in "-f" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test$size >$TEST_FILES_DIR/output.size$size.$flags
  done;
done;

#big input tests with multiple medians
for size in 10000000 100000000; do
  echo "$size 42 656 20" | ./test_generator >$TEST_FILES_DIR/test$size 
  for flags in "-f" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test$size >$TEST_FILES_DIR/output.size$size.$flags
  done;
done;

