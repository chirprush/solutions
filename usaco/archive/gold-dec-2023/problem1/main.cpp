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

    int dp[751][751] = {0};
    int parity[751][751] = {0};

    ll count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            char c;
            std::cin >> c;

            parity[i][j] = c - '0';
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - i; j < N; j++) {
            if (parity[i][j] == dp[i][j]) { continue; }

            dp[i][j] = 1 - dp[i][j];
            count++;

            // Get all new paths in dp
            
        }
    }

    return 0;
}
