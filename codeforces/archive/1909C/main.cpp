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

    for (int i = 0; i < n; i++) {
        diffs.push_back(r[i] - l[i]);
    }

    std::sort(diffs.rbegin(), diffs.rend());

    int weight = 0;

    for (int i = 0; i < n; i++) {
        weight += diffs[i] * c[i];
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
