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
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> B;
    read_some(B, N);

    std::sort(B.rbegin(), B.rend());

    int max = 0;

    for (int b = 1; b <= B[0]; b++) {
        int bessie = 0;
        std::vector<int> nums = B;

        int i = 0, j = 0;

        while (i < N) {
            j += nums[i] / b;
            nums[i] %= b;
            i++;
        }

        if (j >= K) {
            bessie = K / 2 * b;
        } else if (j < K / 2) {
            break;
        } else {
            bessie += b * (j - K / 2);

            std::sort(nums.rbegin(), nums.rend());

            // Not sure if the i < N is needed but
            for (int i = 0; i < K - j && i < N; i++) {
                bessie += nums[i];
            }
        }

        max = std::max(bessie, max);
    }

    std::cout << max << std::endl;

    return 0;
}
