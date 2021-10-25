#pragma once
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

namespace utils {

struct Timer
{
    decltype(std::chrono::steady_clock::now()) time_start;
    Timer() : time_start {std::chrono::steady_clock::now()} {}
    ~Timer()
    {
        auto duration = duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - time_start)
                            .count();
        std::cout << duration << "ms\n";
    }
};

void fast_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

/* back_emplacer is a just of std::back_inserter, calling emplace_back(args) instead of
 * push_back(args). */
template <typename Container>
struct back_emplace_iterator
{
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    Container& container;
    back_emplace_iterator(Container& c) : container(c) {}

    template <typename... Args>
    back_emplace_iterator& operator=(Args&&... args)
    {
        container.emplace_back(std::forward<Args>(args)...);
        return *this;
    }

    back_emplace_iterator& operator*() { return *this; }
    back_emplace_iterator& operator++() { return *this; }
    back_emplace_iterator& operator++(int) { return *this; }
};

template <class Container>
auto back_emplacer(Container& c)
{
    return back_emplace_iterator<Container>(c);
}

template <class I, class P, class T>
auto accumulate_if(I first, I last, P pred, T init)
{
    return std::accumulate(first, last, init, [pred](auto&& total, auto&& value) mutable {
        if (*(pred++)) total += value;
        return total;
    });
}

} // namespace utils