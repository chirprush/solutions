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
        ll k, x, a;
        std::cin >> k >> x >> a;

        // Suppose it takes i losses to get to a win, where we bet b_j
        // for games 1 <= j <= i. Suppose we bet y for this game and win.
        // We must then have that
        //   a >(=?) sum b_j + y
        //   y * (k-1) - sum b_j > 0
        //   
        // Ex. (k: 2, x: 3, a: 15)
        // b_1 = 1
        // b_2 = 2
        // b_3 = 4
        // b_{x + 1} = maximum = a - sum b_j -> k * (a - sum b_j)
        // which should be more than a

        ll b = 0;
        for (int i = 0; i < x; i++) {
            ll lower = b / (k - 1) + 1;
            ll upper = a - b - 1;

            if (lower <= upper) {
                b += lower;
            } else {
                std::cout << "NO" << std::endl;
                goto fail;
            }
        }

        if (k * (a - b) > a) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

fail:;
    }

    return 0;
}
