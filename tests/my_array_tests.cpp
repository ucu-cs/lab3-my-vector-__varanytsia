#include <gtest/gtest.h>
#include "../include/my_array.h"
#include <string>
#include <numeric>
#include <sstream>

TEST(MyArrayTest, ElementAccess) {
    my_array<int, 5> arr;
    arr.fill(42);

    EXPECT_EQ(arr[0], 42);
    EXPECT_EQ(arr.at(4), 42);
    EXPECT_THROW(arr.at(5), std::out_of_range);

    arr[2] = 100;
    EXPECT_EQ(arr[2], 100);
}

TEST(MyArrayTest, FrontBackData) {
    my_array<std::string, 3> arr;
    arr[0] = "first";
    arr[1] = "middle";
    arr[2] = "last";

    EXPECT_EQ(arr.front(), "first");
    EXPECT_EQ(arr.back(), "last");
    EXPECT_EQ(arr.data()[1], "middle");
}

TEST(MyArrayTest, Iterators) {
    my_array<int, 4> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    int expected = 1;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        EXPECT_EQ(*it, expected++);
    }

    std::reverse(arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 4);
    EXPECT_EQ(arr[3], 1);
}

TEST(MyArrayTest, FillMethod) {
    my_array<int, 10> arr;
    arr.fill(7);
    for (std::size_t i = 0; i < arr.size(); ++i) {
        EXPECT_EQ(arr[i], 7);
    }
}

TEST(MyArrayTest, SwapMethod) {
    my_array<int, 3> a1;
    my_array<int, 3> a2;

    a1[0] = 1; a1[1] = 2; a1[2] = 3;
    a2[0] = 4; a2[1] = 5; a2[2] = 6;

    a1.swap(a2);

    EXPECT_EQ(a1[0], 4);
    EXPECT_EQ(a2[2], 3);
}

TEST(MyArrayTest, ComparisonOperators) {
    my_array<int, 3> a1 = {1, 2, 3};
    my_array<int, 3> a2 = {1, 2, 3};
    my_array<int, 3> a3 = {1, 2, 4};
    my_array<int, 3> a4 = {0, 2, 3};

    EXPECT_TRUE(a1 == a2);
    EXPECT_FALSE(a1 != a2);
    EXPECT_TRUE(a1 < a3);
    EXPECT_TRUE(a4 < a1);
    EXPECT_TRUE(a3 > a1);
    EXPECT_TRUE(a1 <= a2);
    EXPECT_TRUE(a3 >= a2);
}

TEST(MyArrayTest, EmptySizeMaxSize) {
    my_array<double, 7> arr;
    EXPECT_FALSE(arr.empty());
    EXPECT_EQ(arr.size(), 7);
    EXPECT_EQ(arr.max_size(), 7);
}


TEST(MyArrayTest, StdCopy) {
    my_array<int, 5> src;
    my_array<int, 5> dst;
    std::iota(src.begin(), src.end(), 1);

    std::copy(src.begin(), src.end(), dst.begin());

    for (std::size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(src[i], dst[i]);
    }
}

TEST(MyArrayTest, TransformSquare) {
    my_array<int, 4> input = {1, 2, 3, 4};
    my_array<int, 4> output;

    std::transform(input.begin(), input.end(), output.begin(),
                   [](int x) { return x * x; });

    EXPECT_EQ(output[0], 1);
    EXPECT_EQ(output[1], 4);
    EXPECT_EQ(output[2], 9);
    EXPECT_EQ(output[3], 16);
}

TEST(MyArrayTest, NestedMyArray) {
    my_array<my_array<int, 2>, 3> matrix;

    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 2; ++j) {
            matrix[i][j] = static_cast<int>(i * 10 + j);
        }
    }

    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[0][1], 1);
    EXPECT_EQ(matrix[1][0], 10);
    EXPECT_EQ(matrix[1][1], 11);
    EXPECT_EQ(matrix[2][1], 21);
}

TEST(MyArrayTest, CompatibleRangeForAndStdCopy) {
    my_array<std::string, 3> words = {"hello", "cpp", "world"};
    my_array<std::string, 3> copy;

    std::copy(words.begin(), words.end(), copy.begin());

    for (std::size_t i = 0; i < 3; ++i) {
        EXPECT_EQ(words[i], copy[i]);
    }

    std::string result;
    for (const auto& word : copy) {
        result += word + " ";
    }

    EXPECT_EQ(result, "hello cpp world ");
}