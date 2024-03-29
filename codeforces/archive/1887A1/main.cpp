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

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a, b;

        read_some(a, n - 1);
        read_some(b, n);

        a.push_back(1);

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
