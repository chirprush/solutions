/*
ID: rush0401
TASK: dualpal
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

const char *digits = "0123456789";

std::string based(int S, int B) {
    std::string s = "";

    while (S > 0) {
        s = digits[S % B] + s;
        S /= B;
    }

    return s;
}
 
bool palindromic(int S, int b) {
    std::string s = based(S, b);
    int l = s.length();

    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int N, S;
    std::cin >> N >> S;
    S++;

    while (N > 0) {
        int count = 0;

        for (int b = 2; b <= 10; b++) {
            if (palindromic(S, b)) {
                count++;

                if (count >= 2) {
                    break;
                }
            }
        }

        if (count >= 2) {
            std::cout << S << std::endl;
            N--;
        }

        S++;
    }

    return 0;
}
