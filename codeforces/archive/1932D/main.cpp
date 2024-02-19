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

bool fill(std::string current, std::string suite, std::vector<int> &cards, std::vector<int> &special, std::vector<std::string> &outputs) {
    while (cards.size()) {
        if (cards.size() >= 2) {
            int a, b;
            a = cards.pop();
            b = cards.pop();

            outputs.push_back(std::to_string(b) + current + " " + std::to_string(a) + current);
        } else {
            if (special.size() == 0) { return false; }
            int a = special.pop();
            int b = cards.pop();

            outputs.push_back(std::to_string(b) + current + " " + std::to_string(a) + suite);
        }
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        char suite;
        std::cin >> suite;

        std::vector<int> C;
        std::vector<int> S;
        std::vector<int> D;
        std::vector<int> H;

        std::vector<int> special;

        std::vector<std::string> outputs;

        for (int i = 0; i < 2 * n; i++) {
            std::string s;
            std::cin >> s;

            switch (s[1]) {
            case 'C':
                C.push_back(s[0] - '0');
                break;
            case 'S':
                S.push_back(s[0] - '0');
                break;
            case 'D':
                D.push_back(s[0] - '0');
                break;
            case 'H':
                H.push_back(s[0] - '0');
                break;
            }
        }

        std::sort(C.begin(), C.end());
        std::sort(S.begin(), S.end());
        std::sort(D.begin(), D.end());
        std::sort(H.begin(), H.end());

        bool good = true;

        // I don't want to write all this out but you probably get the idea

        if (suite != 'C') {
            good = good && fill("C", "" + suite, C, );
        }

        if (!good) { goto imp; }

        if (suite != 'S') {
        }

        if (suite != 'D') {
        }

        if (suite != 'H') {
        }

        continue;
imp:
        std::cout << "IMPOSSIBLE" << std::endl;
    }

    return 0;
}
