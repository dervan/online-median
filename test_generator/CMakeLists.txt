add_executable(test_generator generator.cpp)
add_executable(test_verifier verifier.cpp)
configure_file(run_performance_tests.sh ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/run_performance_tests.sh COPYONLY)

