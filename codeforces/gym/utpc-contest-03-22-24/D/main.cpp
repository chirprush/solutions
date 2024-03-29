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

void dfs(int i, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<bool> &asked, std::set<int> &higher) {
    if (visited[i]) {
        return;
    }

    visited[i] = true;

    for (int j : adj[i]) {
        if (visited[j]) { continue; }

        if (higher.find(j) != higher.end()) {
            asked[i] = true;
        }

        dfs(j, adj, visited, asked, higher);

        asked[i] = asked[j] || asked[i];
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> r;
    read_some(r, n);

    std::set<int> higher;
    std::vector<bool> visited(n);

    // Nobody
    std::vector<bool> asked(n);
    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        if (r[i] >= r[0]) {
            higher.insert(i);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    dfs(0, adj, visited, asked, higher);

    for (int i = 1; i < n; i++) {
        if (asked[i]) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
