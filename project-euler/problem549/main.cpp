#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

constexpr ll N = 100000000;
ll spf[N + 1] = {0};
bool prime[N + 1] = {0};
std::map<std::pair<ll, ll>, ll> s;

void factor(std::map<ll, ll> &f, ll n) {
    while (n != 1) {
        f[spf[n]]++;
        n /= spf[n];
    }
}

// Honestly another optimization you could make rather than
ll solve(ll n) {
    std::map<ll, ll> f;
    factor(f, n);

    ll answer = 0;

    for (auto it = f.begin(); it != f.end(); it++) {
        answer = std::max(answer, s[*it]);
    }

    return answer;
}

int main() {
    ll sum = 0;

    std::fill(prime, prime + N + 1, true);

    for (ll i = 2; i <= (ll) std::sqrt(N) + 1; i++) {
        if (!prime[i]) { continue; }

        for (ll j = 2; i * j <= N; j++) {
            prime[i * j] = false;
        }
    }

    std::cerr << "Sieve done processing" << std::endl;

    for (ll p = 2; p <= N; p++) {
        if (p % 1000000 == 0) {
            std::cerr << (p / 1000000) << "/100" << std::endl;
        }
        if (!prime[p]) { continue; }

        spf[p] = p;

        // Populate s
        ll current = 0;
        ll power = 0;
        ll mult = 1;

        while (current <= (ll) ((double) std::log(N) / std::log(p))) {
            power++;
            ll tmp = mult;

            while (tmp % p == 0) {
                power++;
                tmp /= p;
            }

            for (; current <= power; current++) {
                s[std::make_pair(p, current)] = p * mult;
            }

            mult++;
        }

        for (ll j = p; p * j <= N; j++) {
            if (spf[p * j] == 0) { spf[p * j] = p; }
            spf[p * j] = std::min(p, spf[p * j]);
        }
    }

    std::cerr << "Preprocessing done" << std::endl;

    for (ll i = 2; i <= N; i++) {
        if (i % 1000000 == 0) {
            std::cerr << (i / 1000000) << "/100" << std::endl;
        }
        sum += solve(i);
    }

    std::cout << sum << std::endl;

    return 0;
}
