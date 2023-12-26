#pragma once
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
    stats& operator+=(const stats a) {
        comparison_count += a.comparison_count;
        copy_count += a.copy_count;
        return *this;
    }
};

template <typename T>
stats BubleSort(vector<T>& data) {
    stats stat;
    int size = data.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            stat.comparison_count += 1;
            if (data[j] > data[j + 1]) {
                stat.copy_count += 1;
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template <typename T>
stats quickSort(vector<T>& data, int low, int high) {
    stats stat;
    if (low < high) {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            stat.comparison_count++;
            if (data[j] < pivot) {
                i++;
                swap(data[i], data[j]);
                stat.copy_count++;
            }
        }
        std::swap(data[i + 1], data[high]);
        stat.copy_count++;
        int pi = i + 1;

        stats left_stats = quickSort(data, low, pi - 1);
        stats right_stats = quickSort(data, pi + 1, high);

        stat.comparison_count += left_stats.comparison_count + right_stats.comparison_count;
        stat.copy_count += left_stats.copy_count + right_stats.copy_count;
    }
    return s;
}
template <typename T>
stats CombSort(vector<T>& data) {
    stats stat;
    int size = data.size();
    int gap = size;
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = (gap / shrink) > 1 ? (gap / shrink) : 1;
        if (gap == 1)
            sorted = true;

        for (int i = 0; i + gap < size; ++i) {
            stat.comparison_count += 1;
            if (data[i] > data[i + gap]) {
                stat.copy_count += 1;
                int temp = data[i];
                data[i] = data[i + gap];
                data[i + gap] = temp;
                sorted = false;
            }
        }
    }
    return stat;
}

template<typename T>
std::vector<T> random(T a, T b, int n, size_t i) {
    std::vector<int> res;
    std::mt19937 gen(i);
    std::uniform_int_distribution<> distribution(a, b);
    for (size_t i = 0; i < n; i++) {
        size_t x = distribution(generator);
        res.push_back(x);
    }
    return res;
}
