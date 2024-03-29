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
        int n;
        std::cin >> n;

        std::vector<int> a, b;
        read_some(a, n);
        read_some(b, n);

        std::vector<std::pair<int, int>> c;

        for (int i = 0; i < n; i++) {
            c.push_back(std::make_pair(a[i] - b[i], i + 1));
        }

        std::sort(c.begin(), c.end(), [](std::pair<int, int> &l, std::pair<int, int> &r) { return l.first < r.first; });

        std::vector<int> values;
        for (int i = 0; i < n; i++) {
            if (c[i].first == c[n - 1].first) {
                values.push_back(c[i].second);
            }
        }

        std::sort(values.begin(), values.end());

        std::cout << values.size() << std::endl;

        for (int i = 0; i < values.size(); i++) {
            std::cout << values[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
