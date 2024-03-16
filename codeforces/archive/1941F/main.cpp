#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>

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
void read_some(std::set<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.insert(a);
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
        ll n, m, k;
        std::cin >> n >> m >> k;

        std::vector<ll> a;
        std::set<ll> d, f;
        read_some(a, n);
        read_some(d, m);
        read_some(f, k);

        std::vector<std::pair<ll, ll>> da;

        for (int i = 0; i < n - 1; i++) {
            da.push_back(std::make_pair(i, a[i+1] - a[i]));
        }

        std::sort(da.begin(), da.end(), [](const auto &l, const auto &r) { return l.second < r.second; });

        ll ind = da[da.size() - 1].first;
        ll left = a[ind];
        ll right = a[ind+1];

        // std::cout << "(left, right): " << left << " " << right << std::endl;

        ll middle = std::ceil((left + right) / 2.0);

        ll best = right - left;
        ll before = 0;

        if (da.size() > 1) {
            before = da[da.size() - 2].second;
        }

        for (auto it = d.begin(); it != d.end(); it++) {
            ll di = *it;
            // std::cout << "d[i]: " << di << std::endl;

            if (di >= right) {
                break;
            }

            auto jt =  f.lower_bound(middle - di); // std::lower_bound(f.begin(), f.end(), middle - di);
            // std::cout << "Search for: " << (middle - di) << std::endl;

            if (jt != f.end()) {
                // std::cout << "Value: " << (*jt) << std::endl;
                best = std::min(best, std::max(before, std::max(right - (*jt + di), (*jt + di) - left)));
            }

            if (jt != f.begin()) {
                jt--;
                // std::cout << "Value: " << (*jt) << std::endl;
                best = std::min(best, std::max(before, std::max(right - (*jt + di), (*jt + di) - left)));
            }
        }

        std::cout << best << std::endl;
    }

    return 0;
}
