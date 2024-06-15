#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

struct Factor {
    double weight;
    ll i;
    ll p;
    ll e;
};

struct FactorCmp {
    bool operator() (const Factor *left, const Factor *right) const {
        if (left->weight == right->weight) { return left->p < right->p; }

        return left->weight < right->weight;
    }
};

ll powmod(ll a, ll b, ll m){
    ll ans = 1;
    while (b) {
        if (b % 2 == 1 ) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

constexpr ll n = 500500;
constexpr ll upper = 1e7;

constexpr ll M = 500500507;

bool sieve[upper] = {0};

Factor bases[n] = {0};

int main() {
    std::vector<ll> primes;

    std::fill(sieve, sieve + upper, true);

    for (ll p = 2; p < upper; p++) {
        if (!sieve[p]) { continue; }

        primes.push_back(p);

        if (primes.size() == n) {
            break;
        }

        for (ll j = 2; j * p < upper; j++) {
            sieve[j * p] = false;
        }
    }

    std::set<const Factor *, FactorCmp> factors;

    for (ll i = 0; i < n; i++) {
        bases[i] = (Factor) { std::log(primes[i]), i, primes[i], 0 };

        factors.insert(&bases[i]);
    }

    ll left = n;

    while (left) {
        auto it = factors.begin();
        const Factor *f = *it;

        factors.erase(it);

        bases[f->i].e += f->e + 1;
        bases[f->i].weight = (f->e + 1) * std::log(f->p);

        factors.insert(&bases[f->i]);

        left--;
    }

    ll prod = 1;

    for (ll i = 0; i < n; i++) {
        if (bases[i].e == 0) { break; }

        prod *= powmod(bases[i].p, bases[i].e, M);
        prod %= M;
    }

    std::cout << (prod % M) << std::endl;

    return 0;
}
