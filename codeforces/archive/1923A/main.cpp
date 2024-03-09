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
        int n;
        std::cin >> n;

        std::vector<int> a;
        read_some(a, n);

        int start = 0;
        int end = n - 1;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) { start = i; break; }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 1) { end = i; break; }
        }

        int count = 0;

        for (int i = start; i <= end; i++) {
            if (a[i] == 0) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
