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
        int x, n;
        std::cin >> x >> n;
 
        int max = 0;
        for (int i = std::min((int) std::ceil(std::sqrt(x)), x / n); i >= 1; i--) {
            if (x % i == 0) {
                max = std::max(max, i);
            }
            if (x % (x / i) == 0 && x / i <= x / n) {
                max = std::max(max, x / i);
            }
        }

        std::cout << max << std::endl;
    }

    return 0;
}
