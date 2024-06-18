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
        ll x, y, z, k;
        std::cin >> x >> y >> z >> k;

        ll max = 0;

        for (ll i = 1; i <= x; i++) {
            if (k % i != 0) { continue; }

            for (ll j = 1; j <= y; j++) {
                if (k % j != 0 || k % (i * j) != 0) { continue; }

                ll l = k / (i * j);

                max = std::max(max, (x + 1 - i) * (y + 1 - j) * (z + 1 - l));
            }
        }

        std::cout << max << std::endl;
    }

    return 0;
}
