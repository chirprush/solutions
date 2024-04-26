#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>

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

        std::vector<std::pair<char, int>> blocks;

        blocks.push_back(std::make_pair(s[0], 1));

        for (int i = 1; i < n; i++) {
            if (blocks[blocks.size() - 1].first == s[i]) {
                blocks[blocks.size() - 1].second++;
            } else {
                blocks.push_back(std::make_pair(s[i], 1));
            }
        }

        if (blocks[0].first == '1') {
            blocks.erase(blocks.begin());
        }

        if (blocks[blocks.size() - 1].first == '1') {
            auto it = blocks.end();
            it--;
            blocks.erase(it);
        }

        int g = 0;

        if (blocks.size() == 1 && blocks[0].first == '0') {
            g = blocks[0].second;
        }

        bool skip = false;

        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i].first == '1') {
                continue;
            }

            if (skip) {
                skip = false;
                continue;
            }

            /*
            if (i != 0) {
                g = std::__gcd(g, blocks[i].second + blocks[i-1].second);
            }
            */

            if (i + 2 < blocks.size()) {
                g = std::__gcd(g, std::__gcd(blocks[i].second + blocks[i+1].second, blocks[i+1].second + blocks[i+2].second));
            } else {
                g = std::__gcd(g, blocks[i].second);
            }

            skip = true;
        }

        if (g == 0) {
            std::cout << n << std::endl;
        } else {
            std::cout << g << std::endl;
        }
    }

    return 0;
}
