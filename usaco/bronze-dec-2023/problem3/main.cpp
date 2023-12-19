#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define ll long long

ll solve(ll N, std::vector<ll> &h, std::vector<ll> &a, std::vector<ll> &t) {
    std::vector<ll> index_map(N);

    for (ll i = 0; i < N; i++) {
        index_map[t[i]] = i;
    }

    ll d_lower = 0;
    ll d_upper = std::numeric_limits<ll>::max();

    if (N == 1) {
        if (t[0] == 0) {
            return 0;
        } else {
            return -1;
        }
    }

    for (ll j = 1; j < N; j++) {
        ll i = index_map[j];
        ll prev = index_map[j - 1];

        ll h_prev = h[prev];
        ll a_prev = a[prev];

        ll h_i = h[i];
        ll a_i = a[i];

        if (a_i >= a_prev && h_i >= h_prev) {
            return -1;
        } else if (a_i == a_prev && h_i < h_prev) {
            // Perhaps redundant because we have an else continue,
            // but this made more sense in my head while trying to
            // organize everything
            continue;
        } else if (a_i > a_prev && h_i < h_prev) {
            ll A = (h_prev - h_i) / (a_i - a_prev);
            if ((h_prev - h_i) % (a_i - a_prev) == 0) {
                A--;
            }
            d_upper = std::min(A, d_upper);
        } else if (a_i < a_prev && h_i >= h_prev) {
            d_lower = std::max(1 + (h_prev - h_i) / (a_i - a_prev), d_lower);
        } else {
            continue;
        }

        if (d_upper < d_lower) {
            return -1;
        }
    }

    return d_lower;
}

int main() {
    ll T;

    std::cin >> T;

    for (ll i = 0; i < T; i++) {
        ll N;
        std::cin >> N;

        std::vector<ll> h;
        std::vector<ll> a;
        std::vector<ll> t;

        for (ll j = 0; j < N; j++) {
            ll n;
            std::cin >> n;
            h.push_back(n);
        }

        for (ll j = 0; j < N; j++) {
            ll n;
            std::cin >> n;
            a.push_back(n);
        }

        for (ll j = 0; j < N; j++) {
            ll n;
            std::cin >> n;
            t.push_back(n);
        }

        std::cout << solve(N, h, a, t) << std::endl;
    }

    return 0;
}
