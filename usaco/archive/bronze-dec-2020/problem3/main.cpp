#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

struct Vec {
    int x;
    int y;
};

struct Cow {
    Vec pos;
    Vec dir;
    int t;
    bool done;
};

bool intersects(Cow &leader, Cow &other) {
    if (leader.dir.x == other.dir.x) {
        return false;
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Cow> cows;

    for (int _ = 0; _ < N; _++) {
        char d, 
    }
    return 0;
}
