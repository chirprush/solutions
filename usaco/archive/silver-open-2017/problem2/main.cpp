#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
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
    int n, m;
    std::ifstream fin("cownomics.in");
    std::ofstream fout;

    fout.open("cownomics.out");

    fin >> n >> m;

    std::vector<std::string> spotted;
    std::vector<std::string> plain;

    for (int i = 0; i < n; i++) {
        std::string s;
        fin >> s;
        spotted.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        std::string s;
        fin >> s;
        plain.push_back(s);
    }

    ll count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                std::unordered_set<std::string> spots(n);
                std::unordered_set<std::string> plains(n);

                for (int l = 0; l < n; l++) {
                    std::string gene = "";
                    gene += spotted[l][i];
                    gene += spotted[l][j];
                    gene += spotted[l][k];
                    spots.insert(gene);
                }

                for (int l = 0; l < n; l++) {
                    std::string gene = "";
                    gene += plain[l][i];
                    gene += plain[l][j];
                    gene += plain[l][k];
                    plains.insert(gene);
                }

                for (auto it = spots.begin(); it != spots.end(); it++) {
                    const auto dup = plains.find(*it);

                    if (dup != plains.end()) {
                        goto skip;
                    }
                }

                count++;
skip:;
            }
        }
    }

    fout << count << std::endl;

    return 0;
}
