#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void read_some(std::vector<T> &v, int N) {
    for (int i = 0; i < N; i++) {
        T a;
        std::cin >> a;
        v.push_back(a);
    }
}

template<typename T>
void print_vec(std::vector<T> &v) {
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++) {
        std::cout << " " << v[i];
    }

    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++) {
        int N;
        std::cin >> N;
        std::vector<int> v;

        read_some<int>(v, N);

        int negatives = 0;
        bool done = false;

        for (int i = 0; i < N; i++) {
            if (v[i] < 0) {
                negatives++;
            } else if (v[i] == 0) {
                std::cout << 0 << std::endl;
                done = true;
                break;
            }
        }

        if (done) { continue; }

        if (negatives % 2 == 0) {
            std::cout << 1 << std::endl;
            std::cout << 1 << " " << 0 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}
