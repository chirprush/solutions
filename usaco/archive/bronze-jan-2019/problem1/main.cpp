#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> shells, scores;

    shells.push_back(0);
    shells.push_back(1);
    shells.push_back(2);

    scores.push_back(0);
    scores.push_back(0);
    scores.push_back(0);
    
    for (int _ = 0; _ < N; _++) {
        int a, b, g;
        std::cin >> a >> b >> g;
        
        // Swap
        int tmp = shells[a - 1];
        shells[a - 1] = shells[b - 1];
        shells[b - 1] = tmp;

        scores[shells[g - 1]]++;
    }

    std::cout << *std::max_element(scores.begin(), scores.end()) << std::endl;
    return 0;
}
