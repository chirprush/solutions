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

    /*
    std::cout << "Parity:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << parity[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    */

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            /*
            std::cout << "Step (" << i << ", " << j << "):" << std::endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    std::cout << dp[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            */

            if (parity[i][j] == dp[i][j]) { continue; }

            dp[i][j] = 1 - dp[i][j];
            count++;

            for (int k = j + 1; k < N; k++) {
                dp[i][k] = (dp[i][k] + /* dp[i][j] * */ dp[j][k]) % 2;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
