enable_testing()

add_executable(my_array_tests
        my_array_tests.cpp
        ../include/my_array.h
)


target_link_libraries(my_array_tests
        PRIVATE
        GTest::gtest
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(my_array_tests)
