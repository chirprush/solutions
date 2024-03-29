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
    ll n, A, B, d;
    std::cin >> n >> A >> B >> d;

    std::vector<ll> a;
    read_some(a, n);

    for (int i = 0; i < n; i++) {
        if (a[i] >= A - d && a[i] <= B + d) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
