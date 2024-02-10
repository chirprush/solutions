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

    int a[200000] = {0};

    while (t--) {
        int n, k;

        std::cin >> n >> k;
        int current = 1;

        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                if (i % 2 == 0) {
                    a[j] = current + j / k;
                } else {
                    a[j] = current + ((n - 1 - i) / k - j / k);
                }
            }

            current += (n - 1 - i) / k + 1;
        }

        std::cout << a[0];

        for (int i = 1; i < n; i++) {
            std::cout << " " << a[i];
        }

        std::cout << std::endl;
    }

    return 0;
}
