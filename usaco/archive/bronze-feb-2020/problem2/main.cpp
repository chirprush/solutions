#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <cstdio>

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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N;
    std::cin >> N;

    std::string A, B;
    std::cin >> A >> B;

    int count = 0;
    bool currently = false;

    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            currently = true;
        } else if (A[i] == B[i] && currently) {
            currently = false;
            count++;
        }
    }

    if (currently) {
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}
