cmake_minimum_required(VERSION 3.8)
project(mesosphere_coding_challenge)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES main.cpp include/node.hpp src/node.cpp src/job.cpp include/job.hpp src/scheduler.cpp include/scheduler.hpp)
add_executable(mesosphere_coding_challenge ${SOURCE_FILES})