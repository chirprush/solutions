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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);

    std::vector<int> counts(m);

    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;

        for (int j = 0; j < m; j++) {
            counts[j] += (line[j] == 'S');
        }
    }

    for (int i = 0; i < n; i++) {
        grid[i] = "";

        for (int j = 0; j < m; j++) {
            if ((n - i - 1) < counts[j]) {
                grid[i] += "S";
            } else {
                grid[i] += ".";
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << grid[i] << std::endl;
    }

    return 0;
}
