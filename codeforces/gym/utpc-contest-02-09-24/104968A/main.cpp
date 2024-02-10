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
    int n;
    std::cin >> n;
    int p = 0;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'p' || s[i] == 'P') {
                p++;
            }
        }
    }

    std::cout << p << std::endl;

    return 0;
}
