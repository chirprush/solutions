/*
ID: rush0401
TASK: beads
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
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << " " << v[i];
    }
    
    std::cout << " ]" << std::endl;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int N;
    std::cin >> N;

    std::string necklace;
    std::vector<std::pair<char, int>> lengths;

    std::cin >> necklace;

    char current = necklace[0];
    int length = 1;

    for (int i = 1; i < N; i++) {
        if (necklace[i] != current) {
            lengths.push_back(std::make_pair(current, length));
            current = necklace[i];
            length = 1;
        } else {
            length++;
        }
    }

    lengths.push_back(std::make_pair(current, length));

    if (lengths[N - 1].first == lengths[0].first && lengths.size() > 1) {
        lengths[0].second += lengths[N - 1].second;
        lengths.erase(lengths.end());
    }

    int max = 0;
    int K = lengths.size();

    for (int i = 0; i < K; i++) {
        int running = 0;

        char current;
        if (lengths[i].first == 'w') {
            current = 'r';
        } else {
            current = lengths[i].first;
        }

        running += lengths[i].second;
repeat:
        int j = (i + 1) % K;
        while (j != i) {
            if (lengths[j].first != current && lengths[j].first != 'w') {
                j--;
                break;
            } else {
                running += lengths[j].second;
            }

            j = (j + 1) % K;
        }

        current = current == 'r' ? 'b' : 'r';

        int k = (i - 1 + K) % K;
        while (k != j) {
            if (lengths[k].first != current && lengths[k].first != 'w') {
                break;
            }

            running += lengths[k].second;

            k = (k - 1 + K) % K;
        }

        max = std::max(max, running);

        if (lengths[i].first == 'w' && current == 'b') {
            current = 'b';
            goto repeat;
        }
    }

    std::cout << max << std::endl;

    return 0;
}
