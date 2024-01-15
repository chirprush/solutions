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

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n, f, a, b;
        std::cin >> n >> f >> a >> b;

        std::vector<ll> m;
        read_some(m, n);

        // b >? a * dt
        ll time = 0;
        ll charge = f;
        ll passed = true;

        if (charge <= 0) { passed = false; }

        for (const auto &moment : m) {
            charge -= std::min(b, a * (moment - time));

            if (charge <= 0) {
                passed = false;
                break;
            }
            time = moment;
        }

        if (passed) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
