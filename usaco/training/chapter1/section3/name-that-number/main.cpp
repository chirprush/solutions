/*
ID: rush0401
TASK: namenum
LANG: C++11
*/
#include <iostream>
#include <fstream>
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

const char *letters[] {
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PRS",
    "TUV",
    "WXY",
};

bool matches(std::string serial, std::string word) {
    if (serial.length() != word.length()) { return false; }

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];

        const char *valid = letters[serial[i] - '2'];

        if (c != valid[0] && c != valid[1] && c != valid[2]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    std::string serial;
    std::cin >> serial;

    bool valid = false;
    std::ifstream dictfile("dict.txt");
    
    for (int i = 0; i < 4617; i++) {
        std::string word;
        dictfile >> word;

        if (matches(serial, word)) {
            std::cout << word << std::endl;
            valid = true;
        }
    }

    if (!valid) {
        std::cout << "NONE" << std::endl;
    }

    return 0;
}
