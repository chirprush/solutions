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

constexpr ll M = 998244353;

ll powmod(ll a, ll b, ll m){
    ll ans = 1;
    while (b) {
        if (b % 2 == 1 ) { ans = (ans * a) % m; }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

int main() {
    ll n, p, k;

    std::cin >> n >> p >> k;

    std::vector<ll> den(k + 1);

    // std::cerr << "Values: " << std::endl;

    ll pi = 1;
    for (ll i = 0; i <= k; i++) {
        ll value = 1;
        ll pj = 1;

        for (ll j = 0; j < i; j++) {
            value *= (pi - pj + M) % M;
            value %= M;
            
            pj *= p;
            pj %= M;
        }

        // std::cerr << value << " ";

        den[i] = powmod(value, M - 2, M);

        pi *= p;
        pi %= M;
    }

    // std::cerr << std::endl;

    std::vector<ll> ranks(k + 1);

    ll pn = powmod(p, n, M);
    ll power = 1;
    ll pr = 1;

    for (ll r = 0; r <= std::min(n, k); r++) {
        ll num = 1;
        ll pk = 1;

        ranks[r] = power;

        power *= pn;
        power %= M;

        for (ll i = 0; i < r; i++) {
            // std::cerr << (num * den[i] % M) << " ";

            ranks[r] -= ((num * den[i]) % M) * ranks[i] % M;
            ranks[r] = (ranks[r] + M) % M;

            num *= (pr - pk + M) % M;
            num %= M;

            pk *= p;
            pk %= M;
        }

        // std::cerr << 1 << std::endl;

        pr *= p;
        pr %= M;
    }
    
    ll numerator = 1;
    ll pm = 1;

    for (ll r = 0; r <= k; r++) {
        ll ans = (numerator * den[r] % M) * ranks[r] % M;
        // std::cerr << "(" << ranks[r] << ") ";
        std::cout << ans << " ";

        numerator *= (pn - pm + M) % M;
        numerator %= M;

        pm *= p;
        pm %= M;
    }

    std::cout << std::endl;

    return 0;
}
