#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        int lower = std::numeric_limits<int>::min();
        int upper = std::numeric_limits<int>::max();
        std::vector<int> nots;

        while (n--) {
            int type, value;

            std::cin >> type >> value;
            if (type == 1) {
                lower = std::max(lower, value);
            } else if (type == 2) {
                upper = std::min(upper, value);
            } else if (type == 3) {
                nots.push_back(value);
            }
        }

        if (lower > upper) {
            std::cout << 0 << std::endl;
        } else {
            int count = 0;
            for (int i = 0; i < nots.size(); i++) {
                if (nots[i] <= upper && nots[i] >= lower) {
                    count++;
                }
            }

            std::cout << 1 + upper - lower - count << std::endl;
        }
    }
    return 0;
}
