#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>
#include <tuple>

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
        int n, c, d;
        std::cin >> n >> c >> d;

        int a = std::numeric_limits<int>::max();

        std::map<int, int> given;

        for (int i = 0; i < n * n; i++) {
            int v;
            std::cin >> v;

            a = std::min(a, v);

            given[v]++;
        }

        /*
        std::cout << "A " << a << std::endl;

        std::cout << "Given" << std::endl;
        for (auto it = given.begin(); it != given.end(); it++) {
            std::pair<int, int> el = *it;

            std::cout << el.first << " " << el.second << std::endl;
        }
        */

        std::map<int, int> calc;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                calc[a + i * c + j * d]++;
            }
        }

        /*
        std::cout << "Calc" << std::endl;
        for (auto it = calc.begin(); it != calc.end(); it++) {
            std::pair<int, int> el = *it;

            std::cout << el.first << " " << el.second << std::endl;
        }
        */

        if (calc == given) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
