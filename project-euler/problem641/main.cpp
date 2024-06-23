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

constexpr ll upper = 1e8; // 5e8;
ll N = 1e8;

bool sieve[upper] = {0};

// Lmao erm so maybe recursion isn't the best choice for say 6 million primes?
// :skull: Find something else I suppose
ll count(ll i, double logsum, ll odds, std::vector<std::vector<double>> &choices) {
    if (i == choices.size()) {
        return logsum <= std::log(N) && odds % 2 == 0;
    }

    ll total = 0;

    for (ll j = 0; j < choices[i].size(); j++) {
        if (logsum + choices[i][j] > std::log(N)) { break; }

        total += count(i + 1, logsum + choices[i][j], odds + j % 2, choices);
    }

    return total;
}

int main() {
    std::vector<ll> primes;

    std::fill(sieve, sieve + upper + 1, true);

    for (ll p = 2; p <= upper; p++) {
        if (!sieve[p]) { continue; }

        primes.push_back(p);

        for (ll j = 2; j * p <= upper; j++) {
            sieve[j * p] = false;
        }
    }

    std::cerr << "Prime sieve completed: " << primes.size() << " primes found" << std::endl;

    std::vector<std::vector<double>> choices;
    
    for (ll i = 0; i < primes.size(); i++) {
        std::vector<double> powers;

        if (i % (primes.size() / 100) == 0) {
            std::cerr << "Prime " << i << ": " << primes[i] << std::endl;
        }

        ll e = 0;
        while (true) {
            ll result = e * std::log(primes[i]);

            if (result > std::log(N)) { break; }
            powers.push_back(result);
            e += 4;

            result = e * std::log(primes[i]);

            if (result > std::log(N)) { break; }
            powers.push_back(result);
            e += 2;
        }

        // std::cerr << "First too large exponent: " << e << std::endl;

        choices.push_back(powers);
    }

    std::cerr << "Filled choices" << std::endl;

    std::cout << count(0, 0.0, 0, choices) << std::endl;

    return 0;
}
