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
        ll n;
        std::cin >> n;

        if (n % 2 == 1) {
            std::cout << 1;
            for (int i = 1; i < n; i++) {
                std::cout << " " << 1;
            }
            std::cout << std::endl;
        } else {
            std::cout << 1 << " " << 3;
            for (int i = 0; i < n - 2; i++) {
                std::cout << " " << 2;
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
