#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <cstdio>

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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    ll K, N;
    
    std::cin >> K >> N;

    for (int i = 0; i < N; i++) {
        ll X;
        std::cin >> X;

        ll t = 0;
        ll k = 0;
        ll v = 0;

        // std::cerr << "t = 0: (pos, vel) = (0, 0)" << std::endl;

        while (k < K) {
            for (int i = 1; i >= -1; i--) {
                ll d = (v + i) * (v + i + 1) / 2 - X * (X + 1) / 2;
                bool can = (v + i) <= X || (v + i > X && d < K - k);
                if (v + i > 0 && can) {
                    v = v + i;
                    break;
                }
            }

            t += 1;
            k += v;

            // std::cerr << "t = " << t << ": (pos, vel) = (" << k << ", " << v << ")" << std::endl;
        }

        std::cout << t << std::endl;
    }

    return 0;
}
