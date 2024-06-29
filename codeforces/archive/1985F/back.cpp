#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
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

ll lcm(ll a, ll b) {
    return a * b / std::__gcd(a, b);
}

ll score(ll t, const std::vector<ll> &a, const std::vector<ll> &c) {
    ll s = 0;

    for (ll i = 0; i < a.size(); i++) {
        s += a[i] * (t / c[i] + 1);
    }

    return s;
}

ll search(ll lower, ll upper, ll h, const std::vector<ll> &a, const std::vector<ll> &c) {
    // std::cout << "Search(" << lower << ", " << upper << ")" << std::endl;

    if (lower >= upper) {
        return lower;
    }

    ll mid = (lower + upper) / 2;

    ll mscore = score(mid, a, c);
    // std::cout << "Score(" << mid << ") = " << mscore << std::endl;

    if (mscore >= h) {
        return search(lower, mid, h, a, c);
    } else {
        return search(mid+1, upper, h, a, c);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll h, n;
        std::cin >> h >> n;

        std::vector<ll> a;
        std::vector<ll> c;

        read_some(a, n);
        read_some(c, n);

        ll biglcm = 1;

        for (ll i = 0; i < n; i++) {
            biglcm = lcm(c[i], biglcm);
        }

        ll healthperlcm = score(biglcm, a, c);

        for (ll i = 0; i < n; i++) {
            healthperlcm -= a[i];
        }

        ll lower = 0; // std::max(0.0, biglcm * (std::floor((double) h / healthperlcm) - 1));
        ll upper = std::numeric_limits<ll>::max(); // biglcm * std::ceil((double) h / healthperlcm);

        std::cout << "Health Per Lcm: " << healthperlcm << " Lcm: " << biglcm << std::endl;
        std::cout << "Lower: " << lower << " Upper: " << upper << std::endl;

        std::cout << (1 + search(lower, upper, h, a, c)) << std::endl;
    }

    return 0;
}
