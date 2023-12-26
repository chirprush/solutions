#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int m;
    std::cin >> m;

    int counts[30] = {0};

    for (int _ = 0; _ < m; _++) {
        int t, v;
        std::cin >> t >> v;

        if (t == 1) {
            counts[v]++;
        } else {
            if (v == 0) { std::cout << "YES" << std::endl; continue; }

            int i = (int) log2(v);

            while (i >= 0 && v > 0) {
                if (counts[i] > 0 && v >= 1 << i) {
                    int d = std::min(v / (1 << i), counts[i]);
                    v -= d * (1 << i);
                }

                if (v == 0) { break; }
                i = std::min((int) log2(v), i - 1);
            }
            
            if (v == 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
