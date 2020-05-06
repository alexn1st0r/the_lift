cmake_minimum_required (VERSION 2.8)
project (the_lift)

include_directories(../ ../vendor/googletest/googletest/include ../vendor/googletest/googlemock/include)
add_executable(the_lift_tests the_lift_tests.cpp ../lib/the_lift.cpp ../lib/floor.cpp)
target_link_libraries(the_lift_tests gmock gtest)
