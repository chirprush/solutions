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

struct Edge {
    int a;
    int b;
    int dir;
};

constexpr int NONE = 0;
constexpr int FORWARD = 1;
constexpr int BACKWARD = 2;

// This does not work as apparently an even edge count is not 
// sufficient for an answer to exist :( so come back to this
// later I suppose.
//
// Ah! I forgot to decompose by connected and components and solve that way.
// I'll probably fix the solution sometime then
int main() {
    ll n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    std::vector<std::vector<Edge *>> adj(n);

    std::vector<int> degrees(n);

    for (int i = 0; i < m; i++) {
        int a, b;

        std::cin >> a >> b;
        a--; b--;

        edges[i] = (Edge) { a, b, NONE };
        degrees[a]++;
        degrees[b]++;

        adj[a].push_back(&edges[i]);
        adj[b].push_back(&edges[i]);
    }

    if (m % 2 == 1) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::vector<int> order(n);

    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    std::sort(order.begin(), order.end(), [degrees](int left, int right) { return degrees[left] < degrees[right]; });

    for (int j = 0; j < n; j++) {
        int i = order[j];

        int out = 0;

        for (Edge *edge : adj[i]) {
            out += (edge->dir == FORWARD && edge->a == i) || (edge->dir == BACKWARD && edge->b == i);
        }

        // std::cout << "(i, out): " << i << " " << out << std::endl;

        for (Edge *edge : adj[i]) {
            if (out % 2 == 0 && edge->dir == NONE) {
                // std::cout << "Placed edge going in (a, b): " << edge->a << " " << edge->b << std::endl;
                edge->dir = (edge->a == i) ? BACKWARD : FORWARD;
            } else if (out % 2 == 1 && edge->dir == NONE) {
                // std::cout << "Placed edge going out (a, b): " << edge->a << " " << edge->b << std::endl;
                edge->dir = (edge->a == i) ? FORWARD : BACKWARD;
                out++;
            }
        }

        if (out % 2 == 1) {
            // std::cerr << "Bad case" << std::endl;
        }
    }

    for (const Edge &edge : edges) {
        if (edge.dir == FORWARD) {
            std::cout << (edge.a + 1) << " " << (edge.b + 1) << std::endl;
        } else if (edge.dir == BACKWARD) {
            std::cout << (edge.b + 1) << " " << (edge.a + 1) << std::endl;
        } else {
            // std::cerr << "Edge not reached" << std::endl;
        }
    }

    return 0;
}
