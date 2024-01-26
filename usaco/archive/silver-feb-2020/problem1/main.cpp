#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
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
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    // Solution idea:
    // 1. Compute the solution for one iteration (i.e. for K = 1) in O(MN) time
    // to get some permutation of length N
    // 2. Decompose the permutation into disjoint cycles in like O(N) time.
    // 3. Notice that the order of a cycle of length L is just L so we can take
    // K mod L and index into the cycle to find the number that it goes to.
    
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> intervals;
    std::vector<int> cows(N);

    for (int i = 0; i < N; i++) {
        cows[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;

        L--;
        R--;

        for (int i = L; i <= (L + R) / 2; i++) {
            std::swap(cows[i], cows[R + L - i]);
        }
    }

    std::vector<bool> visited(N);
    std::vector<int> searching(N);
    std::vector<int> indexing(N);
    std::vector<std::vector<int>> cycles;

    int cycle = 0;

    for (int i = 0; i < N; i++) {
        if (visited[cows[i]]) { continue; }

        int index = 0;

        std::vector<int> current;
        current.push_back(cows[i]);
        visited[cows[i]] = true;
        searching[cows[i]] = cycle; 
        indexing[cows[i]] = index;

        index++;

        int j = cows[i];

        while (!visited[cows[j]]) {
            current.push_back(cows[j]);
            searching[cows[j]] = cycle; 
            visited[cows[j]] = true;
            indexing[cows[j]] = index;
            j = cows[j];
            index++;
        }

        cycles.push_back(current);

        cycle++;
    }

    for (int i = 0; i < N; i++) {
        int c = searching[cows[i]];
        int j = indexing[cows[i]];

        std::cout << 1 + cycles[c][(j + (K - 1) % cycles[c].size()) % cycles[c].size()] << std::endl;
    }

    return 0;
}
