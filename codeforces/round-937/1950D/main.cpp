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

        int decimals[] = {
            10,
            11,
            100,
            101,
            110,
            111,
            1000,
            1001,
            1010,
            1011,
            1100,
            1101,
            1110,
            1111,
            10000,
            10001,
            10010,
            10011,
            10100,
            10101,
            10110,
            10111,
            11000,
            11001,
            11010,
            11011,
            11100,
            11101,
            11110,
            11111,
            100000
        };

        for (int i = 30; i >= 0; i--) {
            while (n % decimals[i] == 0) {
                n /= decimals[i];
            }
        }

        if (n == 1) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
