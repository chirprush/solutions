/*
ID: rush0401
TASK: milk
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

#include <cmath>
#include <cstdio>

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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> farmers;

    for (int i = 0; i < M; i++) {
        int P, A;
        std::cin >> P >> A;

        farmers.push_back(std::make_pair(P, A));
    }

    std::sort(farmers.begin(), farmers.end(), [](const std::pair<int,int> &left, const std::pair<int, int> &right) { return left.first < right.first; });

    int cost = 0;

    for (int i = 0; i < M; i++) {
        int j = std::min(farmers[i].second, N);

        N -= j;
        cost += farmers[i].first * j;

        if (N == 0) {
            break;
        }
    }

    std::cout << cost << std::endl;

    return 0;
}
