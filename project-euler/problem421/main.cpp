#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#include <cstdlib>
#include <ctime>

typedef unsigned long long ll;

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
    srand(time(0));

    constexpr ll N = 1e8;
    constexpr ll L = 1e11;

    std::vector<bool> sieve(N + 1, true);
    std::vector<ll> lpf(N + 1, N);

    std::vector<ll> primes;

    for (ll p = 2; p <= N /* std::ceil(std::sqrt(N)) */; p++) {
        if (!sieve[p]) { continue; }

        lpf[p] = p;

        for (ll j = p; j * p <= N; j++) {
            sieve[j * p] = false;
            lpf[j * p] = std::min(lpf[j * p], p);
        }
    }

    std::cerr << "Sieve completed" << std::endl;
    
    ll total = 0;

    for (ll p = 2; p <= N; p++) {
        if (!sieve[p]) { continue; }

        total += p * (L / p) * std::__gcd((ll) 15, p - 1);

        ll gen;

        // Calculate residual term
        do {
            gen = (rand() % (p - 1) + 1);

            // std::cerr << "(gen, p): " << gen << " " << p << std::endl;

            ll ord = p - 1;
            bool ok = true;

            while (ord > 1) {
                ll q = lpf[ord];

                // std::cerr << "q: " << q << std::endl;

                while (ord % q == 0) { ord /= q; }

                ll test = powmod(gen, (p - 1) / q, p);

                if (test == 1) {
                    ok = false;
                    break;
                }
            }

            // std::cerr << "ok: " << ok << std::endl;

            if (ok) {
                break;
            }
        } while (true);

        std::vector<ll> roots;

        if ((p - 1) % 15 == 0) {
            ll cyc3 = powmod(gen, (p - 1) / 3, p);
            ll cyc5 = powmod(gen, (p - 1) / 5, p);
            
            ll g3 = 1;
            ll g5 = 1;

            for (ll i = 0; i < 3; i++) {
                for (ll j = 0; j < 5; j++) {
                    roots.push_back(g3 * g5 % p);

                    g5 = (g5 * cyc5) % p;
                }

                g3 = (g3 * cyc3) % p;
                g5 = 1;
            }
        } else if ((p - 1) % 5 == 0) {
            ll cyc5 = powmod(gen, (p - 1) / 5, p);
            ll g5 = 1;

            for (ll i = 0; i < 5; i++) {
                roots.push_back(g5);

                g5 = (g5 * cyc5) % p;
            }
        } else if ((p - 1) % 3 == 0) {
            ll cyc3 = powmod(gen, (p - 1) / 3, p);
            ll g3 = 1;

            for (ll i = 0; i < 3; i++) {
                roots.push_back(g3);

                g3 = (g3 * cyc3) % p;
            }
        } else {
            roots.push_back(1);
        }

        for (ll root : roots) {
            if (p - root <= (L % p)) {
                total += p;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
