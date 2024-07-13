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
    constexpr ll V = 2006005;
    constexpr ll M = 20092010;
    
    std::vector<ll> a(V + 1);

    for (ll i = 0; i <= 1999; i++) {
        a[i] = 1;
    }

    for (ll i = 2000; i <= V; i++) {
        a[i] = (a[i - 2000] + a[i - 1999]) % M;
    }

    std::cout << a[V] << std::endl;

    return 0;
}
