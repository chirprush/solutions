/*
ID: rush0401
TASK: palsquare
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

const char *digits = "0123456789ABCDEFGHIJ";

std::string based(int S, int B) {
    std::string s = "";

    while (S > 0) {
        s = digits[S % B] + s;
        S /= B;
    }

    return s;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int B;
    std::cin >> B;

    for (int N = 1; N <= 300; N++) {
        int S = N * N;

        std::string s = based(S, B);
        std::string reversed(s);
        std::reverse(reversed.begin(), reversed.end());

        if (s == reversed) {
            std::cout << based(N, B) << " " << s << std::endl;
        }
    }

    return 0;
}
