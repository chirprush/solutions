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

        std::vector<int> blocks;
        std::vector<int> indices;
        int value = a[0];
        int current = 0;
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == value) {
                current++;
            } else {
                blocks.push_back(current);
                indices.push_back(index);
                current = 1;
                index = i;
                value = a[i];
            }
        }

        blocks.push_back(current);
        indices.push_back(index);

        int q;
        std::cin >> q;

        while (q--) {
            int l, r;
            std::cin >> l >> r;
            l--;
            r--;

            int i = std::lower_bound(indices.begin(), indices.end(), l) - indices.begin();

            if (indices[i] > l) {
                i--;
            }

            if (i >= indices.size() - 1) {
                std::cout << -1 << " " << -1 << std::endl;
            } else if (indices[i+1] <= r) {
                std::cout << (l + 1) << " " << (indices[i+1] + 1) << std::endl;
            } else {
                std::cout << -1 << " " << -1 << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
