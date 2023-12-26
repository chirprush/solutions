#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

template<typename T>
void read_some(std::vector<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

int solve(std::string s, int n) {
    // If all distinct then n(n+1)/2
    // but otherwise I have to really think about it
    // I can't really see a good mathematical solution so can we just brute
    // force?
    
    std::unordered_set<std::string> S;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            std::string a = s[i] + s.substr(i + j + 1, n);
            S.insert(a);
        }
    }

    return S.size();
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::cout << solve(s, n) << std::endl;
    }
    return 0;
}
