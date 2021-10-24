cmake_minimum_required(VERSION 3.20.3)

project(knapsack)
add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE -O2 -fprofile-use -fextended-identifiers)