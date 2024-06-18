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
    int t;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        ll max = 0;
        ll best = 2;

        for (ll x = 2; x <= n; x++) {
            ll k = n / x;
            ll sum = x * k * (k + 1) / 2;

            if (sum > max) {
                max = sum;
                best = x;
            }
        }

        std::cout << best << std::endl;
    }

    return 0;
}
