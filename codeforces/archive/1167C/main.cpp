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

std::vector<int> adj[500001];
int visited[500001] = {0};
int component = 0;
int components[500001] = {0};

int dfs(int current) {
    if (visited[current]) { return 0; }

    components[current] = component;

    int sum = 1;
    visited[current] = 1;

    for (int i : adj[current]) {
        sum += dfs(i);
    }

    return sum;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int j;
        std::cin >> j;

        int first;

        for (int l = 0; l < j; l++) {
            if (l == 0) {
                std::cin >> first;
                first--;
            } else {
                int conn;
                std::cin >> conn;
                conn--;

                adj[first].push_back(conn);
                adj[conn].push_back(first);
            }
        }
    }

    std::vector<int> sizes;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            sizes.push_back(dfs(i));
            component++;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << sizes[components[i]] << " ";
    }

    std::cout << std::endl;

    return 0;
}
