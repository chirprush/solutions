#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>

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

        std::vector<ll> a;
        read_some(a, n);

        std::map<ll, std::vector<ll>> congruences;

        for (ll i = 0; i < n; i++) {
            congruences[a[i] % k].push_back(a[i]);
        }

        ll odds = 0;

        ll ops = 0;

        for (auto it = congruences.begin(); it != congruences.end(); it++) {
            odds += it->second.size() % 2;

            std::sort(it->second.begin(), it->second.end());

            for (int i = 0; i < it->second.size(); i++) {
                it->second[i] = (it->second[i] - it->first) / k;
            }

            if (it->second.size() % 2 == 0) {
                for (int i = 0; i < it->second.size(); i++) {
                    ops += (i % 2 == 0 ? -1 : 1) * it->second[i];
                }
            } else {
                // Go casewise on which element to delete using brute force
                ll minimum = std::numeric_limits<ll>::max();

                std::vector<ll> prefix(it->second.size() + 1);
                std::vector<ll> suffix(it->second.size() + 1);

                for (int i = 0; i < it->second.size(); i++) {
                    prefix[i + 1] = prefix[i] + (i % 2 == 0 ? -1 : 1) * it->second[i];
                    suffix[it->second.size() - i - 1] = suffix[it->second.size() - i] + ((it->second.size() - i - 1) % 2 == 0 ? -1 : 1) * it->second[it->second.size() - i - 1];
                }

                for (int i = 0; i < it->second.size(); i++) {
                    minimum = std::min(minimum, prefix[i] - suffix[i + 1]);
                }

                ops += minimum;
            }
        }

        if (odds > 1) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::cout << ops << std::endl;
    }

    return 0;
}
