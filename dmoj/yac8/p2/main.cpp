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
    int N, X;
    std::cin >> N >> X;

    std::vector<int> a;
    read_some(a, N);

    std::set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(a[i]);
    }

    if (X == 0) {
        std::cout << (a.size() == s.size() ? "NO" : "YES") << std::endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (s.count(X ^ a[i])) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}
