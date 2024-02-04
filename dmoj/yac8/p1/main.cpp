#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

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
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << " ]" << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a;
    read_some(a, N);

    std::vector<bool> sort(N);
    
    // 2 1 3 6 5 4
    // 7 2 1 5 3 4 6 -> 7
    // 2 3 1
    // 2 3 5 1 4
    // 3 2 1 -> 3
    // 1 2 3 4 -> 0

    for (int i = 0; i < N; i++) {
        int start = std::min(i, a[i] - 1);
        int end = std::max(i, a[i] - 1);

        if (start == end) { continue; }

        std::fill(sort.begin() + start, sort.begin() + end + 1, true);
    }

    int cost = 0;

    for (const bool &b : sort) {
        if (b) { cost++; }
    }

    std::cout << cost << std::endl;

    return 0;
}
