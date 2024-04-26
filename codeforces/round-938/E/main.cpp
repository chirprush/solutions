#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>

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

        std::string s;
        std::cin >> s;

        int start = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') { start = i; break; }
        }

        if (start == -1) { 
            std::cout << n << std::endl;
            continue;
        }

        for (int k = n; k >= 1; k--) {
            if (k + start > n) {
                continue;
            }

            std::string q = s;
            int j = start;
            int zero = start;
            bool foundz = false;

            while (j + k <= n) {
                for (int l = j; l < j + k; l++) {
                    if (q[l] == '1' && !foundz) {
                        zero = l;
                        foundz = true;
                    }

                    q[l] = q[l] == '1' ? '0' : '1';
                }

                if (!foundz) {
                    j += k;
                } else {
                    j = zero;
                }

                foundz = false;
            }

            bool bad = false;

            for (int l = j; l < n; l++) {
                if (q[l] == '0') { 
                    bad = true;
                    break;
                }
            }

            if (!bad) {
                std::cout << k << std::endl;
                break;
            }
        }
    }

    return 0;
}
