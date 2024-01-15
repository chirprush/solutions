#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;

        std::vector<int> a;
        read_some(a, n);

        std::sort(a.begin(), a.end());

        int S = 0;

        for (int i = 0; i < n; i++) {
            if (i < n - x) {
                S += a[i];
            } else {
                S -= a[i];
            }
        }

        if (x == 0) {
            std::cout << S << std::endl;
            continue;
        }

        int max = std::numeric_limits<int>::min();

        // 1 2 3 4 5 6
        // 1 2 3 -4 -5 -6
        // 1 2 3 -4 -5 0
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                max = std::max(max, S);
                continue;
            }

            S += a[n - j];
            if (n - j - x >= 0) {
                S -= 2 * a[n - j - x];
            }

            max = std::max(max, S);
        }

        std::cout << max << std::endl;
    }
    return 0;
}
