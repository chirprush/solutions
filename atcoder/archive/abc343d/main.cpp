#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

int main() {
    ll n, t;
    std::cin >> n >> t;
    
    std::map<ll, ll> counts;
    std::vector<ll> values(n);

    counts[0] = n;
    ll distinct = 1;
    
    for (ll i = 0; i < t; i++) {
        ll a, b;
        std::cin >> a >> b;
        a--;

        counts[values[a]]--;

        if (counts[values[a]] == 0) {
            distinct--;
        }

        if (counts[values[a] + b] == 0) {
            distinct++;
        }

        counts[values[a] + b]++;
        values[a] += b;

        std::cout << distinct << std::endl;
    }

    return 0;
}
