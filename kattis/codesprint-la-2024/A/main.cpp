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

ll w, p, t, b, r;

bool test_offset(ll offset) {
    ll initial_score = offset >= t ? 0 : r * (t - offset);

    ll full_times = (p - (t + b - offset)) / (t + b);
    ll full_times_score = full_times * r * t;

    ll leftover = p - (t + b - offset) - full_times * (t + b);
    ll leftover_score = r * std::min(leftover, t);

    return initial_score + full_times_score + leftover_score >= w;
}

int main() {
    std::cin >> w >> p >> t >> b >> r;

    // Trust trust
    ll offset1 = (t / std::__gcd(p, t + b)) * p % (t + b);
    ll offset2 = (offset1 + p) % (t + b);
    ll offset3 = ((offset1 - p) % (t + b) + t + b) % (t + b);
    // Guaranteed to be positive? ^

    // std::cerr << "Offsets" << std::endl;
    // std::cerr << offset1 << " " << offset2 << " " << offset3 << std::endl;
    // std::cerr << "Results" << std::endl;
    // std::cerr << test_offset(offset1) << " " << test_offset(offset2) << " " << test_offset(offset3) << std::endl;

    if (test_offset(offset1) && test_offset(offset2) && test_offset(offset3)) {
        std::cout << "Soot Sprites sing a lullaby" << std::endl;
    } else {
        std::cout << "The CSHOA decrees are as murky as the Forest Spirit" << std::endl;
    }

    return 0;
}
