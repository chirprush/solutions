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
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> costs;
    std::vector<std::vector<bool>> avail(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            bool a;
            std::cin >> a;
            avail[i].push_back(a);
        }

        int cost;
        std::cin >> cost;

        costs.push_back(std::make_pair(i, cost));
    }
    
    // Checking takes O(n^2) time hmm
    ll pay = 0;

    std::sort(costs.begin(), costs.end(), [](std::pair<int, int> &p1, std::pair<int, int> &p2) { return p1.second > p2.second; });

    

    return 0;
}
