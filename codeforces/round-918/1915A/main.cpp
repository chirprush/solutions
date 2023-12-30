#include <iostream>
#include <vector>
#include <map>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a == b) { std::cout << c << std::endl; }
        if (b == c) { std::cout << a << std::endl; }
        if (a == c) { std::cout << b << std::endl; }
    }
    return 0;
}
