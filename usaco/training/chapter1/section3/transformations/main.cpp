/*
ID: rush0401
TASK: transform
LANG: C++11
*/
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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

/*
 * @--@
 * ---@
 * -@.@
 * @@@@
 *
 * @--@
 * @@--
 * @.--
 * @@@@
 *
 * (x, y) -> (N - 1 - y, x)
 * Ex. (2, 1) -> (2, 2)
 *     (2, 2) -> (1, 2)
 */

void rotate(std::vector<char> &pattern, int N) {
    std::vector<char> temp(N*N);
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            temp[x * N + (N - 1 - y)] = pattern[y * N + x];
        }
    }

    for (int i = 0; i < N * N; i++) {
        pattern[i] = temp[i];
    }
}

void reflect(std::vector<char> &pattern, int N) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N / 2; x++) {
            std::swap(pattern[y * N + x], pattern[y * N + (N - 1 - x)]);
        }
    }
}

void print_pattern(const std::vector<char> &pattern, int N) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cerr << pattern[y * N + x];
        }
        std::cerr << std::endl;
    }
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<char> before(N * N);
    std::vector<char> after(N * N);

    int j = 0;
    for (int i = 0; i < N; i++) {
        std::string line;
        std::cin >> line;

        for (int k = 0; k < N; k++) {
            before[j] = line[k];
            j++;
        }
    }

    j = 0;
    for (int i = 0; i < N; i++) {
        std::string line;
        std::cin >> line;

        for (int k = 0; k < N; k++) {
            after[j] = line[k];
            j++;
        }
    }

    bool valid = false;

    int i;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (before == after) {
                valid = true;
                goto outer;
            }

            rotate(before, N);
        }

        reflect(before, N);
    }
outer:

    if (!valid) {
        std::cout << 7 << std::endl;
    } else if (i == 0 && j > 0) {
        std::cout << j << std::endl;
    } else if (i > 0 && j == 0) {
        std::cout << 4 << std::endl;
    } else if (i > 0 && j > 0) {
        std::cout << 5 << std::endl;
    } else if (i == 0 && j == 0) {
        std::cout << 2 << std::endl;
    }

    return 0;
}
