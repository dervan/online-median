project(median_calculator_tests)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
include_directories("../include")
include_directories("../src")

add_custom_target(check COMMAND GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} --verbose)

add_executable(array_median_calculator_test array_median_calculator_test.cpp ../src/vector.cpp)
target_link_libraries(array_median_calculator_test gtest_main)
add_test(NAME SortedArrayTests COMMAND array_median_calculator_test)

add_executable(heap_median_calculator_test heap_median_calculator_test.cpp ../src/heap.cpp ../src/vector.cpp)
target_link_libraries(heap_median_calculator_test gtest_main)
add_test(NAME HeapMedianTests COMMAND heap_median_calculator_test)

add_executable(heap_test heap_test.cpp ../src/vector.cpp)
target_link_libraries(heap_test gtest_main)
add_test(NAME HeapTests COMMAND heap_test)

add_executable(magic_fives_calculator_test magic_fives_calculator_test.cpp ../src/vector.cpp)
target_link_libraries(magic_fives_calculator_test gtest_main)
add_test(NAME MagicFivesTests COMMAND magic_fives_calculator_test)

