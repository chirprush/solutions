#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> mids;
    std::vector<int> ends;

    bool end = false;
    int current = 0;

    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c;

        if (c == '1') {
            current++;

            if (i == 0) {
                end = true;
            }
        } else if (current > 0) {
            if (end) {
                ends.push_back(current);
            } else {
                mids.push_back(current);
            }
            end = false;
            current = 0;
        }
    }

    if (current > 0) {
        ends.push_back(current);
    }

    std::vector<int> middle_times(N);
    int t_max = std::numeric_limits<int>::max();
    
    for (int i = 0; i < mids.size(); i++) {
        middle_times[i] = (mids[i] - 1) / 2;
        t_max = std::min(middle_times[i], t_max);
    }

    if (ends.size() == 0) {
        int S = 0;

        for (int i = 0; i < mids.size(); i++) {
            S += mids[i] - 2 * t_max;
        }

        std::cout << S << std::endl;
    } else {
        int ends_max = *std::min_element(ends.begin(), ends.end()) - 1;

        if (mids.size() == 0) {
            int S = 0;
            
            for (int i = 0; i < ends.size(); i++) {
                S += (int)ceil((double) (ends[i]) / (2 * ends_max + 1));
            }

            std::cout << S << std::endl;

            return 0;
        } else {
            int best_time = std::min(ends_max, t_max);
            std::vector<int> sums;

            for (int t = 0; t <= best_time; t++) {
                int S = 0;

                for (int i = 0; i < mids.size(); i++) {
                    S += mids[i] - 2 * t;
                }

                for (int i = 0; i < ends.size(); i++) {
                    S += (int) ceil((double) ends[i] / (2 * t + 1));
                }

                sums.push_back(S);
            }

            int smallest = *std::min_element(sums.begin(), sums.end());

            std::cout << smallest << std::endl;
        }
    }

    return 0;
}
