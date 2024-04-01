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

    std::vector<int> a;
    std::vector<int> equiv(n+1);

    read_some(a, n);

    std::vector<int> divisors;

    for (int i = 1; i <= (int)std::round(std::sqrt(n)); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
    }

    for (int divisor : divisors) {
        equiv[divisor] = a[0];
        int pos = divisor % n;

        while (pos != 0) {
            equiv[divisor] += a[pos];
            pos = (pos + divisor) % n;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << equiv[std::__gcd(i, n)] << std::endl;
    }

    return 0;
}
