/*
ID: rush0401
TASK: friday
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <cstdio>

typedef long long ll;

template<typename T>
void read_some(std::vector<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

template<typename T>
void print_some(std::vector<T> &v) {
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << std::endl;
}

bool leap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<int> lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> freq(7);

    int day = 2;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            freq[(day + 12) % 7]++;

            day += lengths[j] + (int)(j == 1 && leap(1900 + i));
        }
    }

    print_some(freq);

    return 0;
}
