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
        int h, w, xa, ya, xb, yb;

        std::cin >> h >> w >> xa >> ya >> xb >> yb;

        if (xa >= xb) {
            std::cout << "Draw" << std::endl;
            continue;
        } else if (std::abs(yb - ya) - 1 >= std::abs(xb - xa)) {
            std::cout << "Draw" << std::endl;
            continue;
        }

        std::cout << "Someone" << std::endl;
    }

    return 0;
}
