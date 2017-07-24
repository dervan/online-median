add_executable(test_generator generator.cpp)
add_executable(test_verifier verifier.cpp)
configure_file(run_performance_tests.sh run_performance_tests.sh COPYONLY)

