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

bool solve(int N, int A, int B) {
    if (A > N) {
        return false;
    }

    int left = N - A;
    int free = std::min(left, (N + 1)/2);
    return B <= free * left;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int N, A, B;
        std::cin >> N >> A >> B;

        std::cout << (solve(N, A, B) ? "Yes" : "No") << std::endl;
    }

    return 0;
}
