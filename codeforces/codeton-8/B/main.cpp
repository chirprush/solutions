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
        read_some(a, n);

        std::set<int> left;
        
        for (int i = 0; i <= n; i++) {
            left.insert(i);
        }

        std::vector<int> p;

        for (int i = 0; i < n; i++) {
            auto it = left.begin();
            int l0 = *it;
            it++;
            int l1 = *it;

            if (a[i] == l1 - l0) {
                left.erase(l0);
                p.push_back(l0);
            } else {
                left.erase(l0 - a[i]);
                p.push_back(l0 - a[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            std::cout << p[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
