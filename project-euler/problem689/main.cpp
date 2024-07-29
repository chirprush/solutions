#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

// Certainly not all precision shall be kept but
constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
constexpr int N = 31;
constexpr double threshold = 0.5;

struct Entry {
    int bit;
    double acc;
};

int main() {
    double total = 0;

    std::vector<double> prefix(N + 1);

    prefix[0] = 0;

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + 1.0 / (i * i);
    }

    std::vector<Entry> entries;

    entries.push_back((Entry) {1, 0.0});

    ll count = 0;

    while (entries.size()) {
        Entry entry = entries.back();
        entries.pop_back();

        count++;

        // std::cerr << "(" << entry.bit << ", " << entry.acc << ")" << std::endl;

        if (entry.bit == N) {
            // std::cerr << " -> " << (entry.acc > threshold) * std::pow(2, -N) << std::endl;
            total += (entry.acc > threshold) * std::pow(2, -N);
        } else if (entry.acc > threshold) {
            // std::cerr << " -> " << std::pow(2, -entry.bit) << std::endl;
            total += std::pow(2, -entry.bit);
        } else if (entry.acc + PI * PI / 6.0 - prefix[entry.bit - 1] < threshold) {
            // std::cerr << " -> " << 0 << std::endl;
            // Impossible to reach threshold
        } else {
            // std::cerr << " -> Recurse" << std::endl;
            entries.push_back((Entry) {entry.bit + 1, entry.acc});
            entries.push_back((Entry) {entry.bit + 1, entry.acc + 1.0 / (entry.bit * entry.bit)});
        }
    }

    std::cout << "States: " << count << std::endl;
    std::cout << std::setprecision(10) << total << std::endl;

    return 0;
}
