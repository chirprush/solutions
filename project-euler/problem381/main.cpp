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
        if (b % 2 == 1 ) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

ll inv(ll a, ll p) {
    return powmod(a, p - 2, p);
}

ll S(ll p) {
    ll sum = p - 1;
    ll prod = p - 1;

    for (ll i = 1; i <= 4; i++) {
        prod *= inv(p - i, p);
        prod %= p;

        sum += prod;
        sum %= p;
    }

    return sum % p;
}

constexpr ll upper = 1e8;
bool sieve[upper + 1] = {0};

int main() {
    std::fill(sieve, sieve + upper + 1, true);

    std::vector<ll> primes;

    for (ll p = 2; p <= upper; p++) {
        if (!sieve[p]) { continue; }

        primes.push_back(p);

        for (ll j = 2; p * j <= upper; j++) {
            sieve[p * j] = false;
        }
    }

    std::cerr << "Sieve complete" << std::endl;

    ll total = 0;

    for (ll i = 2; i < primes.size(); i++) {
        total += S(primes[i]);
    }

    std::cout << total << std::endl;

    return 0;
}
