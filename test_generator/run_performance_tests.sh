#!/bin/bash
TEST_FILES_DIR=./test_data
mkdir -p $TEST_FILES_DIR

echo "Continous median tests: (1k, 10k)"
for size in 1000 10000 100000; do
  echo "$size 42 656 0" | ./test_generator >$TEST_FILES_DIR/test_a_$size 
  for flags in "-f" "-a" "-h"; do
    echo "==========================================================="
    echo "./median_calculator -e $flags with size $size"
    time ./median_calculator -e $flags <$TEST_FILES_DIR/test_a_$size >$TEST_FILES_DIR/output_a_size$size.-e$flags
  done;
done;

echo "###########################################################"
echo "Single median tests: (1k, 100k, 1M) "
for size in 1000 100000 1000000; do
  echo "$size 42 656 1" | ./test_generator >$TEST_FILES_DIR/test_b_$size 
  for flags in "-f" "-a" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test_b_$size >$TEST_FILES_DIR/output_b_size$size.$flags
  done;
done;

echo "###########################################################"
echo "Multpile (42) medians, big input: (1M, 10M, 100M)"
for size in 1000000 10000000 100000000; do
  echo "$size 42 656 42" | ./test_generator >$TEST_FILES_DIR/test_c_$size 
  for flags in "-f" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test_c_$size >$TEST_FILES_DIR/output_c_size$size.$flags
  done;
done;

echo "###########################################################"
echo "Single median, big input: (10M, 100M, 1000M)"
for size in 10000000 100000000 1000000000; do
  echo "$size 42 656 1" | ./test_generator >$TEST_FILES_DIR/test_d_$size 
  for flags in "-f" "-h"; do
    echo "==========================================================="
    echo "./median_calculator $flags with size $size"
    time ./median_calculator $flags <$TEST_FILES_DIR/test_d_$size >$TEST_FILES_DIR/output_d_size$size.$flags
  done;
done;


