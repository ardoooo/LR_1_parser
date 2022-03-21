cmake_minimum_required(VERSION 3.0.0)
project(LR1_parser)
set(CMAKE_CXX_STANDARD 20)

add_executable(LR1_parser src/grammar.cpp src/item.cpp src/main.cpp  src/parsing_table.cpp src/state.cpp include/grammar.h include/item.h include/parsing_table.h include/state.h)

OPTION(BUILD_TESTS OFF)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(earley_algorithm src/main.cpp)
target_link_libraries(earley_algorithm Library)

if(BUILD_TESTS)
    include(ExternalProject)
    set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake ${PROJECT_SOURCE_DIR})

    set(EXTERNAL_INSTALL_LOCATION ${PROJECT_SOURCE_DIR}/3rdparty)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    find_package(Threads REQUIRED)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
    if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    endif()
    ExternalProject_Add(
            googletest_repo
            GIT_REPOSITORY https://github.com/google/googletest.git
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    )
    include_directories(${EXTERNAL_INSTALL_LOCATION}/include include)
    link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

    add_subdirectory(tests)

    include(CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(
            NAME coverage
            EXECUTABLE Test
    )
endif()