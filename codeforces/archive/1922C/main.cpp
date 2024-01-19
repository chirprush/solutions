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
    std::cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<ll> a;
        read_some(a, n);

        std::vector<ll> forward(n);
        std::vector<ll> backward(n);
        forward[0] = 0;
        forward[1] = 1;
        backward[n - 1] = 0;
        backward[n - 2] = 1;

        for (int i = 2; i < n; i++) {
            ll left = std::abs(a[i - 2] - a[i - 1]);
            ll right = std::abs(a[i] - a[i - 1]);
            forward[i] = forward[i - 1] + (right < left ? 1 : right);
        }

        for (int i = n - 3; i >= 0; i--) {
            ll left = std::abs(a[i] - a[i+1]);
            ll right = std::abs(a[i+1] - a[i+2]);
            backward[i] = backward[i + 1] + (left < right ? 1 : left);
        }

        int m;
        std::cin >> m;

        for (int i = 0; i < m; i++) {
            int x, y;
            std::cin >> x >> y;

            if (y > x) {
                std::cout << forward[y - 1] - forward[x - 1] << std::endl;
            } else {
                std::cout << backward[y - 1] - backward[x - 1] << std::endl;
            }
        }
    }

    return 0;
}
