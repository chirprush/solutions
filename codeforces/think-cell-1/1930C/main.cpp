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
    std::cout << v[0];
    for (int i = 1; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        // Probably wrong but
        std::map<int, int> counts;
        std::vector<int> a;
        std::vector<int> b;

        for (int i = 0; i < n; i++) {
            int j;
            std::cin >> j;
            a.push_back(i + j + 1);
        }

        while (a.size()) {
            auto it = std::max_element(a.begin(), a.end());

            b.push_back(*it);
            it = a.erase(it);

            for (; it != a.end(); it++) {
                (*it)--;
            }
        }

        std::sort(b.rbegin(), b.rend());

        print_some(b);
    }

    return 0;
}
