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
    ll n, m, k;
    std::cin >> n >> m >> k;

    std::vector<ll> inc(m); // F
    std::vector<ll> maxes(m); // C

    for (int i = 0; i < m; i++) {
        ll f, c;
        std::cin >> f >> c;

        inc[i] = f;
        maxes[i] = c;
    }

    ll score = 0;

    std::vector<std::vector<ll>> beauties(m);

    for (int i = 0; i < n; i++) {
        ll t, s;
        std::cin >> t >> s;

        t--;

        beauties[t].push_back(s);

        score += s;
    }

    for (int i = 0; i < m; i++) {
        std::sort(beauties[i].rbegin(), beauties[i].rend());
    }

    std::vector<std::pair<ll, ll>> moves; // (k, score per move)

    for (int i = 0; i < m; i++) {
        // std::cerr << "Debug: " << i << std::endl;
        ll initial = 0;
        ll done = 0;

        for (int j = 0; j < beauties[i].size(); j++) {
            // std::cerr << "  Debug: " << j << std::endl;
            if (beauties[i][j] + (done + 1) * inc[i] > maxes[i]) {
                initial += maxes[i] - beauties[i][j] - done * inc[i];
            } else {
                if (initial > 0) {
                    moves.push_back(std::make_pair(1, initial + inc[i] * (beauties[i].size() - j)));
                    done++;
                } else {
                    ll to_fill = (maxes[i] - beauties[i][j] - done * inc[i]) / inc[i];
                    done += to_fill;
                    moves.push_back(std::make_pair(to_fill, initial + inc[i] * (beauties[i].size() - j)));
                }

                initial = 0;
                j--;
                // std::cerr << "Move (from design " << i << ")" << std::endl;
                // initial = maxes[i] - beauties[i][j] - done * inc[i];
            }
        }

        if (initial > 0) {
            moves.push_back(std::make_pair(1, initial));
            // std::cerr << "Move (from design " << i << ")" << std::endl;
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        // std::cerr << "Move: (" << moves[i].first << ", " << moves[i].second << ")" << std::endl;
    }

    std::sort(moves.begin(), moves.end(), [](const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) { return a.second > b.second; });

    for (int i = 0; i < moves.size(); i++) {
        ll z = std::min(moves[i].first, k);
        k -= z;
        score += z * moves[i].second;
    }

    std::cout << score << std::endl;

    return 0;
}
