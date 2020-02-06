cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp02)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


add_executable(aedaTP_2 main.cpp Tests/tests.cpp Tests/frota.cpp Tests/veiculo.cpp)

target_link_libraries(aedaTP_2 gtest gtest_main)
