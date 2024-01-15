#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

typedef long long ll;

struct item {
    int type;
    ll index;

    ll value;
    item *upper;
    ll copies;
};

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

ll solve(const item *items, ll l, ll k) {
    if (k == 0) {
        return items[0].value;
    }

    int i;
    for (i = 0; i < l; i++) {
        if (items[i].index >= k) {
            break;
        }
    }

    if (items[i].type == 1) {
        
    }
}

int main() {
    ll t;
    std::cin >> t;

    while (t--) {
        ll n, q;
        std::cin >> n >> q;

        item items[100001];
        int l = 0;
        ll index = 0;

        for (int _ = 0; _ < n; _++) {
            ll b, x;
            std::cin >> b >> x;

            if (b == 1) {
                item i = {0};
                i.type = 1;
                i.value = x;
                i.index = index;

                index++;

                items[l] = i;
            } else {
                item i = {0};
                i.type = 2;
                i.upper = &items[l-1];
                i.copies = x;
                i.index = index;

                index = (x + 1) * index;
                
                items[l] = i;
            }

            l++;
        }

        item i = {0};
        i.type = 3;
        i.index = index;

        items[l] = i;
        l++;

        for (int _ = 0; _ < q; _++) {
            ll k;
            std::cin >> k;

            k--;

            std::cout << solve(items, l, k) << std::endl;
        }
    }
    return 0;
}
