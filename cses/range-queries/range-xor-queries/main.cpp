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
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a;

    read_some(a, n);
    std::vector<int> prefix(n+1);

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] ^ a[i-1];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;

        std::cout << (prefix[b] ^ prefix[a-1]) << std::endl;
    }

    return 0;
}
