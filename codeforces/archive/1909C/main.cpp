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

template<typename T>
void print_some(std::vector<T> &v) {
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++) {
        std::cout << " " << v[i];
    }

    std::cout << std::endl;
}

int solve(int n, std::vector<int> &l, std::vector<int> &r, std::vector<int> &c) {
    // Hopefully a greedy solution works
    // Uhhh I don't think it does sadly
    std::vector<int> diffs;

    for (int i = n - 1; i >= 0; i--) {
        int j = n - 1;
        while ((l[j] >= r[i] || l[j] <= 0) && j >= 0) { j--; }
        diffs.push_back(r[i] - l[j]);
        l[j] = -1;
    }

    std::sort(diffs.begin(), diffs.end());

    int weight = 0;

    for (int i = 0; i < n; i++) {
        weight += diffs[i] * c[n - 1 - i];
    }

    return weight;
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::vector<int> l;
        std::vector<int> r;
        std::vector<int> c;

        std::cin >> n;

        read_some(l, n);
        read_some(r, n);
        read_some(c, n);

        std::sort(l.begin(), l.end());
        std::sort(r.begin(), r.end());
        std::sort(c.begin(), c.end());

        std::cout << solve(n, l, r, c) << std::endl;
    }

    return 0;
}
