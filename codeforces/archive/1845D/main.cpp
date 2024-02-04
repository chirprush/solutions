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
    int t;
    std::cin >> t;

    while (t--) {
        ll N;
        std::cin >> N;

        std::vector<ll> a;
        read_some(a, N);

        std::vector<ll> prefix(N + 1);
        prefix[0] = 0;

        for (int i = 0; i < N; i++) {
            prefix[i+1] = prefix[i] + a[i];
        }

        ll m = 0;

        for (int i = 0; i < N; i++) {
            if (prefix[i] > prefix[i+1]) {
                m = std::max(m, prefix[i]);
            }
        }

        std::cout << m << std::endl;
    }

    return 0;
}
