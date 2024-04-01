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
        int n, k;
        std::cin >> n >> k;

        if (k != 1 && k != n) {
            std::cout << -1 << std::endl;
            continue;
        }

        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                std::cout << i << " ";
            }

            std::cout << std::endl;
        } else {
            for (int i = 1; i <= n; i++) {
                std::cout << 1 << " ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}
