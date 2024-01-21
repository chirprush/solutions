/*
ID: rush0401
TASK: gift1
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
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << " ]" << std::endl;
}

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int N;
    std::cin >> N;

    std::map<std::string, int> names;
    std::vector<std::string> people;

    std::vector<int> balances(N);

    for (int i = 0; i < N; i++) {
        std::string name;
        std::cin >> name;

        names[name] = i;
        people.push_back(name);
        balances[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        std::string name;
        std::cin >> name;

        int index = names[name];

        int initial, k;
        std::cin >> initial >> k;

        if (k > 0) {
            balances[index] += - (initial / k) * k;
        } else {
            balances[index] += initial;
        }

        for (int j = 0; j < k; j++) {
            std::string other_name;
            std::cin >> other_name;

            int other = names[other_name];

            balances[other] += initial / k;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << people[i] << " " << balances[i] << std::endl;
    }

    return 0;
}
