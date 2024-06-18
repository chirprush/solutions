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
        ll n, m;
        std::cin >> n >> m;

        std::vector<ll> rows(n);
        std::vector<ll> cols(m);

        for (ll i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;

            for (ll j = 0; j < m; j++) {
                rows[i] += s[j] == '#';
                cols[j] += s[j] == '#';
            }
        }

        ll r = 0;
        ll c = 0;

        for (ll i = 0; i < n; i++) {
            if (rows[i] > rows[r]) {
                r = i;
            }
        }

        for (ll i = 0; i < m; i++) {
            if (cols[i] > cols[c]) {
                c = i;
            }
        }
        
        std::cout << (r + 1) << " " << (c + 1) << std::endl;
    }

    return 0;
}
