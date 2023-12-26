#pragma once
#include <iostream>
#include <random>
#include <fstream>
#include"stats/main.h"
using namespace std;

int main() {
    int a[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };
    ofstream fout;
    fout.open("D:\\Ycheba\\lab3\\quick_sort2.txt");
    for (size_t i = 0; i < 13; i++) {
		stats b;
		vector<int> temp(a[i]);
		for (size_t j = 0; j < a[i]; j++) {
			temp[j] = j;
		}
		b = quickSort(temp,1,a[i]-1);
        cout << i << endl;
        fout << a[i] << ' ' << b.comparison_count / 100 << ' ' << b.copy_count / 100 << endl;
    }
	fout.close();
}

