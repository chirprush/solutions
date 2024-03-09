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

ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int dfs(int i, std::vector<std::vector<int>> &adj, std::vector<bool> &visited) {
    if (visited[i]) { return 0; }

    visited[i] = true;

    int count = 1;

    for (int &j : adj[i]) {
        count += dfs(j, adj, visited);
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;

    constexpr ll M = 1e9 + 7;

    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<bool> visited(n);
    std::vector<int> children;

    visited[0] = true;

    for (int &i : adj[0]) {
        children.push_back(dfs(i, adj, visited));
    }

    ll count = 0;

    for (int i = 0; i < children.size(); i++) {
        for (int j = 0; j < children[i]; j++) {
            count += modpow(3, j, M);
            count %= M;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
