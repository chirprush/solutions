#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

int main() {
    /* This is just for reading input */
    std::vector<long long> cows;
    std::vector<long long> canes;

    long long N;
    long long M;

    std::cin >> N;
    std::cin >> M;

    for (ll i = 0; i < N; i++) {
        ll a;
        std::cin >> a;
        cows.push_back(a);
    }

    for (ll i = 0; i < M; i++) {
        ll a;
        std::cin >> a;
        canes.push_back(a);
    }
    /* End of reading input */

    /* The actual algorithm */
    for (ll i = 0; i < M; i++) {
        ll height = 0;
        ll cane = canes[i];

        ll j = 0;
        while (cane > 0 && j < N) {
            ll cow = cows[j];
            if (cow > height && cane > 0) {
                ll eaten = std::min(cane, cow - height);
                height += eaten;
                cows[j] += eaten;
                cane -= eaten;
            }

            j++;
        }
    }

    /* Printing the solution out */
    for (ll i = 0; i < N; i++) {
        std::cout << cows[i] << std::endl;
    }
}
