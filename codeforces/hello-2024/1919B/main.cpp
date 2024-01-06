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

int solve(int n, std::vector<int> &v) {
    // This looks highly sus
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    
    return std::abs(sum);
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::vector<int> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = (s[i] == '+' ? 1 : -1);
        }

        std::cout << solve(n, v) << std::endl;
    }

    return 0;
}
