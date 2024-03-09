#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

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
    int t;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        if (n == 2) {
            std::cout << "6 10" << std::endl;
            continue;
        }

        ll left = (n - 1) * (n - 2) / 2;
        ll K = left + n - (left % n);
        ll k = n + 1;
        ll start = (k * k - k - K) / n;

        std::vector<ll> a;
        a.push_back(start);

        for (int i = 1; i < n - 1; i++) {
            a.push_back(start + i);
        }

        K -= (n - 1) * (n - 2) / 2;

        a.push_back(start + n + 1);

        for (int i = n - 2; i >= 1; i--) {
            ll diff = std::min(a[i+1] - a[i] - 1, K);
            a[i] += diff;
            K -= diff;
        }

        std::cout << a[0];

        for (int i = 1; i < n; i++) {
            std::cout << " " << a[i];
        }

        std::cout << std::endl;
    }

    return 0;
}
