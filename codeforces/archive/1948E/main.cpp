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

void sequence(std::vector<int> &a, int m, int p) {
    if (m == 1) {
        a.push_back(p + 1);
        return;
    }

    int r = 0;
    if (m % 2 == 0) {
        r = m / 2;
    } else {
        r = m / 2 + 1;
    }

    for (int i = r; i >= 1; i--) {
        a.push_back(i + p);
    }

    for (int i = m; i >= m + 1 + (m % 2) - r; i--) {
        a.push_back(i + p);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a;

        int m = std::min(n, k);

        for (int i = 0; i < n / m; i++) {
            sequence(a, m, i * m);
        }

        if (n % m != 0) {
            sequence(a, n % m, (n / m) * m);
        }

        for (int i = 0; i < a.size(); i++) {
            std::cout << a[i] << " ";
        }

        std::cout << std::endl;

        std::cout << (int)std::ceil((double) n / m) << std::endl;

        for (int i = 0; i < n / m; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << (i + 1) << " ";
            }
        }

        if (n % m != 0) {
            for (int i = 0; i < n % m; i++) {
                std::cout << (n / m + 1) << " ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
