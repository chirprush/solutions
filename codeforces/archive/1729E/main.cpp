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

// This doesn't work at all btw so come back to this later
int main() {
    ll n = 1;

    while (n <= 50) {
        std::cout << "? " << n << " " << (n + 1) << std::endl;

        ll result;
        std::cin >> result;

        if (result == -1) {
            std::cout << "! " << n << std::endl;
            break;
        } else if (result > 1) {
            std::cout << "! " << (result + 1) << std::endl;
            break;
        }

        n++;
    }

    return 0;
}
