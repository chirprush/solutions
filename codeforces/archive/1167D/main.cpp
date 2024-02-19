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

    std::string s;
    std::cin >> s;

    int level = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            std::cout << (level % 2);
            level++;
        } else {
            level--;
            std::cout << (level % 2);
        }
    }

    std::cout << std::endl;

    return 0;
}
