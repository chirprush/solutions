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

int bitat(int mask, int b) {
    return (mask >> b) & 1;
}

int count(int mask) {
    return __builtin_popcount(mask);
}

int solve(int n, int i, int lamps, int mask, const int *bitmasks, const std::vector<int> *conds) {
    int c = count(lamps);
    if (i == n + 1 && c > 0 && c <= n / 5) {
        return mask;
    } else if (i == n + 1) {
        return 0;
    }

    // Case current bit is 0 (or potentially 1 if we set it earlier)
    int newmask = solve(n, i + 1, lamps, mask, bitmasks, conds);
    if (newmask) {
        return newmask;
    }
    
    // Case current bit is 1
    mask |= 1 << i;
    lamps ^= bitmasks[i];

    // Make this handle chaining (probably by using graphs to do the bitmask thing better)
    for (int v : conds[i]) {
        mask |= 1 << v;
        lamps ^= bitmasks[v];
    }

    newmask = solve(n, i + 1, lamps, mask, bitmasks, conds);

    if (newmask) {
        return newmask;
    }

    return 0;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;

        std::cin >> n >> m;

        std::vector<int> conds[20];

        if (n < 5 || n >= 20) {
            for (int i = 0; i < m; i++) {
                int a, b;
                std::cin >> a >> b;
            }

            if (n < 5) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << n << std::endl;

                for (int i = 1; i <= n; i++) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }

            continue;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;

            conds[u].push_back(v);
        }

        int bitmasks[20] = {};

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * i <= n; j++) {
                bitmasks[i] |= 1 << (i * j);
            }
        }

        int mask = solve(n, 1, 0, 0, bitmasks, conds);

        if (mask) {
            std::cout << count(mask) << std::endl;

            for (int i = 1; i <= n; i++) {
                if (bitat(mask, i)) {
                    std::cout << i << " ";
                }
            }

            std::cout << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}
