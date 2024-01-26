/*
ID: rush0401
TASK: combo
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

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<int> john;
    std::vector<int> master;

    read_some(john, 3);
    read_some(master, 3);

    std::set<std::string> combos;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                int a = john[0] + i;
                int b = john[1] + j;
                int c = john[2] + k;

                std::string s1 = std::to_string((a + N) % N) + " " + std::to_string((b + N) % N) + " " +std::to_string((c + N) % N);

                a = master[0] + i;
                b = master[1] + j;
                c = master[2] + k;

                std::string s2 = std::to_string((a + N) % N) + " " + std::to_string((b + N) % N) + " " +std::to_string((c + N) % N);

                combos.insert(s1);
                combos.insert(s2);
            }
        }
    }

    std::cout << combos.size() << std::endl;

    return 0;
}
