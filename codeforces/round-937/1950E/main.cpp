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
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int best = n;

        for (int i = 1; i <= (int)std::round(std::sqrt(n)); i++) {
            if (n % i != 0) { continue; }

            int count = 0;

            for (int j = 0; j < i; j++) {
                int total = 0;
                std::map<char, int> counts;
                char best = s[j];

                for (int k = 0; k < n / i; k++) {
                    total++;
                    counts[s[j + k * i]]++;

                    if (counts[s[j + k * i]] > counts[best]) {
                        best = s[j + k * i];
                    }
                }

                count += total - counts[best];
            }

            if (count <= 1) {
                best = std::min(i, best);
            }

            count = 0;

            for (int j = 0; j < n / i; j++) {
                int total = 0;
                std::map<char, int> counts;
                char best = s[j];

                for (int k = 0; k < i; k++) {
                    total++;
                    counts[s[j + k * (n / i)]]++;

                    if (counts[s[j + k * (n / i)]] > counts[best]) {
                        best = s[j + k * (n / i)];
                    }
                }

                count += total - counts[best];
            }

            if (count <= 1) {
                best = std::min(n / i, best);
            }
        }

        std::cout << best << std::endl;
    }

    return 0;
}
