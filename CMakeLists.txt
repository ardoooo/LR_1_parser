cmake_minimum_required(VERSION 3.0.0)
project(LR1_parser VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(LR1_parser src/main.cpp src/grammar.cpp include/grammar.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
