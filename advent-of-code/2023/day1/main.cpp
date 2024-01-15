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

ll solve1(std::string s) {
    ll total = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            total += 10 * (s[i] - '0');
            break;
        }
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            total += (s[i] - '0');
            break;
        }
    }

    return total;
}

ll solve2(std::string s) {
    ll total = 0;

    std::vector<std::string> digits = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            total += 10 * (s[i] - '0');
            break;
        }

        for (int j = 0; j < digits.size(); j++) {
            std::string &word = digits[j];
            if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
                total += 10 * (j + 1);
                goto outer;
            }
        }
    }
outer:

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            total += (s[i] - '0');
            break;
        }

        for (int j = 0; j < digits.size(); j++) {
            const auto &word = digits[j];
            if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
                total += j + 1;
                goto outer2;
            }
        }
    }
outer2:

    return total;
}

int main() {
    int t;
    std::cin >> t;
    ll total = 0;

    while (t--) {
        std::string s;
        std::cin >> s;

        // total += solve1(s);
        total += solve2(s);
    }

    std::cout << total << std::endl;

    return 0;
}
