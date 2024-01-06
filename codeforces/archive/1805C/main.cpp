#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

template<typename T>
void read_some(std::vector<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

int solve(std::vector<ll> &k, ll a, ll b, ll c) {
    ll min = (b - k[0]) * (b - k[0]);
    ll prev = min;
    int minIndex = 0;

    // You probably have to binary search this but I don't want to think about
    // this right now so let me just move on
    for (int i = 1; i < k.size(); i++) {
        ll value = (b - k[i]) * (b - k[i]);

        if (value > prev) { break; }

        if (value < min) {
            min = value;
            minIndex = i;
        }

        prev = value;
    }
    
    if (min - 4 * a * c < 0) {
        return minIndex;
    } else {
        return -1;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m;
        std::cin >> n >> m;

        std::vector<ll> slopes;

        for (int i = 0; i < n; i++) {
            ll k;
            std::cin >> k;
            slopes.push_back(k);
        }

        std::sort(slopes.begin(), slopes.end());

        for (int i = 0; i < m; i++) {
            ll a, b, c;
            std::cin >> a >> b >> c;
            int index = solve(slopes, a, b, c);

            if (index == -1) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl << slopes[index] << std::endl;
            }
        }
    }
    return 0;
}
