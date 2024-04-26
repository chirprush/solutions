#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <bitset>

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

void dfs(int i, std::vector<int> *adj, bool *visited, int *includes) {
    if (visited[i]) {
        return;
    }

    visited[i] = true;

    includes[i] = 1 << i;

    for (int j : adj[i]) {
        if (!visited[j]) {
            dfs(j, adj, visited, includes);
        }

        includes[i] |= includes[j];
    }
}

int solve(int n, int i, int lamps, int mask, int *bitmasks, int *includes) {
    int c = count(lamps);
    if (i == n + 1 && c > 0 && c <= n / 5) {
        return mask;
    } else if (i == n + 1) {
        return 0;
    }

    // Case current bit is 0 (or potentially 1 if we set it earlier)
    int newmask = solve(n, i + 1, lamps, mask, bitmasks, includes);
    if (newmask) {
        return newmask;
    }
    
    // Case current bit is 1
    for (int j = 1; j <= n; j++) {
        if (bitat(includes[i], j) && !bitat(mask, j)) {
            mask |= (1 << j);
            lamps ^= bitmasks[j];
        }
    }

    newmask = solve(n, i + 1, lamps, mask, bitmasks, includes);

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

        std::vector<int> adj[20];
        
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;

            adj[u].push_back(v);
        }

        int bitmasks[20] = {};

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * i <= n; j++) {
                bitmasks[i] |= 1 << (i * j);
            }
        }

        int combined[20] = {};
        int includes[20] = {};
        bool visited[20] = {};

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, includes);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (bitat(includes[i], j)) {
                    combined[i] ^= bitmasks[j];
                }
            }
        }

        int mask = solve(n, 1, 0, 0, bitmasks, includes);

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
