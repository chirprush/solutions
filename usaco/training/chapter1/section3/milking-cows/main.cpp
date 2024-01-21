/*
ID: rush0401
TASK: milk2
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
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

struct Bound {
    int t;
    bool start;
};

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<Bound> bounds;

    for (int i = 0; i < N; i++) {
        int start, end;
        std::cin >> start >> end;

        bounds.push_back((Bound) { start, true });
        bounds.push_back((Bound) { end, false });
    }

    std::sort(bounds.begin(), bounds.end(), [](const Bound &left, const Bound &right) { return left.t < right.t; });

    std::vector<std::pair<int, int>> intervals;

    int i = 0;
    int level = 0;
    int start = -1;

    /*
    for (const auto &b : bounds) {
        std::cerr << b.t << " " << b.start << std::endl;
    }

    std::cerr << std::endl;
    */

    while (i < bounds.size()) {
        if (start < 0) {
            start = bounds[i].t;
        }

        int value = bounds[i].t;
        while (bounds[i].t == value && i < bounds.size()) {
            level += bounds[i].start ? 1 : -1;
            i++;
        }
        i--;

        if (level == 0) {
            intervals.push_back(std::make_pair(start, bounds[i].t));
            start = -1;
        }

        i++;
    }

    /*
    for (const auto &i : intervals) {
        std::cerr << i.first << " " << i.second << std::endl;
    }
    */

    int milking = 0;
    int idle = 0;

    for (int i = 0; i < intervals.size(); i++) {
        milking = std::max(milking, intervals[i].second - intervals[i].first);

        if (i > 0) {
            idle = std::max(idle, intervals[i].first - intervals[i-1].second);
        }
    }
    
    std::cout << milking << " " << idle << std::endl;

    return 0;
}
