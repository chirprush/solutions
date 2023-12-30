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

char solve(char a, char b) {
    if (a == 'A' && b == 'B') { return 'C'; }
    else if (a == 'A' && b == 'C') { return 'B'; }
    else if (a == 'B' && b == 'C') { return 'A'; }
    if (b == 'A' && a == 'B') { return 'C'; }
    else if (b == 'A' && a == 'C') { return 'B'; }
    else if (b == 'B' && a == 'C') { return 'A'; }

    return 0;
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        std::string a;
        std::string b;
        std::string c;

        std::cin >> a >> b >> c;

        if (a[0] == '?') { std::cout << solve(b[0], c[0]) << std::endl; }
        else if (a[1] == '?') { std::cout << solve(b[1], c[1]) << std::endl; }
        else if (a[2] == '?') { std::cout << solve(b[2], c[2]) << std::endl; }
        else if (b[0] == '?') { std::cout << solve(a[0], c[0]) << std::endl; }
        else if (b[1] == '?') { std::cout << solve(a[1], c[1]) << std::endl; }
        else if (b[2] == '?') { std::cout << solve(a[2], c[2]) << std::endl; }
        else if (c[0] == '?') { std::cout << solve(a[0], b[0]) << std::endl; }
        else if (c[1] == '?') { std::cout << solve(a[1], b[1]) << std::endl; }
        else if (c[2] == '?') { std::cout << solve(a[2], b[2]) << std::endl; }
    }
    return 0;
}
