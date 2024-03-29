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
        int n;
        std::cin >> n;
        std::vector<int> a;
        std::set<int> values;
        read_some(a, n);

        if (n == 1) {
            std::cout << 1 << std::endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            values.insert(a[i]);
        }

        std::sort(a.begin(), a.end());

        ll max = a[a.size() - 1];
        ll x = 0;

        for (int i = 0; i < n; i++) {
            x = std::__gcd(x, max - a[i]);
        }

        ll cost = 0;

        for (int i = 0; i < n; i++) {
            cost += (max - a[i]) / x;
        }

        ll last = max;

        while (values.find(last) != values.end()) {
            last -= x;
        }

        cost += (max - last) / x;

        std::cout << cost << std::endl;
    }

    return 0;
}
