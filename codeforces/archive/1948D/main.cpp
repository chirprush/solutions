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
        std::string s;
        std::cin >> s;

        int n = s.size();
        int max = 0;
        
        // Define dp[l][i] to be the prefix for the number of matches with
        // substring length l at i
        std::vector<std::vector<int>> dp(n+1);

        for (int l = 0; l <= n; l++) {
            for (int i = 0; i <= n; i++) {
                dp[l].push_back(0);
            }
        }

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                dp[l][i+1] = dp[l][i];

                if (i + l >= n) { continue; }

                if (s[i] == s[i + l] || s[i + l] == '?' || s[i] == '?') {
                    dp[l][i+1]++;
                }
            }
        }

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                if (i + l <= n && dp[l][i+l] - dp[l][i] == l) {
                    max = std::max(max, 2 * l);
                }
            }
        }

        /*
        for (int l = 0; l <= n; l++) {
            for (int i = 0; i <= n; i++) {
                std::cout << dp[l][i] << " ";
            }
            std::cout << std::endl;
        }
        */

        std::cout << max << std::endl;
    }

    return 0;
}
