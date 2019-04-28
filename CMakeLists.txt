cmake_minimum_required(VERSION 3.9)
project(uni_project_parallel C)

set(CMAKE_C_STANDARD 99)

add_executable(uni_project_parallel main.c stopper.c stopper.h)