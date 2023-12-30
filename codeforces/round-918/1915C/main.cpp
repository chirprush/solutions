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

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        ll sum = 0;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            ll a;
            std::cin >> a;
            sum += a;
        }

        double S = std::sqrt(sum);
        if (S - std::floor(S) > 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}
