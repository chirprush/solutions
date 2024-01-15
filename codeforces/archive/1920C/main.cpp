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
        int n;
        std::cin >> n;

        std::vector<int> a;
        read_some(a, n);

        int points = 1;

        for (int k = 1; k < n; k++) {
            if (n % k == 0) {
                int gcd = 0;

                for (int i = 0; i < n / k; i++) {
                    for (int j = 0; j < k; j++) {
                        gcd = std::__gcd(gcd, std::abs(a[i * k + j] - a[j]));

                        if (gcd == 1) {
                            goto skip;
                        }
                    }
                }

                points++;
            }
skip:;
        }

        std::cout << points << std::endl;;
    }

    return 0;
}
