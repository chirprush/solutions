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

constexpr int dir(char c) {
    if (c == '>') { return 1; }

    return -1;
}

bool dfs(int i, std::vector<std::vector<int>> &adj, std::vector<bool> &visited) {
    if (i == adj.size() - 1) {
        return true;
    } else if (visited[i]) {
        return false;
    }

    visited[i] = true;

    for (int j : adj[i]) {
        if (visited[j]) {
            continue;
        }

        if (dfs(j, adj, visited)) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string top, bottom;
        std::cin >> top >> bottom;

        std::vector<std::vector<int>> adj(2 * n);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                adj[i].push_back(i - 1 + dir(top[i-1]));

                adj[i + n].push_back(i + n - 1 + dir(bottom[i-1]));
            }

            if (i < n - 1) {
                adj[i].push_back(i + 1 + dir(top[i+1]));

                adj[i + n].push_back(i + n + 1 + dir(bottom[i+1]));
            }

            adj[i].push_back(i + n + dir(bottom[i]));
            adj[i + n].push_back(i + dir(top[i]));
        }

        std::vector<bool> visited(2 * n);

        if (dfs(0, adj, visited)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
