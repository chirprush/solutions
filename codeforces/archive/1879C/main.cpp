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

constexpr ll M = 998244353;

ll factmod(ll n) {
    ll product = 1;

    for (ll i = 2; i <= n; i++) {
        product *= i;
        product %= M;
    }

    return product;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::vector<int> blocks;

        std::string s;
        std::cin >> s;

        char current = s[0];
        int length = 0;

        for (const auto &c : s) {
            if (c == current) {
                length++;
            } else {
                blocks.push_back(length);
                current = c;
                length = 1;
            }
        }

        blocks.push_back(length);

        ll sum = 0;
        ll product = 1;

        for (const auto &l : blocks) {
            sum += l - 1;

            product *= factmod(l);
            product %= M;
        }

        std::cout << sum << " " << product << std::endl;
    }

    return 0;
}
