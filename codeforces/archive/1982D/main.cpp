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
        ll n, m, k;
        std::cin >> n >> m >> k;

        ll totalsum = 0;

        std::vector<std::vector<ll>> a;
        std::vector<std::vector<ll>> nums;

        std::vector<std::vector<ll>> r;
        std::vector<std::vector<ll>> c;

        for (int i = 0; i < n; i++) {
            std::vector<ll> v;

            read_some(v, m);

            nums.push_back(v);
        }

        for (int i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;

            std::vector<ll> arow;

            std::vector<ll> rowsum;
            rowsum.push_back(0);

            for (int j = 0; j < m; j++) {
                if (s[j] == '0') {
                    arow.push_back(1);
                } else {
                    arow.push_back(-1);
                }

                totalsum += arow[j] * nums[i][j];

                rowsum.push_back(rowsum[j] + arow[j]);
            }

            a.push_back(arow);
            r.push_back(rowsum);
        }

        for (int j = 0; j < m; j++) {
            std::vector<ll> colsum;
            colsum.push_back(0);

            for (int i = 0; i < n; i++) {
                colsum.push_back(colsum[i] + a[i][j]);
            }

            c.push_back(colsum);
        }

        ll sum = 0;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                sum += a[i][j];
            }
        }

        ll g = sum;

        for (int i = 0; i < n - k + 1; i++) {
            ll s = sum;

            for (int j = 0; j < m - k + 1; j++) {
                // std::cout << "(" << i << ", " << j << "): " << s << std::endl;
                g = std::__gcd(g, s);

                if (j == m - k) { continue; }

                s -= c[j][i + k] - c[j][i];
                s += c[j + k][i + k] - c[j + k][i];
            }

            if (i == n - k) { continue; }

            sum -= r[i][k] - r[i][0];
            sum += r[i + k][k] - r[i + k][0];
        }

        // std::cout << "GCD: " << g << std::endl;
        // std::cout << "Total: " << totalsum << std::endl;

        if (totalsum == 0 || (g != 0 && totalsum % g == 0)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
