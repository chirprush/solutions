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

        std::set<int> losing;
        std::set<int> winning;

        for (int i = 0; i < n; i++) {
            if (losing.size() == 0 || *losing.begin() > a[i] || (winning.size() >0 && *winning.begin() < a[i])) {
                losing.insert(a[i]);
            } else {
                winning.insert(a[i]);
            }
        }

        std::cout << winning.size() << std::endl;
    }

    return 0;
}
