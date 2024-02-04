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

        std::vector<std::pair<int, int>> conds;
        bool failed = false;

        for (int i = 0; i < Q; i++) {
            int a, h;
            std::cin >> a >> h;
            a--;
            h--;
            conds.push_back(std::make_pair(a, h));
        }

        std::vector<int> maxes(N);

        for (int i = 0; i < N; i++) {
            maxes[i] = 0;
        }
        
        /*
        int m = 0;
        for (int i = 0; i < N; i++) {
            if (c[i]) {
                maxes[i] = std::max(c[i], m);
                m = maxes[i];
            } else {
                maxes[i] = 0;
            }
        }
        */

        // Does order matter when we're doing these conditions
        // I think so yeah how should I sort these then
        // Uhh we probably should sort them from left to right by a[j] idk
        std::sort(conds.begin(), conds.end(), [](const std::pair<int, int> &c1, const std::pair<int, int> &c2) { return c1.first < c2.first; });
        // ^ Actually if we have a bunch of zeros on the left and not on the
        // right, then this wouldn't be optimal but I'm going to be honest I'm
        // not sure if there's any way to make it optimal

        // If we have absolutely no information to work with we kinda have to
        // set c[i] to the minimum value possible
        // But like we still have to do this whenever there's also no
        // conditions on the values so perhaps this isn't the right place to
        // put this.
        /*
        bool all = true;
        for (int i = 0; i < N; i++) {
            if (c[i] != 0) {
                all = false;
            }
        }

        if (all)
        */

        // Make sure to check for actually setting less than 1
        while (true) {
            if (conds.size() == 0) {
                break;
            }

            int K = conds.size();

            for (int i = 0; i < conds.size(); i++) {
                std::pair<int, int> cond = conds[i];
                std::cerr << cond.first << " " << cond.second << std::endl;

                if (maxes[cond.first]) {
                    maxes[cond.second] = maxes[cond.first] + 1;
                } else if (maxes[cond.second]) {
                    maxes[cond.first] = maxes[cond.second] - 1;
                    if (maxes[cond.first] < 1) { goto failure; }
                } else { continue; }

                std::cerr << "Hit: " << cond.first << " " << cond.second << std::endl;

                for (int j = cond.first + 1; j < cond.second; j++) {
                    if (maxes[j] && maxes[j] != maxes[cond.first]) {
                        goto failure;
                    } else {
                        maxes[j] = maxes[cond.first];
                    }
                }

                conds.erase(conds.begin() + i);
                i--;
            }

            // This seems really inefficient
            if (K == conds.size()) {
                for (int i = 0; i < N; i++) {
                    if (i == 0 && maxes[i] == 0) {
                        maxes[i] = 1;
                        break;
                    } else if (maxes[i] == 0) {
                        maxes[i] = maxes[i-1];
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (i == 0 && maxes[i] == 0) {
                maxes[i] = 1;
            } else if (maxes[i] == 0) {
                maxes[i] = maxes[i-1];
            }
        }

        for (int i = 0; i < N; i++) {
            if (c[i]) { continue; }

            if (i == 0) {
                c[i] = maxes[i];
            } else if (maxes[i] == maxes[i-1]) {
                c[i] = 1;
            } else {
                // maxes[i] should be greater than maxes[i-1]
                c[i] = maxes[i];
            }

            if (c[i] < 1 || c[i] > C) {
                failed = true;
                break;
            }
        }

        if (failed) {
failure:
            std::cout << -1 << std::endl;
        } else {
            print_some(c);
        }
    }

    return 0;
}
