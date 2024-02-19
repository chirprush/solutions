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

        std::string s;
        std::cin >> s;

        int score = 0;

        int i = 0;
        while (i < n) {
            if (s[i] == '@') { score++; }

            if (i < n - 1 && s[i+1] != '*') {
                i++;
            } else if (i < n - 2 && s[i+2] != '*') {
                i += 2;
            } else {
                break;
            }
        }

        std::cout << score << std::endl;;
    }

    return 0;
}
