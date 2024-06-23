#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

template<typename T>
void print_some(std::vector<T> &v) {
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << " ]" << std::endl;
}

constexpr ll N = 1e8;

int main() {
    std::vector<bool> sieve(N + 1);
    std::fill(sieve.begin(), sieve.end(), true);

    std::vector<ll> primes;

    for (ll p = 2; p <= N; p++) {
        if (!sieve[p]) { continue; }

        primes.push_back(p);

        for (ll j = 2; j * p <= N; j++) {
            sieve[j * p] = false;
        }
    }

    double total = 0;
    double prod = 1;

    for (ll i = 0; i < primes.size(); i++) {
        prod *= 1 - 1 / (double) primes[i];

        total += prod * std::pow(primes[i] - 1, -3);
    }

    std::cout << std::setprecision(13) << total << std::endl;

    return 0;
}
