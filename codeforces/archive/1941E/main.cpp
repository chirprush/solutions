#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>

typedef long long ll;
typedef std::pair<ll, ll> E;

ll dp[200001] = {0};

struct ValueComp {
    bool operator() (const E &l, const E &r) {
        if (l.second == r.second) {
            return l.first < r.first;
        }
        return l.second < r.second;
    }
};

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n, m, k, d;
        std::cin >> n >> m >> k >> d;

        std::vector<ll> costs(n);

        for (int i = 0; i < n; i++) {
            std::set<E, ValueComp> current;

            dp[0] = 1;
            current.insert(std::make_pair(0, 1));

            for (int j = 0; j < m; j++) {
                ll w;
                std::cin >> w;

                if (j == 0) { continue; }

                if (j > d + 1) {
                    current.erase(std::make_pair(j - d - 2, dp[j - d - 2]));
                }

                ll score = (current.begin())->second + w + 1;
                dp[j] = score;
                current.insert(std::make_pair(j, score));
            }

            costs[i] = dp[m - 1];
        }

        std::vector<ll> prefix(n+1);
        prefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + costs[i];
        }

        ll total = prefix[k] - prefix[0];

        for (int i = 0; i < n - k + 1; i++) {
            total = std::min(total, prefix[i + k] - prefix[i]);
        }

        std::cout << total << std::endl;
    }

    return 0;
}
