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
        std::string s;

        std::cin >> n;
        std::cin >> s;



        /*
        int u = 0;
        int d = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') {
                u++;
            } else if (s[i] == 'D') {
                d++;
            }
        }

        std::cout << 2 * std::min(u, d) << std::endl;
        */

        /*
        std::vector<int> prefix;
        prefix[0] = (s[0] == 'U' ? 1 : -1);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + (s[i] == 'U' ? 1 : -1);
        }
        */
    }

    return 0;
}
