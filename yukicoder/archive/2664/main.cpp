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

bool dfs(int i, std::vector<int> &x, std::vector<int> *adj, std::vector<bool> &visited) {
    if (visited[i]) {
        return false;
    }

    visited[i] = true;

    bool okay = true;

    for (int j : adj[i]) {
        if (visited[j] && (x[i] + x[j]) % 2 != 1) {
            return false;
        }

        if (!visited[j]) {
            x[j] = (x[i] + 1) % 2;
            okay = dfs(j, x, adj, visited) && okay;
        }
    }

    return okay;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);
    std::vector<int> adj[101];

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;

        u--;  v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> visited(n);

    bool good = true;

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        x[i] = 0;
        if (!dfs(i, x, adj, visited)) {
            good = false;
            break;
        }
    }

    if (good) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
