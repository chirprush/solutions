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
    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        char c;
        std::cin >> a >> c >> b;

        bool pm = a >= 12;

        int hour = a % 12;
        hour = hour == 0 ? 12 : hour;

        if (hour < 10) {
            std::cout << "0";
        }

        std::cout << hour << ":";

        if (b < 10) {
            std::cout << "0";
        }

        std::cout << b;

        std::cout << " " << (pm ? "PM" : "AM") << std::endl;
    }

    return 0;
}
