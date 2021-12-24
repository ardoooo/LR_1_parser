cmake_minimum_required(VERSION 3.0.0)
project(LR1_parser VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)


add_executable(LR1_parser src/grammar.cpp src/item.cpp src/main.cpp  src/parsing_table.cpp src/state.cpp include/grammar.h include/item.h include/parsing_table.h include/state.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
