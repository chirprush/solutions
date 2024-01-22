/*
ID: rush0401
TASK: barn1
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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    // We kinda don't need S right
    int M, S, C;
    std::cin >> M >> S >> C;

    std::vector<int> stalls;

    for (int i = 0; i < C; i++) {
        int s;
        std::cin >> s;

        stalls.push_back(s);
    }

    std::sort(stalls.begin(), stalls.end());

    if (M >= C) {
        std::cout << C << std::endl;
        return 0;
    }

    std::vector<int> diffs;

    for (int i = 1; i < C; i++) {
        diffs.push_back(stalls[i] - stalls[i-1]);
    }

    std::sort(diffs.begin(), diffs.end());

    int sum = M;

    // Sum all but the last M - 1 elements.
    for (int i = 0; i < C - M; i++) {
        sum += diffs[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
