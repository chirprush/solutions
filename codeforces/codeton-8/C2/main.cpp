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

        std::set<int> left;
        for (int i = 0; i < n; i++) {
            left.insert(i);
        }

        std::vector<int> v;

        for (int i = 0; i < x; i++) {
            int u;
            std::cin >> u;
            u--;

            left.erase(u);
            v.push_back(u);
        }

        int count = x + y - 2;

        std::sort(v.begin(), v.end());

        std::vector<std::pair<int, int>> diffs;
        std::set<int> extras;
        
        for (int i = 0; i < x; i++) {
            int current = v[i];
            int next = v[(i + 1)%x];
            int diff;

            if (next < current) {
                diff = n + next - current;
            } else {
                diff = next - current;
            }

            diffs.push_back(std::make_pair(current, diff));
        }

        std::sort(diffs.begin(), diffs.end(), [](std::pair<int, int> &l, std::pair<int, int> &r) {
                if (l.second == r.second) { return l.first < r.first; }
                return l.second < r.second;
        });

        for (int i = 0; i < diffs.size(); i++) {
            int to = std::min((diffs[i].second - 1) / 2, y);

            if (diffs[i].second > 1 && diffs[i].second % 2 == 1) {
                extras.insert((diffs[i].second + diffs[i].first - 1 + n) % n);
            }
            
            for (int j = 1; j <= to; j++) {
                v.push_back((2 * j + diffs[i].first) % n);
                left.erase((2 * j + diffs[i].first) % n);
                extras.erase((2 * j + diffs[i].first) % n);
            }

            y -= to;
        }

        while (y && extras.size()) {
            int u = *(extras.begin());

            extras.erase(u);
            left.erase(u);
            v.push_back(u);

            y--;
        }

        while (y) {
            int u = *(left.begin());
            left.erase(u);
            v.push_back(u);
            y--;
        }

        std::sort(v.begin(), v.end());

        x = v.size();

        for (int i = 0; i < x; i++) {
            int current = v[i];
            int next = v[(i + 1)%x];
            count += next - current == 2 || (next < current && n + next - current == 2);
        }

        std::cout << count << std::endl;
    }

    return 0;
}
