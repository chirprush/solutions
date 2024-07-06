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

constexpr ll M = 1e9 + 7;
ll factorials[101] = {0};
ll invfactorials[101] = {0};

ll powmod(ll a, ll b, ll m){
    ll ans = 1;
    while (b) {
        if (b % 2 == 1 ) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n || n < 0) {
        return 0;
    }

    return (factorials[n] * invfactorials[k] % M) * invfactorials[n - k] % M;
}

int main() {
    factorials[0] = 1;

    for (ll k = 1; k <= 100; k++) {
        factorials[k] = k * factorials[k - 1] % M;
    }

    invfactorials[100] = powmod(factorials[100], M - 2, M);

    for (ll k = 99; k >= 0; k--) {
        invfactorials[k] = (k + 1) * invfactorials[k + 1] % M;
    }

    // std::cerr << "Precomputation finished" << std::endl;

    int t;
    std::cin >> t;

    while (t--) {
        ll n, i, j, x, y;

        std::cin >> n >> i >> j >> x >> y;

        if (x == n) {
            // std::cerr << "Case 1" << std::endl;
            if (i == 1 || i == n) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << (comb(n - y - 1, j - i - 1) * comb(y - 1, n - j) % M) << std::endl;
            }
            continue;
        } else if (y == n) {
            // std::cerr << "Case 2" << std::endl;
            if (j == 1 || j == n) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << (comb(n - x - 1, j - i - 1) * comb(x - 1, i - 1) % M) << std::endl;
            }
            continue;
        }

        ll total = 0;

        for (ll k = 2; k <= n - 1; k++) {
            if (k == i || k == j) { continue; }

            if (k < i && x > y) {
                // std::cerr << "Case 3.1 (k = " << k << ")" << std::endl;
                total += (comb(n - x - 1, i - k - 1) * comb(x - y - 1, j - i - 1) % M) * comb(y - 1, n - j) % M;
            } else if (i < k && k < j && x < y && n - std::min(x, y) - 1 >= j - i - 2) {
                // std::cerr << "Case 3.2 (k = " << k << ")" << std::endl;
                total += (comb(n - y - 1, j - k - 1) * comb(y - x - 1, j - i - 1 + y - n) % M) * comb(x - 1, i - 1) % M;
            } else if (i < k && k < j && x > y && n - std::min(x, y) - 1 >= j - i - 2) {
                // std::cerr << "Case 3.3 (k = " << k << ")" << std::endl;
                total += (comb(n - x - 1, k - i - 1) * comb(x - y - 1, j - i - 1 + x - n) % M) * comb(y - 1, n - j) % M;
            } else if (k > j && x < y) {
                // std::cerr << "Case 3.4 (k = " << k << ")" << std::endl;
                total += (comb(n - y - 1, k - j - 1) * comb(y - x - 1, j - i - 1) % M) * comb(x - 1, i - 1) % M;
            }

            total %= M;
            
            // std::cerr << "total (k = " << k << "): " << total << std::endl;
        }

        std::cout << total << std::endl;
    }

    return 0;
}
