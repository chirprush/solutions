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
        ll n, q;
        std::cin >> n >> q;

        std::vector<ll> a(n+1);
        std::vector<ll> inv(n+1);

        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];

            inv[a[i]] = i;
        }

        std::vector<ll> starts(n+1, 1);
        std::vector<ll> ends(n+1, 1);

        for (int i = n; i >= 1; i--) {
            for (int m = 2; m * a[i] <= n; m++) {
                int j = inv[m * a[i]];
                if (j > i) {
                    starts[i] += starts[j];
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            for (int m = 2; m * a[j] <= n; m++) {
                int i = inv[m * a[j]];

                if (j < i) {
                    ends[i] += ends[j]; // 1;
                }
            }
        }

        print_some(starts);
        print_some(ends);

        std::vector<ll> starts_prefix(n+1);
        std::vector<ll> ends_prefix(n+1);

        for (int i = 0; i < n; i++) {
            starts_prefix[i+1] = starts_prefix[i] + starts[i+1];
            ends_prefix[i+1] = ends_prefix[i] + ends[i+1];
        }

        print_some(starts_prefix);
        print_some(ends_prefix);

        for (int i = 0; i < q; i++) {
            ll l, r;
            std::cin >> l >> r;

            if (l == r) {
                std::cout << "1 " << std::endl;
            } else {
                // (paths that start after - paths that end after) - (paths that start before - paths that end before)?
                // not this (starts_prefix[n] - starts_prefix[l - 1]) - (ends_prefix[n] - ends_prefix[r])
                ll count = 0;
                std::cout << count << " ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
