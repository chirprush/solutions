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

/* Failed solution; the real solution is actually far simpler :( */
int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        std::vector<ll> a;
        read_some(a, n);

        std::vector<ll> ops; // Heh

        bool bad = false;

        for (ll j = 0; j <= 40; j++) {
            bool quit = true;

            for (ll i = 0; i < n; i++) {
                quit = quit && (a[i] == 0);
            }

            if (quit) {
                break;
            }

            if (j == 40) {
                bad = true;
                break;
            }

            ll op = 0;
            ll best = std::numeric_limits<ll>::min();

            std::sort(a.begin(), a.end());
            std::vector<ll> prefix(n + 1);

            print_some(a);

            for (ll i = 0; i < n; i++) {
                prefix[i+1] = prefix[i] + a[i];
            }

            bool skip = true;

            for (ll i = 0; i <= n; i++) {
                ll previous = (i - 1 < 0) ? 0 : a[i-1];
                ll x = (n - 2 * i >= 0) ? a[i] : previous;
                ll score = (n - 2 * i) * x + 2 * prefix[i];

                if (j == 2) {
                    std::cout << "Score choice: " << score << std::endl;
                }

                if (score != 0 && score > best) {
                    op = x;
                    best = score;
                    skip = false;
                }
            }

            if (skip) {
                continue;
            }

            ops.push_back(op);

            for (ll i = 0; i < n; i++) {
                a[i] = std::abs(a[i] - op);
            }

        }

        if (bad) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::cout << ops.size() << std::endl;
        
        for (ll i = 0; i < ops.size(); i++) {
            std::cout << ops[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
