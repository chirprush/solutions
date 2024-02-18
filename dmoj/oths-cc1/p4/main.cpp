#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

template<typename T>
void read_some(std::vector<T> &v, ll N) {
    for (ll i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

template<typename T>
void print_some(std::vector<T> &v) {
    std::cout << "[";

    for (ll i = 0; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << " ]" << std::endl;
}

int main() {
    ll N, S, T;
    std::cin >> N >> S >> T;

    std::vector<ll> a;
    read_some(a, N);

    std::vector<ll> prefix(N+1);
    std::vector<ll> suffix(N+1);

    prefix[0] = 0;
    suffix[N] = 0;
    
    for (ll i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + a[i];
        suffix[i + 1] = suffix[i] + a[N - 1 - i];
    }

    if (S * T >= N) {
        std::cout << prefix[N] << std::endl;
        return 0;
    }

    ll score = 0;
    for (ll i = 0; i <= T; i++) {
        score = std::max(score, prefix[i * S] + suffix[(T - i) * S]);
    }

    std::cout << score << std::endl;

    return 0;
}
