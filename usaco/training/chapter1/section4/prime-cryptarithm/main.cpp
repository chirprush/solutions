/*
ID: rush0401
TASK: crypt1
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <cstdio>

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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

bool valid_num(int N, const std::vector<int> &digits) {
    std::string s = std::to_string(N);

    for (int i = 0; i < s.length(); i++) {
        bool yes = false;
        for (int j = 0; j < digits.size(); j++) {
            if (s[i] - '0' == digits[j]) {
                yes = true;
                break;
            }
        }

        if (!yes) {
            return false;
        }
    }

    return true;
}

bool valid(int a, int b, int c, int d, int e, const std::vector<int> &digits) {
    int partial1 = (100 * a + 10 * b + c) * e;
    int partial2 = (100 * a + 10 * b + c) * d;

    int total = (100 * a + 10 * b + c) * (10 * d + e);

    bool p1 = partial1 >= 100 && partial1 < 1000 && valid_num(partial1, digits);
    bool p2 = partial2 >= 100 && partial2 < 1000 && valid_num(partial2, digits);
    bool t = total >= 1000 && total < 10000 && valid_num(total, digits);

    return p1 && p2 && t;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<int> digits;
    read_some(digits, N);

    int count = 0;

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    for (int e = 0; e < N; e++) {
                        if (valid(digits[a], digits[b], digits[c], digits[d], digits[e], digits)) { count++; }
                    }
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
