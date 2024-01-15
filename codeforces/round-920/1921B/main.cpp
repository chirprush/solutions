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
        std::string s1;
        std::string s2;

        std::cin >> n;
        std::cin >> s1;
        std::cin >> s2;

        int total1 = 0;
        int total2 = 0;

        for (int i = 0; i < n; i++) {
            if (s1[i] == '1' && s2[i] == '0') {
                total1++;
            } else if (s1[i] == '0' && s2[i] == '1') {
                total2++;
            }
        }

        std::cout << std::min(total1, total2) + std::abs(total2 - total1) << std::endl;
    }
    return 0;
}
