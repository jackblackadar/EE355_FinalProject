cmake_minimum_required(VERSION 3.15)
project("EE355 Final Project")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tests
include_directories(${CMAKE_SOURCE_DIR})
add_executable(TestContact tests/test_contact.cpp contact.cpp)
add_executable(TestDate tests/test_date.cpp date.cpp)
add_executable(TestNetwork tests/test_network.cpp network.cpp contact.cpp date.cpp person.cpp misc.cpp)
