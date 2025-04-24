// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "include/my_array.h"

int main() {
    my_array<int, 5> arr;

    arr.fill(10);
    std::cout << "After fill(10): ";
    for (auto v : arr) std::cout << v << ' ';
    std::cout << '\n';

    arr[2] = 42;
    std::cout << "After arr[2] = 42: ";
    for (auto v : arr) std::cout << v << ' ';
    std::cout << '\n';

    try {
        std::cout << "Element at(2): " << arr.at(2) << '\n';
        std::cout << "Element at(10): ";
        std::cout << arr.at(10) << '\n';
    } catch (const std::out_of_range& ex) {
        std::cout << "Caught exception: " << ex.what() << '\n';
    }

    std::cout << "Front: " << arr.front() << ", Back: " << arr.back() << '\n';

    my_array<int, 5> other = {10, 10, 42, 10, 10};
    std::cout << "arr == other: " << (arr == other) << '\n';

    my_array<int, 5> swap_arr = {1, 2, 3, 4, 5};
    arr.swap(swap_arr);
    std::cout << "After swap with {1,2,3,4,5}: ";
    for (auto v : arr) std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}
