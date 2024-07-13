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

bool isIdentity(ll A[2][2]) {
    return A[0][0] == 1 && A[1][1] == 1 && A[0][1] == 0 && A[1][0] == 0;
}

void printMatrix(ll A[2][2]) {
    std::cout << A[0][0] << " " << A[0][1] << "\n" << A[1][0] << " " << A[1][1] << std::endl;
}

int main() {
    ll A[2][2] = {{1, 0}, {5, 3}};
    ll M = 10;
    ll k = 0;

    std::cout << "Determinant: " << (A[0][0] * A[1][1] - A[0][1] * A[1][0]) % M << std::endl;

    ll B[2][2] = {{1, 0}, {0, 1}};

    while (k == 0 || !isIdentity(B)) {
        ll C[2][2] = {{0, 0}, {0, 0}};
        
        C[0][0] = (A[0][0] * B[0][0] % M + A[0][1] * B[1][0] % M) % M;
        C[0][1] = (A[0][0] * B[0][1] % M + A[0][1] * B[1][1] % M) % M;
        C[1][0] = (A[1][0] * B[0][0] % M + A[1][1] * B[1][0] % M) % M;
        C[1][1] = (A[1][0] * B[0][1] % M + A[1][1] * B[1][1] % M) % M;

        B[0][0] = C[0][0];
        B[0][1] = C[0][1];
        B[1][0] = C[1][0];
        B[1][1] = C[1][1];

        k++;

        std::cout << k << std::endl;
        printMatrix(B);
    }

    return 0;
}
