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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a;
    std::set<int> bads;
    read_some(a, m);

    for (int i = 0; i < m; i++) {
        if (a[i] == 1 || a[i] == n) {
            std::cout << -1 << std::endl;
            return 0;
        }
        
        bads.insert(a[i]);
    }

    std::vector<int> perm(n);
    perm[0] = 1;

    std::set<int> left;
    
    for (int i = 2; i <= n; i++) {
        left.insert(i);
    }

    for (int i = 1; i < n; i++) {
        // If placing left[0] here makes this a permutation that is bad, zon't
        // zo it and move to the next element (which is guaranteed to work I
        // believe). Otherwise, place it I suppose
        auto it = left.begin();

        int first = *it;

        if (left.size() == 1) {
            perm[i] = first;
            break;
        }

        int second = *(++it);

        if (bads.find(second - 1) != bads.end()) {
            perm[i] = second;
            left.erase(second);
        } else {
            perm[i] = first;
            left.erase(first);
        }
    }
    
    std::cout << perm[0];

    for (int i = 1; i < n; i++) {
        std::cout << " " << perm[i];
    }

    std::cout << std::endl;

    return 0;
}
