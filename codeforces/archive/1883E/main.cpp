#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<double> a(n);

        for (int i = 0; i < n; i++) {
            int j;
            std::cin >> j;

            a[i] = std::log2(j);
        }
        
        ll count = 0;

        for (int i = 1; i < n; i++) {
            ll diff = std::max(0ll, (ll) std::ceil(a[i - 1] - a[i]));
            count += diff;
            a[i] += diff;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
