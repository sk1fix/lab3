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
ostream& operator << (ostream& out, stats& s) {
    cout << "Comparsions: " << s.comparison_count << "  Copies: " << s.copy_count << " ";
    return out;
}
template <typename T>
stats BubleSort(vector<T>& data) {
    stats stat;
    int size = data.size();
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1-i; j++) {
            stat.comparison_count += 1;
            if (data[j] > data[j + 1]) {
                stat.copy_count += 1;
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return stat;
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
        swap(data[i + 1], data[high]);
        stat.copy_count++;
        int pi = i + 1;

        stats left_stats = quickSort(data, low, pi - 1);
        stats right_stats = quickSort(data, pi + 1, high);

        stat.comparison_count += left_stats.comparison_count + right_stats.comparison_count;
        stat.copy_count += left_stats.copy_count + right_stats.copy_count;
    }
    return stat;
}

template <typename T>
stats CombSort(vector<T>& data) {
    stats stat;
    double factor = 1.2473309;
    int step = data.size() - 1;
    int size = data.size();
    while (step >= 1)
    {
        for (int i = 0; i + step < size; i++)
        {
            stat.comparison_count += 1;
            if (data[i] > data[i + step])
            {
                stat.copy_count += 1;
                T temp = data[i];
                data[i] = data[i + step];
                data[i + step] = temp;
            }
        }
        step /= factor;
    }
    return stat;
}

template<typename T>
vector<T> random(T a, T b, int n, size_t i) {
    vector<int> res;
    mt19937 gen(i);
    uniform_int_distribution<> distribution(a, b);
    for (size_t i = 0; i < n; i++) {
        size_t x = distribution(gen);
        res.push_back(x);
    }
    return res;
}
