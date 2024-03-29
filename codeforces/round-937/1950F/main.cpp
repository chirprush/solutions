#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

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

/*
int solve(int a, int b, int c) {
    assert(a >= 0 && b >= 0 && c >= 0);

    if (c == 0 && (a > 0 || b > 0)) {
        return -1;
    } else if (c == 0 && a == 0 && b == 0) {
        return 0;
    } else if (a == 0 && c != 1) {
        return -1;
    } else if (a == 0) {
        return b;
    } else if (b == 0 && ) {
    }
}
*/

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a + 1 != c) {
            std::cerr << "bad" << std::endl;
            std::cout << -1 << std::endl;
            continue;
        }

        int d = (int)std::log2(c);
        int need = (1 << (d + 1)) - c;

        if (b == 0) {
            std::cerr << "type 0" << std::endl;
            std::cout << d << std::endl;
        } else if (b <= need) {
            std::cerr << "type 1" << std::endl;
            std::cout << (d + 1) << std::endl;
        } else {
            std::cerr << "type 2" << std::endl;
            b -= need;

            int m = (int)std::ceil((double)b / c);

            std::cout << (d + 1 + m) << std::endl;
        }
    }

    return 0;
}
