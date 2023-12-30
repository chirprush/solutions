#include <iostream>
#include <vector>
#include <map>
#include <utility>
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

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> intervals;
        
        for (int i = 0; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            intervals.push_back(std::make_pair(a, b));
        }

        std::sort(intervals.begin(), intervals.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.second - p1.first < p2.second - p2.first; });

        int count = 0;
        // I have no clue how to do this in O(n) so let's hope O(n^2) works
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intervals[i].first > intervals[j].first && intervals[i].second < intervals[j].second) {
                    count++;
                }
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
