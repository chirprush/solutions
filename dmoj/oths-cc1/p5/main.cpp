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

int main() {
    ll N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<std::pair<ll, ll>>> graph(N);

    std::vector<ll> builds;
    read_some(builds, K);

    std::vector<ll> contains;
    read_some(contains, K);

    std::vector<std::vector<ll>> locations(K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < contains[i]; j++) {
            ll a;
            std::cin >> a;
            locations[i].push_back(a);
        }
    }

    for (int i = 0; i < M; i++) {
        ll a, b, c;
        std::cin >> a >> b >> c;

        graph[a].push_back(std::make_pair(b, c));
    }

    return 0;
}
