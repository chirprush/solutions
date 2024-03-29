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

typedef std::vector<std::map<int, int>> Graph;

int dfs(int time, int i, int end, Graph &adj, std::map<std::pair<int, int>, int> &unstable, std::vector<bool> &visited) {
    if (i == end) {
        return time;
    } else if (visited[i]) {
        return -1;
    }

    visited[i] = true;

    int best = -1;

    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
        int j = it->first;
        int t = it->second;

        if (visited[j] || (unstable.count(std::make_pair(i, j)) && time + t > unstable[std::make_pair(i, j)])) { continue; }

        int result = dfs(time + t, j, end, adj, unstable, visited);

        if (result >= 0) {
            best = (best < 0 ? result : std::min(best, result));
        }
    }
    
    return best;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int h, e;
    std::cin >> h >> e;
    h--; e--;

    std::map<std::pair<int, int>, int> unstable;
    Graph adj(n);
    std::vector<bool> visited(n);

    for (int i = 0; i < m; i++) {
        int u, v, t;
        std::cin >> u >> v >> t;
        u--; v--;

        adj[u][v] = t;
        adj[v][u] = t;
    }

    int tornado = 0;
    int start;
    std::cin >> start;
    start--;
    for (int i = 0; i < k - 1; i++) {
        int next;
        std::cin >> next;
        next--;

        tornado += adj[start][next];

        unstable[std::make_pair(start, next)] = tornado;
        unstable[std::make_pair(next, start)] = tornado;

        start = next;
    }

    std::cout << dfs(0, h, e, adj, unstable, visited) << std::endl;
    
    return 0;
}
