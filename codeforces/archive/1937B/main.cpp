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

        std::string a1, a2;
        std::cin >> a1 >> a2;

        int down = 0;
        int count = 0;

        // TODO: Actually fix this spaghetti
        for (int i = 0; i < n - 1; i++) {
            if (a1[i+1] >= a2[i]) {
                down++;
                break;
            }
        }

        std::string path = a1.substr(0, down + 1) + a2.substr(down);

        std::vector<bool> bottom(n);
        bottom[n - 1] = true;

        for (int i = 0; i < n - 1; i++) {
            bottom[n - 2 - i] = bottom[n - 1 - i] && (path[n - 1 - i] == a2[n - 2 - i]);
        }

        for (int i = 0; i < n; i++) {
            if (path[i] != a1[i]) {
                break;
            } else if (bottom[i]) {
                count++;
            }
        }

        std::cout << path << std::endl;
        std::cout << count << std::endl;
    }

    return 0;
}
