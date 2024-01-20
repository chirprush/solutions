#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <cstdio>

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
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> p;
    read_some(p, n);

    int deranged = -1;

    for (int i = n - 1; i >= 1; i--) {
        if (p[i] < p[i - 1]) {
            deranged = i;
            break;
        }
    }

    if (deranged == -1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << deranged << std::endl;
    }

    return 0;
}
