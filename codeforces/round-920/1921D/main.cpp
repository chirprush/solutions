#include <iostream>
#include <vector>
#include <string>
#include <map>
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
        ll n, m;
        std::vector<ll> a, b;

        std::cin >> n >> m;

        read_some(a, n);
        read_some(b, m);

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int left = 0;
        int right = m - 1;

        ll diff = 0;

        // It's likely a greedy solution doesn't work because I've
        // also tried iterating down the ends and taking the max differences
        // for both elements so hmmmm
        for (int i = 0; i < (n / 2); i++) {
            int j1 = i;
            int j2 = n - 1 - i;

            diff += std::abs(a[j1] - b[right]) + std::abs(a[j2] - b[left]);

            left++;
            right--;
        }

        if (n % 2 == 1) {
            int j = n / 2;

            diff += std::max(std::abs(a[j] - b[left]), std::abs(a[j] - b[right]));
        }

        std::cout << diff << std::endl;
    }
    return 0;
}
