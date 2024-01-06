#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
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
    std::ofstream fout;
    std::ifstream fin;

    fin.open("blocks.in");
    fout.open("blocks.out");

    int letters[26] = {0};
    int N;
    fin >> N;
    for (int _ = 0; _ < N; _++) {
        int top[26] = {0};
        int bottom[26] = {0};

        std::string l, b;
        fin >> l >> b;

        for (int i = 0; i < l.length(); i++) {
            top[l[i] - 'a']++;
        }

        for (int i = 0; i < b.length(); i++) {
            bottom[b[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            letters[i] += std::max(top[i], bottom[i]);
        }
    }

    for (int i = 0; i < 26; i++) {
        fout << letters[i] << std::endl;
    }

    fin.close();
    fout.close();
    return 0;
}
