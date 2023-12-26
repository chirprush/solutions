#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void read_some(std::vector<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

int solve(int n, int k, int d, std::vector<int> &a, std::vector<int> &b) {
    int initial = 0;
    int after = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) { initial++; }
        if (a[i] + (i <= b[0] ? 1 : 0) == i + 1) { after++; }
    }

    if (d == 1) { return initial; }

    if (initial >= after) {
        return initial + (d - 1) / 2;
    } else {
        return after + (d - 2) / 2;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        int k;
        int d;

        std::cin >> n >> k >> d;

        std::vector<int> a;
        read_some(a, n);

        std::vector<int> b;
        read_some(b, k);

        std::cout << solve(n, k, d, a, b) << std::endl;
    }
    return 0;
}
