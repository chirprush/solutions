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

ll powmod(ll a, ll b, ll m){
    ll ans = 1;
    while (b) {
        if (b % 2 == 1 ) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

constexpr ll M = 998244353;

ll facts[1001] = {0};
ll invfacts[1001] = {0};

ll comb(ll n, ll k) {
    return (facts[n] * invfacts[k] % M) * invfacts[n - k] % M;
}

ll dp[1001][26] = {0};


int main() {
    ll K;
    std::cin >> K;

    std::vector<ll> C;
    read_some(C, 26);

    facts[0] = 1;

    for (ll i = 1; i <= 1000; i++) {
        facts[i] = i * facts[i-1];
        facts[i] %= M;
    }

    invfacts[1000] = powmod(facts[1000], M - 2, M) % M;

    for (ll i = 999; i >= 0; i--) {
        invfacts[i] = (i + 1) * invfacts[i + 1];
        invfacts[i] %= M;
    }

    for (ll k = 0; k <= C[0]; k++) {
        dp[k][0] = 1;
    }

    for (ll i = 1; i < 26; i++) {
        for (ll k = 0; k <= K; k++) {
            dp[k][i] = 0;

            for (ll j = 0; j <= std::min(k, C[i]); j++) {
                dp[k][i] += comb(k, j) * dp[k - j][i - 1] % M;
                dp[k][i] %= M;
            }
        }
    }

    ll count = 0;

    for (ll k = 1; k <= K; k++) {
        count += dp[k][25];
        count %= M;
    }

    std::cout << count << std::endl;

    return 0;
}
