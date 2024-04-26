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
        ll n, k;
        std::cin >> n >> k;

        std::vector<ll> a;
        read_some(a, n);

        ll count = 0;
        ll left = 0;
        ll right = n - 1;

        while (k > 0) {
            if (left > right) { break; }

            if (left == right) {
                ll remove = std::min(k, a[left]);

                a[left] -= remove;

                if (!a[left]) { count++; }

                break;
            }

            ll remove = std::min(k, 2 * std::min(a[left], a[right]));

            a[left] -= (remove + 1) / 2;
            a[right] -= remove / 2;

            if (!a[left]) { left++; count++; }
            if (!a[right]) { right--; count++; }

            k -= remove;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
