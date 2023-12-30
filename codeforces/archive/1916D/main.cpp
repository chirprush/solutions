#include <iostream>
#include <vector>
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

bool is_square(ll n) {
    double S = std::sqrt(n);
    return !(S - (int) S > 0);
}

void solve(int n) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j == i) { continue; }
            ll N = (ll) (1 * std::pow(10, n - 1)) + (ll) (6 * std::pow(10, i)) + (ll) (9 * std::pow(10, j));
            if (is_square(N)) {
                count++;
                std::cout << N << std::endl;
            }

            if (count == n) { return; }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (j == i) { continue; }
            ll N = (ll) (9 * std::pow(10, n - 1)) + (ll) (6 * std::pow(10, i)) + (ll) (1 * std::pow(10, j));
            if (is_square(N)) {
                count++;
                std::cout << N << std::endl;
            }

            if (count == n) { return; }
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    
    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;

        solve(n);
    }
    return 0;
}
