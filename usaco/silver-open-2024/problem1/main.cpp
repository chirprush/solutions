#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>

typedef long long ll;

void dfs(ll f, std::vector<std::vector<ll>> &adj, std::vector<bool> &visited) {
    if (visited[f]) {
        return;
    }

    visited[f] = true;

    for (ll j : adj[f]) {
        if (visited[j]) { continue; }

        dfs(j, adj, visited);
    }
}

int main() {
    ll n, k;
    std::cin >> n >> k;

    std::queue<ll> t;
    
    for (int i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        t.push(a);
    }

    std::vector<std::vector<ll>> adj(k);
    ll interviewer = 0, current = 0;

    std::map<ll, std::vector<ll>> interviewers; 
    std::vector<ll> ends(k);
    std::queue<ll> free;

    for (int i = 0; i < k; i++) {
        free.push(i);
    }

    while (true) {
        while (free.size() && t.size()) {
            ll f = free.front();
            free.pop();

            ll time = t.front();
            t.pop();

            ends[f] += time;

            interviewers[ends[f]].push_back(f);
        }

        if (free.size() && !t.size()) {
            interviewer = free.front();
            current = ends[interviewer];
            break;
        }

        auto it = interviewers.begin();

        // Shouldn't happen but might as well
        while (it->second.size() == 0) { it++; }

        for (ll i = 0; i < it->second.size(); i++) {
            free.push(it->second[i]);

            if (i > 0) {
                adj[it->second[i]].push_back(it->second[i-1]);
                adj[it->second[i-1]].push_back(it->second[i]);
            }
        }
        
        interviewers.erase(it);
    }

    std::cout << current << std::endl;

    std::vector<bool> visited(k);
    dfs(interviewer, adj, visited);

    for (int i = 0; i < k; i++) {
        std::cout << (int)visited[i];
    }

    std::cout << std::endl;

    return 0;
}
