#pragma once
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
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
void swap(T& a, T& b, stats& stat) {
    T temp = a;
    a = b;
    b = temp;
    stat.copy_count += 3;
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
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return stat;
}

template <typename T>
stats quickSort(vector<T>& arr) {
    vector<pair<T, T>> stack;
    stack.push_back(make_pair(0, arr.size() - 1));
    stats stat;
    while (!stack.empty()) {
        pair<int, int> curr = stack.back();
        stack.pop_back();
        int low = curr.first;
        int high = curr.second;
        while (low < high) {
            int pivot = arr[(low + high) / 2];
            int i = low;
            int j = high;
            while (i <= j) {
                while (arr[i] < pivot) {
                    i++;
                    stat.comparison_count++;
                }
                while (arr[j] > pivot) {
                    j--;
                    stat.comparison_count++;
                }
                if (i <= j) {
                    swap(arr[i], arr[j], stat);
                    i++;
                    j--;
                }
            }
            if (j - low < high - i) {
                if (low < j)
                    stack.push_back(make_pair(low, j));
                low = i;
            }
            else {
                if (i < high)
                    stack.push_back(make_pair(i, high));
                high = j;
            }
        }
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
