#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

constexpr ll N = 100;
ll spf[N + 1] = {0};

void factor(std::map<ll, ll> &f, ll n) {
    while (n != 1) {
        f[spf[n]]++;
        n /= spf[n];
    }
}

ll solve(ll n) {
    std::map<ll, ll> f;
    factor(f, n);

    ll answer = 0;
    for (auto it = f.begin(); it != f.end(); it++) {
        ll p = it->first;
        ll e = it->second;

        int k = 1;
        int power = 1;
        while (power < e) {
            k++;

            power++;
            int kcopy = k;
            while (kcopy % p == 0) {
                power++;
                kcopy /= p;
            }
        }

        answer = std::max(answer, k * p);
    }

    return answer;
}

ll solve2(ll n) {
    std::map<ll, ll> f;
    factor(f, n);

    std::vector<std::pair<ll, ll>> factors(f.begin(), f.end());

    std::sort(factors.begin(), factors.end(), [](const std::pair<ll, ll> &left, const std::pair<ll, ll> &right) { return left.second * std::log(left.first) > right.second * std::log(right.first); });

    ll p = factors[0].first;
    ll e = factors[0].second;

    int k = 1;
    int power = 1;
    while (power < e) {
        k++;

        power++;
        int kcopy = k;
        while (kcopy % p == 0) {
            power++;
            kcopy /= p;
        }
    }

    return k * p;

    /*
    std::cout << "[ ";
    for (int i = 0; i < factors.size(); i++) {
        std::cout << "(" << factors[i].first << ", " << factors[i].second << ") ";
    }
    std::cout << "]" << std::endl;
    */

    // ll answer = 0;

    /*
    for (auto it = f.begin(); it != f.end(); it++) {
        ll p = it->first;
        ll e = it->second;

        int k = 1;
        int power = 1;
        while (power < e) {
            k++;

            power++;
            int kcopy = k;
            while (kcopy % p == 0) {
                power++;
                kcopy /= p;
            }
        }

        answer = std::max(answer, k * p);
    }
    */

    // return answer;
}

int main() {
    ll sum = 0;

    for (ll i = N; i >= 2; i--) {
        for (ll j = 1; i * j <= N; j++) {
            spf[i * j] = i;
        }
    }

    std::cerr << "Sieve done processing" << std::endl;

    for (ll i = 2; i <= N; i++) {
        // std::cout << i << " " << value << std::endl;
        if (solve(i) != solve2(i)) {
            std::cout << i << " is a bad number" << std::endl;
        }
        sum += solve(i);
    }

    std::cout << sum << std::endl;

    return 0;
}
