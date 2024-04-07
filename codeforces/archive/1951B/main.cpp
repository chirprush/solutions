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

int count(std::vector<int> &a, int k) {
    int c = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i == k) { continue; }
        if (a[i] > a[k]) { break; }

        if (i >= k - 1) { c++; }
    }

    return c;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;
        
        k--;

        std::vector<int> a;
        read_some(a, n);

        int c = count(a, k);

        std::swap(a[0], a[k]);
        c = std::max(c, count(a, 0));

        std::swap(a[0], a[k]);

        int next = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > a[k]) {
                next = i;
                break;
            }
        }

        std::swap(a[k], a[next]);

        c = std::max(c, count(a, next));

        std::cout << c << std::endl;
    }

    return 0;
}
