#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int solve(std::vector<int> &a, int n) {
    if (n == 1) {
        return 0;
    }

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i+1]) {
            total++;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;

        std::vector<int> a;
        read_some(a, n);

        std::cout << solve(a, n) << std::endl;
    }

    return 0;
}
