#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>

typedef long long ll;

template<typename T>
void read_some(std::vector<T> &v, ll N) {
    for (ll i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

ll solve_kind1(ll b, ll n) {
    // ll N = (ll) std::ceil(std::sqrt(n));
    ll N = n;
    ll k = 0;

    for (ll p = 2; p <= N; p++) {
        if (n % p == 0 && b % p != 0) { return 0; }
        else if (n % p == 0) {
            ll bprime = 0;
            ll nprime = 0;

            while (n % p == 0) { nprime++; n /= p; }
            while (b % p == 0) { bprime++; b /= p; }

            k = std::max(k, (ll) std::ceil((double) nprime / bprime)); 
        }

        if (n == 1) {
            break;
        }
    }

    return k;
}

/*
ll discrete_log(ll b, ll n, ll a, ll T) {
    return 0;
}
*/

ll intpow(ll p, ll e) {
    ll result = 1;

    while (e) {
        if (e % 2 == 1) {
            result *= p;
        }
        e >>= 1;
        p *= p;
    }

    return result;
}

ll totient(ll n) {
    std::map<ll, ll> primes;
    int N = n;

    for (int p = 2; p <= N; p++) {
        if (n % p == 0) {
            primes[p] = 0;
            while (n % p == 0) { primes[p]++; n /= p; }
        }

        if (n == 1) { break; }
    }

    ll t = 1;

    for (const auto &pair : primes) {
        ll p = pair.first;
        ll e = pair.second;
        t *= intpow(p, e - 1) * (p - 1);
    }

    return t;
}

ll solve_kind2(ll b, ll n, ll T) {
    ll q = b % n;
    ll k = 1;

    while (T % k != 0 || q != 1) {
        q = (q * b) % n;
        k++;
    }

    return k;
}

ll solve_kind3(ll b, ll n, ll T) {
    // I'm sort of assuming a loose upper bound for this is the totient but hey
    // who knows
    ll q = b % n;

    for (ll k = 1; k <= T; k++) {
        if (q == n - 1) {
            return k;
        }
        q = (q * b) % n;
    }

    return 0;
}

int main() {
    ll t;
    std::cin >> t;

    for (ll _ = 0; _ < t; _++) {
        ll b, n;
        std::cin >> b >> n;

        ll k1 = solve_kind1(b, n);

        if (k1 != 0) {
            std::cout << 1 << " " << k1 << std::endl;
        } else {
            if (std::__gcd(b, n) != 1) {
                std::cout << 0 << std::endl;
                continue;
            }

            ll T = totient(n);

            ll k2 = solve_kind2(b, n, T);
            ll k3 = solve_kind3(b, n, T);

            if (k2 == 0) {
                std::cout << 3 << " " << k3 << std::endl;
            } else if (k3 == 0) {
                std::cout << 2 << " " << k2 << std::endl;
            } else if (k2 < k3) {
                std::cout << 2 << " " << k2 << std::endl;
            } else {
                std::cout << 3 << " " << k3 << std::endl;
            }
        }
    }

    return 0;
}
