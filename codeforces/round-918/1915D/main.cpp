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

int get_type(char c) {
    switch (c) {
    case 'a': return 0;
    case 'e': return 0;
    case 'b': return 1;
    case 'c': return 1;
    case 'd': return 1;
    }
    return -1;
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::string s;
        std::cin >> n;
        std::cin >> s;

        std::string output = "";
        std::string dot = ".";

        int i = n - 1;
        while (i >= 0) {
            if (get_type(s[i]) == 0) {
                output = dot + s[i - 1] + s[i] + output;
                i -= 2;
            } else if (get_type(s[i]) == 1) {
                output = dot + s[i - 2] + s[i - 1] + s[i] + output;
                i -= 3;
            }
        }

        std::cout << output.substr(1) << std::endl;
    }
    return 0;
}
