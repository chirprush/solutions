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

struct Entry {
    std::map<char, int> counts;
    std::vector<char> stack;
};

int main() {
    int n, q;
    std::cin >> n >> q;

    Entry counts[101][101] = {};

    for (int i = 0; i < q; i++) {
        int s;
        std::cin >> s;

        if (s == 0) {
            char l;
            int x, y;

            std::cin >> l >> x >> y;

            counts[x][y].counts[l]++;
            counts[x][y].stack.push_back(l);
        } else if (s == 1) {
            int x, y;
            std::cin >> x >> y;
            if (!counts[x][y].stack.size()) { continue; }
            char l = counts[x][y].stack[counts[x][y].stack.size()-1];
            counts[x][y].stack.pop_back();
            counts[x][y].counts[l]--;
        } else {
            char l;
            int x, y;
            std::cin >> l >> x >> y;

            if (2 * counts[x][y].counts[l] > counts[x][y].stack.size()) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        }
    }

    return 0;
}
