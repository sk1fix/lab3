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
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
