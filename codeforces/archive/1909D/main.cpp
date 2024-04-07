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
        ll n, k;
        std::cin >> n >> k;

        std::vector<ll> a(n);

        ll g = 0;
        ll q = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];

            a[i] -= k;

            g = std::__gcd(g, a[i]);
        }

        if (g == 0) {
            std::cout << 0 << std::endl;
            continue;
        }

        bool bad = false;

        for (int i = 0; i < n; i++) {
            ll qi = a[i] / g - 1;

            if (qi < 0) {
                std::cout << -1 << std::endl;
                bad = true;
                break;
            }

            q += qi;
        }

        if (bad) { continue; }

        std::cout << q << std::endl;
    }

    return 0;
}
