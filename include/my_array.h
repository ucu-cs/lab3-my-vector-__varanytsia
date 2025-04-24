#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <cstddef>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <type_traits>

template<typename T, std::size_t N>
class my_array {
public:
    constexpr my_array() = default;

    constexpr my_array(std::initializer_list<T> init) {
        if (init.size() != N) {
            throw std::length_error("Initializer list size must match array size");
        }
        std::size_t i = 0;
        for (const auto& val : init) {
            data_[i++] = val;
        }
    }

    T &operator[](std::size_t i) noexcept { return data_[i]; }
    const T &operator[](std::size_t i) const noexcept { return data_[i]; }

    T &at(std::size_t i) {
        if (i >= N) throw std::out_of_range("Index out of range");
        return data_[i];
    }

    const T &at(std::size_t i) const {
        if (i >= N) throw std::out_of_range("Index out of range");
        return data_[i];
    }

    T &front() { return data_[0]; }
    const T &front() const { return data_[0]; }

    T &back() { return data_[N - 1]; }
    const T &back() const { return data_[N - 1]; }

    T *data() noexcept { return data_; }
    const T *data() const noexcept { return data_; }

    T *begin() noexcept { return data_; }
    const T *begin() const noexcept { return data_; }
    const T *cbegin() const noexcept { return data_; }

    T *end() noexcept { return data_ + N; }
    const T *end() const noexcept { return data_ + N; }
    const T *cend() const noexcept { return data_ + N; }

    std::reverse_iterator<T *> rbegin() noexcept { return std::reverse_iterator<T *>(end()); }
    std::reverse_iterator<const T *> rbegin() const noexcept { return std::reverse_iterator<const T *>(end()); }
    std::reverse_iterator<const T *> crbegin() const noexcept { return std::reverse_iterator<const T *>(end()); }

    std::reverse_iterator<T *> rend() noexcept { return std::reverse_iterator<T *>(begin()); }
    std::reverse_iterator<const T *> rend() const noexcept { return std::reverse_iterator<const T *>(begin()); }
    std::reverse_iterator<const T *> crend() const noexcept { return std::reverse_iterator<const T *>(begin()); }

    [[nodiscard]] constexpr bool empty() const noexcept { return N == 0; }
    [[nodiscard]] constexpr std::size_t size() const noexcept { return N; }
    [[nodiscard]] constexpr std::size_t max_size() const noexcept { return N; }

    void fill(const T& value) {
        for (std::size_t i = 0; i < N; ++i) {
            data_[i] = value;
        }
    }

    void swap(my_array &other) noexcept(std::is_nothrow_swappable_v<T>) {
        for (std::size_t i = 0; i < N; ++i) {
            std::swap(data_[i], other.data_[i]);
        }
    }

    friend bool operator==(const my_array &lhs, const my_array &rhs) {
        for (std::size_t i = 0; i < N; ++i) {
            if (!(lhs[i] == rhs[i])) return false;
        }
        return true;
    }

    friend bool operator!=(const my_array &lhs, const my_array &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const my_array &lhs, const my_array &rhs) {
        for (std::size_t i = 0; i < N; ++i) {
            if (lhs[i] < rhs[i]) return true;
            if (rhs[i] < lhs[i]) return false;
        }
        return false;
    }

    friend bool operator>(const my_array &lhs, const my_array &rhs) {
        return rhs < lhs;
    }

    friend bool operator<=(const my_array &lhs, const my_array &rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>=(const my_array &lhs, const my_array &rhs) {
        return !(lhs < rhs);
    }

private:
    T data_[N];
};

#endif //MY_ARRAY_H
