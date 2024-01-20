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

    std::vector<ll> a, b;
    read_some(a, n);
    read_some(b, n);

    for (ll i = 0; i < n; i++) {
        a[i] *= (i + 1) * (n - i);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.rbegin(), b.rend());

    ll answer = 0;

    for (int i = 0; i < n; i++) {
        answer += a[i] * b[i];
    }

    std::cout << answer << std::endl;

    return 0;
}
