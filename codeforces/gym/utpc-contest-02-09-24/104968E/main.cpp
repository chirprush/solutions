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
    int N;
    std::cin >> N;

    // std::vector<std::pair<int, int>> pizzas;
    std::map<int, std::vector<int>> pizzas;

    int max_t = 0;
    int total = 0;

    for (int i = 0; i < N; i++) {
        int s, q, c, v;
        std::cin >> s >> q >> c >> v;

        int d = std::min(s * q, (s - 1) * c + q);
        // pizzas.push_back(std::make_pair(v, d));

        pizzas[d].push_back(v);

        // This is terrible but nobody asked
        std::sort(pizzas[d].begin(), pizzas[d].end());

        total += v;
        max_t = std::max(max_t, d);
    }

    int t = 0;

    std::map<int, std::vector<int>>::iterator it = pizzas.begin();

    while (t <= max_t && it != pizzas.end()) {
        if (it->second.size() == 0) {
            it++;
            continue;
        } else if (t > it->first) {
            it++;
            continue;
        }

        total -= it->second[it->second.size() - 1];
        it->second.erase(it->second.begin() + (it->second.size() - 1));
        t++;
    }

    std::cout << total << std::endl;

    // std::sort(pizzas.begin(), pizzas.end(), [](std::pair<int, int> l, std::pair<int, int> r) { return l.first > r.first; });

    return 0;
}
