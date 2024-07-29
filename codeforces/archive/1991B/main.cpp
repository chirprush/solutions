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

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        std::vector<ll> b;
        read_some(b, n - 1);

        std::vector<std::vector<ll>> a(n, std::vector<ll>(30, -1));

        bool ok = true;

        for (ll i = 0; i < n - 1; i++) {
            for (ll bit = 0; bit < 30; bit++) {
                ll mask = (1 << bit);
                ll bibit = (b[i] & mask) >> bit;

                // We are given that a[i] & a[i+1] = b[i]
                if (bibit == 0) {
                    if (a[i][bit] == 1) {
                        a[i + 1][bit] = 0;
                    } else if (a[i][bit] == 0) {
                        a[i + 1][bit] = -1;
                    } else {
                        a[i][bit] = 0;
                        a[i + 1][bit] = -1;
                    }
                } else {
                    if (a[i][bit] == 0) {
                        // std::cerr << "Bad bit at (i, bit) = (" << i << ", " << bit << ")" << std::endl;
                        ok = false;
                        break;
                    }

                    a[i][bit] = 1;
                    a[i + 1][bit] = 1;
                }
            }

            if (!ok) {
                break;
            }
        }

        if (!ok) {
            std::cout << -1 << std::endl;
        } else {
            for (ll i = 0; i < n; i++) {
                ll total = 0;

                for (ll bit = 0; bit < 30; bit++) {
                    // std::cout << "a[" << i << "][" << bit << "] = " << a[i][bit] << std::endl;
                    a[i][bit] = (a[i][bit] == -1) ? 0 : a[i][bit];
                    total += (1 << bit) * a[i][bit];
                }

                std::cout << total << " ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
