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
    int N;
    std::cin >> N;
    std::vector<int> a;
    read_some(a, N);

    std::sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += a[i];
    }

    std::cout << sum / (N - 1) << std::endl;

    return 0;
}
