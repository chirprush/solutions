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
    int n, k;
    std::cin >> n >> k;

    ll dp[1002][1002] = {0};
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;

    const ll M = 1000000000 + 7;

    for (int i = 3; i <= n; i++) {
        dp[i][0] = 1;

        for (int j = 0; j <= 999 /* std::min(i * (i - 1) / 2, 999) */; j++) {
            ll a = dp[i][j];
            ll b = (j + 1 <= 1000 ? dp[i-1][j+1] : 0);
            ll c = (j - i + 1 >= 0 ? dp[i-1][j - i + 1] : 0);
            dp[i][j + 1] = (a + b + M - c) % M;
        }
    }

    std::cout << dp[n][k] << std::endl;

    return 0;
}
