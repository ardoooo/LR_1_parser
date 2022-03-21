cmake_minimum_required(VERSION 3.1)

target_link_libraries(Test Library)

target_link_libraries(Test gtest_main gtest gmock Threads::Threads)