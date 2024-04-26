#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>

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
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> a, b;

        read_some(a, n);
        read_some(b, m);

        std::map<int, int> acounts;
        std::map<int, int> bcounts;

        for (int i = 0; i < m; i++) {
            bcounts[b[i]]++;
        }

        for (int i = 0; i < m; i++) {
            acounts[a[i]]++;
        }

        int matches = 0;
        int goods = 0;

        for (auto it = acounts.begin(); it != acounts.end(); it++) {
            std::pair<int, int> el = *it;

            matches += std::min(acounts[el.first], bcounts[el.first]);
        }

        if (matches >= k) {
            goods++;
        }

        for (int i = m; i < n; i++) {
            if (acounts[a[i-m]] <= bcounts[a[i-m]]) {
                matches--;
            }

            acounts[a[i-m]]--;

            if (acounts[a[i]] < bcounts[a[i]]) {
                matches++;
            }

            acounts[a[i]]++;

            if (matches >= k) { goods++; }
        }

        std::cout << goods << std::endl;
    }

    return 0;
}
