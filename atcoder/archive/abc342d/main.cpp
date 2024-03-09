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
    int n;
    std::cin >> n;

    std::vector<ll> a;
    read_some(a, n);

    std::map<ll, ll> counts;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            counts[0]++;
            continue;
        }

        // Finish later

        ll value = 1;
        ll p = 2;
        while (a[i] > 1 && p < (ll)std::sqrt(a[i])) {
            ll exp = 0;

            while (a[i] > 1 && a[i] % p == 0) {
                a[i] /= p;
                exp++;
            }

            if (exp % 2) { value *= p; }

            p++;
        }

        counts[value]++;
    }

    ll count = 0;

    for (auto it = counts.begin(); it != counts.end(); it++) {
        count += it->second * (it->second - 1) / 2;

        if (it->first == 0) {
            count += n - it->second;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
