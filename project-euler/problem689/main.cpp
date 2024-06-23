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
constexpr double TOTAL = PI * PI / 6.0;
constexpr int limit = 34;
constexpr double threshold = 0.5;

double solve(int current, double total, double prefix) {
    if (current >= limit) {
        return total > threshold;
    } else if (total > threshold) {
        return 1;
    } else if (total + TOTAL - prefix <= threshold) {
        return 0;
    }

    return 0.5 * solve(current + 1, total, prefix + 1.0 / (current * current)) + 0.5 * solve(current + 1, total + 1.0 / (current * current), prefix + 1.0 / (current * current));
}

int main() {
    std::cout << std::setprecision(10) << solve(1, 0, 0) << std::endl;
    return 0;
}
