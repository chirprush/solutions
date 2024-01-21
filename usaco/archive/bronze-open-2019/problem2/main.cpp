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

void check(const std::vector<std::vector<int>> &g, std::vector<bool> &checked, int i) {
    for (int j : g[i]) {
        if (!checked[j]) {
            checked[j] = true;
            check(g, checked, j);
        }
    }
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int N;

    std::cin >> N;
    std::vector<std::vector<int>> g(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;

        // Dual
        g[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < N; i++) {
        std::vector<bool> checked(N);

        checked[i] = true;
        check(g, checked, i);

        bool all = true;
        for (int j = 0; j < N; j++) {
            all = all && checked[j];
        }

        if (all) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}
