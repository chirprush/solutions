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

        std::vector<ll> a;
        read_some(a, n);

        std::vector<ll> prefix(n);
        std::set<int> indices;

        prefix[n - 1] = a[n - 1];

        indices.insert(0);
        if (prefix[n - 1] > 0) {
            indices.insert(n - 1);
        }

        for (int i = n - 2; i >= 0; i--) {
            prefix[i] = prefix[i+1] + a[i];

            if (prefix[i] > 0) {
                indices.insert(i);
            }
        }

        ll sum = 0;

        for (std::set<int>::iterator it = indices.begin(); it != indices.end(); it++) {
            sum += prefix[*it];
        }

        std::cout << sum << std::endl;
    }

    return 0;
}
