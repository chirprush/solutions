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
    int N, M, T;
    std::cin >> N >> M >> T;

    for (int t = 0; t < T; t++) {
        char state = 'C';
        std::vector<std::pair<int, int>> flipped;
        std::pair<int, int> prev = std::make_pair(-1, -1);
        bool first = true;
        // N is std::min(M, N)
        if (N == 2 || M <= 2) {
            // Always go second
            std::cout << 2 << std::endl << std::flush;

            while (state == 'C') {
                if (!first) {
                    std::cin >> state;
                } else { first = false; }
                int r, c;
                std::cin >> r >> c;

                prev = std::make_pair(r, c);

                bool found = false;
                for (int i = 0; i < flipped.size(); i++) {
                    if (flipped[i] == prev) {
                        flipped.erase(flipped.begin() + i);
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    flipped.push_back(prev);
                }

                // Place diagonal to
                if (flipped.size() == 1) {
                    r = (r + 1) % (N+1) + 1;
                    c = (c == 1) ? 2 : 1;
                    flipped.push_back(std::make_pair(r, c));
                } else if (flipped.size() == 3) {
                    if (flipped[0].second == flipped[1].second) {
                        r = flipped[0].first;
                        c = flipped[0].second;
                        flipped.erase(flipped.begin());
                    } else if (flipped[0].second == flipped[2].second) {
                        r = flipped[0].first;
                        c = flipped[0].second;
                        flipped.erase(flipped.begin());
                    } else {
                        r = flipped[1].first;
                        c = flipped[1].second;
                        flipped.erase(flipped.begin() + 1);
                    }
                }

                std::cout << r << " " << c << std::endl << std::flush;
            }

            if (state == 'I' || state == 'L') { return 0; }
        } else {
            // Always go first, halving the interval
            while (state == 'C') {
            }

            if (state == 'I' || state == 'L') { return 0; }
        }
    }

    return 0;
}
