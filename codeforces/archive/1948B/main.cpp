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
        int n;
        std::cin >> n;

        std::vector<int> a;
        read_some(a, n);

        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i+1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "YES" << std::endl;
        } else {
            std::vector<int> b;

            for (int i = 0; i < n; i++) {
                if (a[i] >= 10 && i <= index) {
                    b.push_back(a[i] / 10);
                    b.push_back(a[i] % 10);
                } else {
                    b.push_back(a[i]);
                }
            }

            bool good = true;

            for (int i = 0; i < b.size() - 1; i++) {
                if (b[i] > b[i+1]) {
                    good = false;
                    break;
                }
            }

            std::cout << (good ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}
