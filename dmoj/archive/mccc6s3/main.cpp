#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <limits>
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

typedef std::pair<ll, ll> pii;

struct pair_ordering : std::binary_function<pii, pii, bool> {
    bool operator() (const pii &left, const pii &right) const { return  left.second < right.second; }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> a;
    read_some(a, N);

    std::vector<ll> prefix(N+1);
    prefix[0] = 0;

    std::set<pii, pair_ordering()> left;
    std::set<pii, pair_ordering()> right;

    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + a[i];

        if (i >= 1) {
            right.insert(std::make_pair(i, a[i]));
        }
    }

    int min = std::numeric_limits<ll>::max();
    int index = -1;
    int move = -1;

    for (int i = 0; i < N; i++) {
        ll x = prefix[i];
        ll y = prefix[N] - prefix[i+2];

        ll diff = std::abs(x - y);

        if (left.size() > 0) {
            auto it = std::lower_bound(left.begin(), left.end(), std::make_pair(0, diff / 2));

            if (it == left.end()) { it--; }

            ll new_diff = std::abs(x - y + it->second);
            if ()
        }

    }

    return 0;
}
