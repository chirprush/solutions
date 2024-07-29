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

        std::string a, b;
        std::cin >> a >> b;

        std::vector<std::vector<ll>> aprefix(n + 1, std::vector<ll>(26));
        std::vector<std::vector<ll>> bprefix(n + 1, std::vector<ll>(26));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                aprefix[i][j] = aprefix[i - 1][j] + (a[i - 1] - 'a' == j);
                bprefix[i][j] = bprefix[i - 1][j] + (b[i - 1] - 'a' == j);
            }
        }

        while (q--) {
            ll l, r;
            std::cin >> l >> r;

            l--; r--;

            ll total = 0;

            for (int j = 0; j < 26; j++) {
                total += std::abs(aprefix[r + 1][j] - aprefix[l][j] - (bprefix[r + 1][j] - bprefix[l][j]));
            }

            std::cout << total / 2 << std::endl;
        }
    }

    return 0;
}
