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

    std::vector<ll> a;
    read_some(a, N);

    ll count = 0;
    ll net = 0;
    ll mult = 0;

    for (int i = 1; i <= N; i++) {
        ll current = a[i - 1] + net - (N - i) * mult;
        count += std::abs(current);
        net += -current * (N + 1 - i);
        mult += -current;
    }

    std::cout << count << std::endl;
    
    return 0;
}
