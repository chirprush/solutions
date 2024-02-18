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
        int N;
        std::cin >> N;

        std::vector<int> a;
        read_some(a, N);

        std::set<int> h;

        for (int i = 0; i < N - 1; i++) {
            if (a[i] == a[i+1]) {
                h.insert(a[i]);
            } else if (i < N - 2 && a[i] == a[i+2]) {
                h.insert(a[i]);
            }
        }

        if (h.size()) {
            auto it = h.begin();
            std::cout << *it;
            it++;
            for (; it != h.end(); it++) {
                std::cout << " " << *it;
            }
            std::cout << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}
