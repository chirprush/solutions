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

        std::vector<int> a;
        read_some(a, n);

        std::string s;
        std::cin >> s;

        int start = 0;

        std::vector<ll> prods;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'L') {
                start++;
            }
        }

        int left = start;
        int right = start;

        ll prod = a[start] % m;
        prods.push_back(prod);

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'R') {
                right++;
                prod = (prod * a[right]) % m;
            } else {
                left--;
                prod = (prod * a[left]) % m;
            }

            prods.push_back(prod);
        }

        for (int i = n - 1; i >= 0; i--) {
            std::cout << prods[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
