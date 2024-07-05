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
    int t;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        std::vector<ll> a;
        read_some(a, n);

        std::set<ll> nums;

        // Check for duplicates
        bool yes = true;
        
        for (int i = 0; i < n; i++) {
            if (nums.find(a[i]) != nums.end()) {
                yes = false;
                break;
            }

            nums.insert(a[i]);
        }

        if (!yes) {
            std::cout << "NO" << std::endl;
            continue;
        }

        std::vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

        for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
            std::map<ll, ll> classes;

            for (int j = 0; j < n; j++) {
                classes[a[j] % primes[i]]++;
            }

            bool any = false;

            for (int j = 0; j < primes[i]; j++) {
                if (classes[j] < 2) {
                    any = true;
                    break;
                }
            }

            if (!any) { 
                yes = false;
                break;
            }
        }

        if (yes) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
