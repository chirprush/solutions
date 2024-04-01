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

int a[(1 << 12)][(1 << 12)] = {0};

void construct_line(int i, int j, int n, bool horizontal) {
    for (int v = 0; v < (1 << (n + 1)); v++) {
        int place = v % 2 + 2 * (v / 4);
        int side = (v / 2) % 2;

        if (horizontal) {
            a[i + side][j + place] = v;
        } else {
            a[i + place][j + side] = v;
        }
    }
}

void add(int i, int j, int n, int m, int value) {
    // std::cout << "add(" << i << ", " << j << ", "  << n << ", " << m << ", " << value << ")" << std::endl;
    for (int k = 0; k < (1 << n); k++) {
        for (int l = 0; l < (1 << m); l++) {
            a[i + k][j + l] += value;
        }
    }
}

void construct(int i, int j, int n, int m) {
    // std::cout << "construct(" << i << ", " << j << ", "  << n << ", " << m << ")" << std::endl;
    if (n == 1) {
        construct_line(i, j, m, true);
    } else if (m == 1) {
        construct_line(i, j, n, false);
    } else {
        construct(i, j, n - 1, m - 1);

        construct(i, j + (1 << (m - 1)), n - 1, m - 1);
        add(i, j + (1 << (m - 1)), n - 1, m - 1, 1 << (m + n - 2));

        construct(i + (1 << (n - 1)), j, n - 1, m - 1);
        add(i + (1 << (n - 1)), j, n - 1, m - 1, 1 << (m + n - 1));

        construct(i + (1 << (n - 1)), j + (1 << (m - 1)), n - 1, m - 1);
        add(i + (1 << (n - 1)), j + (1 << (m - 1)), n - 1, m - 1, (1 << (m + n - 1)) + (1 << (m + n - 2)));
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    construct(0, 0, n, m);

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << m); j++) {
            std::cout << a[i][j] << " ";
        }

        std::cout << std::endl;
    }

    /*
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << m); j++) {
            for (int k = i + 1; k < (1 << n); k++) {
                for (int l = j + 1; l < (1 << m); l++) {
                    if (a[i][j] ^ a[i][l] ^ a[k][j] ^ a[k][l]) {
                        std::cout << "Bad pair" << std::endl;
                        std::cout << i << " " << j << " " << k << " " << l << std::endl;
                        std::cout << a[i][j] << " " << a[i][l] << " " << a[k][j] << " " << a[k][l] << std::endl;
                        goto end;
                    }
                }
            }
        }
    }

end:;
    */

    return 0;
}
