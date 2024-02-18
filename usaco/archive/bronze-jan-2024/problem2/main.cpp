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
    int N, S;
    std::cin >> N >> S;

    std::vector<std::pair<int, int>> spots;
    std::vector<int> past;
    std::vector<int> broken;

    for (int i = 0; i < N; i++) {
        int q, v;
        std::cin >> q >> v;
        spots.push_back(std::make_pair(q, v));
        past.push_back(0);
        broken.push_back(0);
    }

    int i = S-1;
    int power = 1;
    int dir = 1;
    int score = 0;

    while (true) {
        if (i < 0 || i >= N || power * dir == past[i]) {
            break;
        }

        past[i] = power * dir;

        if (spots[i].first == 0) {
            power += spots[i].second;
            dir = -dir;
        } else if (spots[i].second <= power && !broken[i]) {
            score++;
            broken[i] = 1;
        }
        
        i += power * dir;
    }

    std::cout << score << std::endl;
    
    return 0;
}
