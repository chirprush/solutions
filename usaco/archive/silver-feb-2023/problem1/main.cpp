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
    std::cerr << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cerr << " " << v[i];
    }
    
    std::cerr << " ]" << std::endl;
}

typedef std::pair<double, double> Line;

std::pair<double, double> intersect(const Line &l1, const Line &l2) {
    if (std::abs(l1.first - l2.first) < 1e-9) {
        return std::make_pair(0, 0);
    }
    
    double x = (double) (l2.second - l1.second) / (l1.first - l2.first);
    double y = l1.first * x + l1.second;

    return std::make_pair(x, y);
}


int main() {
    int t;
    std::cin >> t;

    // Okay this solution works for the very first test case and then fails
    // quite spectacularly on everything else so check this later.

    while (t--) {
        ll N, tc, tm;
        std::cin >> N >> tc >> tm;

        std::vector<ll> a, b, c;

        for (int i = 0; i < N; i++) {
            ll ai, bi, ci;
            std::cin >> ai >> bi >> ci;

            a.push_back(ai);
            b.push_back(bi);
            c.push_back(ci);
        }

        std::vector<ll> criticals;
        std::vector<Line> lines;

        for (int i = 0; i < N; i++) {
            double m = - (double) b[i] / a[i];
            double q = ((double) (a[i] * tc + b[i] * tm - c[i])) / (a[i]);
            if (q > 0) {
                lines.push_back(std::make_pair(m, q));
            }
        }

        lines.push_back(std::make_pair(0, 0));

        std::sort(lines.begin(), lines.end(), [](const Line &l1, const Line &l2) { return l1.second > l2.second; });

        /*
        for (int i = 0; i < lines.size(); i++) {
            std::cerr << lines[i].first << " " << lines[i].second << std::endl;
        }
        */

        int i = 0;
        Line &current = lines[i];

        criticals.push_back(std::ceil(current.second));

        while (i < lines.size()) {
            // std::cerr << "i: " << i << std::endl;
            int min_index = lines.size();
            double min = std::numeric_limits<double>::max();

            for (int j = i + 1; j < lines.size(); j++) {
                const Line &compare = lines[j];
                std::pair<double, double> point = intersect(current, compare);

                if (point.first > 0 && point.first <= min) {
                    min_index = j;
                    min = point.first;
                }
            }

            if (min_index == lines.size()) { break; }

            std::pair<double, double> next = intersect(current, lines[min_index]);
            current = lines[min_index];
            criticals.push_back(std::ceil(next.first) + std::ceil(next.second));

            i = min_index;
        }

        // print_some(criticals);

        if (criticals.size()) {
            std::cout << *std::min_element(criticals.begin(), criticals.end()) << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}
