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
        int n, x, y;
        std::cin >> n >> x >> y;

        std::vector<int> v;

        for (int i = 0; i < x; i++) {
            int u;
            std::cin >> u;
            u--;
            v.push_back(u);
        }

        std::sort(v.begin(), v.end());

        int count = x - 2;

        for (int i = 0; i < x; i++) {
            int current = v[i];
            int next = v[(i + 1)%x];
            count += next - current == 2 || (next < current && n + next - current == 2);
        }

        std::cout << count << std::endl;
    }

    return 0;
}
