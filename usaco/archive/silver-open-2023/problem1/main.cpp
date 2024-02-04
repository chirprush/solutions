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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> a;
    read_some(a, N);

    std::vector<ll> rindex(N);
    std::vector<ll> index(N);
    for (int i = 0; i < N; i++) {
        rindex[i] = i;
    }

    std::sort(rindex.begin(), rindex.end(), [&a](ll i, ll j) { return a[i] < a[j]; });

    for (int i = 0; i < N; i++) {
        index[rindex[i]] = i;
    }

    std::sort(a.begin(), a.end());

    std::vector<ll> prefix(N+1);
    prefix[0] = 0;

    ll T = 0;

    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + a[i];
        T += (i + 1) * a[i];
    }

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++) {
        ll i, j;
        std::cin >> i >> j;
        i--;
        i = index[i];

        int k = std::lower_bound(a.begin(), a.end(), j) - a.begin();
        k -= (k > i ? 1 : 0);
        
        ll off = (k > i ? 1 : 0);
        std::cout << T - (i + 1) * a[i] + (k + 1) * j + (prefix[i + off] - prefix[k + off]) << std::endl;
    }

    return 0;
}
