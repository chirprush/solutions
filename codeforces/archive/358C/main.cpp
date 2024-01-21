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
    int n;
    std::cin >> n;

    std::vector<int> a;
    read_some(a, n);

    std::vector<std::vector<int>> blocks;

    std::vector<int> current = {};

    // ~~Assume that the input ends with a 0 all the time otherwise the test
    // creators are evil~~
    // They are
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            blocks.push_back(current);
            current = {};
        } else {
            current.push_back(a[i]);
        }
    }

    if (current.size()) {
        current.insert(current.begin(), 0);
        blocks.push_back(current);
    }

    for (std::vector<int> &block : blocks) {
        bool bad = block.size() > 0 && block[0] == 0;

        if (bad) {
            block.erase(block.begin());
        }

        int N = block.size();

        if (N == 0) {
            std::cout << 0 << std::endl;
        } else if (N == 1) {
            std::cout << "pushStack" << std::endl;
            if (!bad) { std::cout << "1 popStack" << std::endl; }
        } else if (N == 2) {
            std::cout << "pushStack" << std::endl;
            std::cout << "pushQueue" << std::endl;
            if (!bad) { std::cout << "2 popStack popQueue" << std::endl; }
        } else if (N == 3) {
            std::cout << "pushStack" << std::endl;
            std::cout << "pushQueue" << std::endl;
            std::cout << "pushFront" << std::endl;
            if (!bad) { std::cout << "3 popStack popQueue popFront" << std::endl; }
        } else {
            std::vector<int> indices(N);

            for (int i = 0; i < N; i++) {
                indices[i] = i;
            }

            std::sort(indices.begin(), indices.end(), [&block](int i, int j) { return block[i] < block[j]; });

            // Perhaps a waste of memory but hey
            std::set<int> good = {indices[N - 1], indices[N - 2], indices[N - 3]};

            int count = 0;

            for (int i = 0; i < N; i++) {
                if (count == 0 && !good.count(i)) {
                    std::cout << "pushStack" << std::endl;
                } else if (count == 0 && good.count(i)) {
                    std::cout << "pushFront" << std::endl;
                    count++;
                } else if (count == 1 && !good.count(i)) {
                    std::cout << "pushStack" << std::endl;
                } else if (count == 1 && good.count(i)) {
                    std::cout << "pushStack" << std::endl;
                    count++;
                } else if (count == 2 && !good.count(i)) {
                    std::cout << "pushBack" << std::endl;
                } else if (count == 2 && good.count(i)) {
                    std::cout << "pushQueue" << std::endl;
                }
            }
            
            if (!bad) { std::cout << "3 popStack popQueue popFront" << std::endl; }
        }
    }

    return 0;
}
