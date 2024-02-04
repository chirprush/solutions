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
    // std::cout << "[";
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++) {
        std::cout << " " << v[i];
    }

    std::cout << std::endl;
    
    // std::cout << " ]" << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int N, Q, C;
        std::cin >> N >> Q >> C;

        std::vector<int> c;
        read_some(c, N);

        // std::vector<std::pair<int, int>> pairs;
        std::map<int, int> conds;
        std::map<int, int> rev_conds;

        for (int i = 0; i < Q; i++) {
            int a, h;
            // The *first* cow with a strictly greater score than all cows 1 to
            // a
            std::cin >> a >> h;
            h--;
            a--;
            if (conds[h]) {
                conds[h] = std::max(a, conds[h]);
            } else {
                conds[h] = a;
            }
            rev_conds[a] = h;
            // pairs.push_back(std::make_pair(a, h));
        }

        std::vector<int> maxes(N);
        bool failed = false;

        for (int i = 0; i < N; i++) {
            if (c[i] != 0) {
                maxes[i] = i == 0 ? c[i] : std::max(c[i], maxes[i-1]);
            } if (c[i] == 0 && conds.count(i)) {
                // h cannot be 1
                // Do we ever have to add more than 1?
                c[i] = maxes[i - 1] + 1;

                if (c[i] > C) {
                    std::cout << -1 << std::endl;
                    failed = true;
                    break;
                }

                maxes[i] = c[i];

                // Check here whether this is violated in between h and a?
                // Sufficient to check at h - 1 and a right because maxes is
                // monotonic
                if (maxes[i-1] != maxes[conds[i]]) {
                    std::cout << -1 << std::endl;
                    failed = true;
                    break;
                }
            } else if (c[i] == 0) {
                c[i] = 1;
                maxes[i] = i == 0 ? 1 : maxes[i-1];
            }
        }

        if (!failed) {
            print_some(c);
        }
    }

    return 0;
}
