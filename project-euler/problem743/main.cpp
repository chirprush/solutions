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

ll powmod(ll a, ll b, ll m){
    ll ans = 1;
    while (b) {
        if (b % 2 == 1) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

int main() {
    constexpr ll n = (ll) 1e16;
    constexpr ll k = (ll) 1e8;

    constexpr ll M = (ll) 1e9 + 7;

    std::vector<ll> factorials(k+1);
    std::vector<ll> inv_factorials(k+1);
    factorials[0] = 1;
    inv_factorials[0] = 1;

    for (ll i = 1; i <= k; i++) {
        if (i % (k / 100) == 0) {
            std::cout << (i / (k / 100)) << std::endl;
        }

        factorials[i] = i * factorials[i-1] % M;
        inv_factorials[i] = powmod(factorials[i], M - 2, M);
    }

    ll count = 0;

    for (ll l = k % 2; l <= k; l += 2) {
        if (l % (k / 100) == 0) {
            std::cout << (l / (k / 100)) << std::endl;
        }

        ll current = factorials[k];
        current = current * inv_factorials[l] % M;
        current = current * inv_factorials[(k - l) / 2] % M;
        current = current * inv_factorials[(k - l) / 2] % M;
        current = current * powmod(2, n / k * l, M) % M;
        count += current % M;
    }

    std::cout << count % M << std::endl;

    return 0;
}
