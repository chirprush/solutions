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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a;
    std::vector<ll> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    read_some(a, n);
    std::sort(a.begin(), a.end());

    ll m = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0) {
                dp[i] = std::max(dp[i], 1 + dp[j]);
                m = std::max(m, dp[i]);
            }
        }
    }

    std::cout << m << std::endl;

    return 0;
}
