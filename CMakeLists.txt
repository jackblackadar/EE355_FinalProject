cmake_minimum_required(VERSION 3.15)
project("EE355 Final Project")

# Tests
add_executable(TestContact tests/test_contact.cpp contact.cpp)
add_executable(TestDate tests/test_date.cpp date.cpp)