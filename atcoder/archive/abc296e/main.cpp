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

    std::vector<int> A;
    read_some(A, N);

    std::vector<int> AK(N);
    std::set<int> winning;

    for (int i = 0; i < N; i++) {
        A[i]--;
        AK[i] = A[i];
    }

    // This kinda obviously TLEs so come back to it later
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            AK[j] = A[AK[j]];

            if (AK[j] == j) {
                winning.insert(j);
                break;
            }
        }
    }

    std::cout << winning.size() << std::endl;

    return 0;
}
