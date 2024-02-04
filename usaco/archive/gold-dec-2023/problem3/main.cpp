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

    std::vector<ll> x;
    read_some(x, N);

    std::sort(x.begin(), x.end());

    std::vector<ll> prefix(N + 1);
    prefix[0] = 0;

    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + x[i];
    }

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++) {
        int a, b;
        std::cin >> a >> b;

        int k = b * x.size() / (a + b);

        std::cout << a * (k * x[k] - prefix[k]) + b * (prefix[N] - prefix[k+1] - (x.size() - 1 - k) * x[k]) << std::endl;
    }

    return 0;
}
