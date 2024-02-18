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
    int N, D;
    std::cin >> N >> D;

    std::vector<int> a;
    read_some(a, N);

    int b = 1, l = 1;
    int current = 1;
    int prev = a[0];

    // 9 3 3 3 9
    //   b     b -> 3
    //   1 2 3
    for (int i = 1; i < N; i++) {
        if (std::abs(a[i] - prev) <= D) {
            current++;
        } else {
            b++;
            l = std::max(l, current);
            current = 1;
        }

        prev = a[i];
    }

    l = std::max(l, current);

    std::cout << b << std::endl << l << std::endl;

    return 0;
}
