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

    int a = 0;
    int b = 0;
    int h = 0;


    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == '.') { continue; }

            if (line[j] - '0' > h) {
                a = i + 1;
                b = j + 1;
                h = line[j] - '0';
            }
        }
    }

    std::cout << a << " " << b << std::endl;

    return 0;
}
