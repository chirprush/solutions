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

constexpr ll MM = (ll)3e5 + 2;

struct Round {
    ll maxodd;
    ll minodd;
    ll maxeven;
    ll mineven;

    Round() {
        maxodd = 0;
        maxeven = 0;
        minodd = 0;
        mineven = 0;
    }

    Round(ll a, ll b, ll c, ll d) {
        maxodd = a;
        minodd = b;
        maxeven = c;
        mineven = d;
    }
};

constexpr ll debug = 1;

int main() {
    int t;
    std::cin >> t;

    // I'm actually quite out of ideas as to why this fails
    while (t--) {
        int N, M, K;
        std::cin >> N >> M >> K;

        std::vector<Round> choices(MM);

        std::vector<ll> needs(MM);
        std::vector<ll> needby(MM);

        for (int i = 0; i < M; i++) {
            ll maxodd = 0, minodd = 1e5, maxeven = 0, mineven = 1e5;
            ll a;

            for (int j = 0; j < K; j++) {
                std::cin >> a;

                if (a % 2 == 1) {
                    maxodd = std::max(maxodd, a);
                    minodd = std::min(minodd, a);
                } else if (a % 2 == 0) {
                    maxeven = std::max(maxeven, a);
                    mineven = std::min(mineven, a);
                }
            }

            if (minodd > maxodd) {
                minodd = maxodd;
            }

            if (mineven > maxeven) {
                mineven = maxeven;
            }

            needs[i] = std::min(maxodd, maxeven);

            choices[i] = Round(maxodd, minodd, maxeven, mineven);
        }

        std::string NAMES[] = {"Even", "Odd"};
        std::vector<int> moves(MM);

        // needby[i] should be like the minimum score that can win after i
        // if we play optimally
        // First run through
        ll score = N;
        for (int i = 0; i < M; i++) {
            if (score < needs[i] + 1 || score < 1) {
                goto imp;
            }

            if (choices[i].maxodd == 0) {
                score += choices[i].mineven;
            } else if (choices[i].maxeven == 0) {
                score += choices[i].minodd;
            } else { /* if (choices[i].maxeven < choices[i].maxodd) {
                // Play odd so lose even in worst case
                score -= choices[i].maxeven;
            } else if (choices[i].maxodd <= choices[i].maxeven) {
                // Play even so lose odd in worst case
                score -= choices[i].maxodd;
            } */ 
                score -= needs[i];
            }

            needby[i] = score;
        }

        if (score <= 0) {
            goto imp;
        }

        for (int i = 0; i < M; i++) {
            needby[i] -= score - 1;
        }

        if (debug) {
            for (int i = 0; i < M; i++) {
                std::cout << "rounds[" << i << "]: " << "Odd(" << choices[i].minodd << ", " << choices[i].maxodd << "), Even(" << choices[i].mineven << ", " << choices[i].maxeven << ")" << std::endl;
            }

            for (int i = 0; i < M; i++) {
                std::cout << "needs[" << i << "]: " << needs[i] << std::endl;
            }

            for (int i = 0; i < M; i++) {
                std::cout << "needby[" << i << "]: " << needby[i] << std::endl;
            }
        }

        score = N;
        for (int i = 0; i < M; i++) {
            if (debug) {
                std::cout << "score[" << i << "]: " << score << std::endl;
            }

            if (choices[i].maxodd == 0) {
                score += choices[i].mineven;
                moves[i] = 0;
            } else if (choices[i].maxeven == 0) {
                if (score - choices[i].maxodd >= needby[i] && score - choices[i].maxodd > 0) {
                    score -= choices[i].maxodd;
                    moves[i] = 0;
                } else {
                    score += choices[i].minodd;
                    moves[i] = 1;
                }
            } else if (choices[i].maxeven < choices[i].maxodd) {
                // Play odd so lose even in worst case
                // unless we can make the sequence smaller
                if (score - choices[i].maxodd >= needby[i] && score - choices[i].maxodd > 0) {
                    score -= choices[i].maxodd;
                    moves[i] = 0;
                } else {
                    score -= choices[i].maxeven;
                    moves[i] = 1;
                }
            } else /* if (choices[i].maxodd <= choices[i].maxeven) */ {
                // Play even so lose odd in worst case
                score -= choices[i].maxodd;
                moves[i] = 0;
            }
        }

        std::cout << NAMES[moves[0]];
        for (int i = 1; i < M; i++) {
            std::cout << " " << NAMES[moves[i]];
        }
        std::cout << std::endl;
        continue;
imp:
        std::cout << -1 << std::endl;
    }

    return 0;
}
