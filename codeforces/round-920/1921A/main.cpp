#include <iostream>
#include <vector>
#include <string>
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

    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;

        std::cin >> x1 >> y1;
        std::cin >> x2 >> y2;
        std::cin >> x3 >> y3;
        std::cin >> x4 >> y4;

        ll length = std::max(x1, std::max(x2, std::max(x3, x4))) - std::min(x1, std::min(x2, std::min(x3, x4)));

        std::cout << length * length << std::endl;
    }
    return 0;
}
