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
    int n;
    std::cin >> n;

    std::vector<std::string> s;
    std::vector<std::string> rev(n);

    read_some(s, n);

    for (int i = 0; i < n; i++) {
        rev[i] = s[i];
        std::reverse(rev[i].begin(), rev[i].end());
    }

    std::sort(rev.begin(), rev.end());

    ll length = 0;

    print_some(s);
    print_some(rev);

    for (int i = 0; i < n; i++) {
        std::cout << "it: " << i << std::endl;
        length += s[i].size() * 2 * n;

        auto start = std::lower_bound(rev.begin(), rev.end(), s[i]);
        auto end = std::upper_bound(rev.begin(), rev.end(), s[i]);

        std::cout << "Search: " << s[i] << " at " << (ll)(start - rev.begin()) << " and " << (ll)(end - rev.begin()) << std::endl;
        ll diff = (ll)(end - start);
        std::cout << "Diff: " << diff << std::endl;

        length -= s[i].size() * diff;
    }

    std::cout << length << std::endl;

    return 0;
}
