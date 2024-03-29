#include <bits/stdc++.h>
using namespace std;

int n, p;
pair<int, int> fence[200001];
pair<pair<int, int>, pair<int, int> > cow[100001];
vector<pair<pair<int, int>, pair<int, int> > > hori, vert;
map<pair<int, int>, vector<pair<int, int> > > adj;
map<pair<int, int>, int> ind;
set<pair<int, int> > vis;
vector<pair<int, int> > order;
map<int, set<int> > mx, my;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

vector<pair<pair<int, int>, pair<int, int> > > findseg(){
    vector<pair<pair<int, int>, pair<int, int> > > v;

    map<int, vector<pair<int, int> > > m;
    for(int i = 0; i < p; i++){
        m[fence[i].first].push_back(fence[i]);
    }

    for(pair<int, vector<pair<int, int> > > mp: m){
        sort(m[mp.first].begin(), m[mp.first].end(), cmp);

        for(int i = 0; i < m[mp.first].size(); i += 2){
            v.push_back(make_pair(m[mp.first][i], m[mp.first][i+1]));
        }
    }

    return v;
}

pair<pair<int, int>, pair<int, int> > cont(pair<int, int> p1){
    pair<pair<int, int>, pair<int, int> > seg;

    auto it = mx[p1.first].lower_bound(p1.second);
    // cout << *it << endl;
    if(it != mx[p1.first].end() && ((it != mx[p1.first].begin()) || (it == mx[p1.first].begin() && *it == p1.second))){
        // cout << "hi2" << endl;
        if(it == mx[p1.first].begin()){
            seg = make_pair(make_pair(p1.first, *it), make_pair(p1.first, *(++it)));
        }
        else{
            seg = make_pair(make_pair(p1.first, *(it)), make_pair(p1.first, *(--it)));
        }
    }

    if(abs(ind[seg.first] - ind[seg.second]) == 1 || abs(ind[seg.first] - ind[seg.second]) == order.size()-1){
        goto done;
    }

    // cout << "hi3" << endl;
    it = my[p1.second].lower_bound(p1.first);
    // cout << "hi4" << endl;
    if(it == my[p1.second].begin()){
        seg = make_pair(make_pair(*it, p1.second), make_pair(*(++it), p1.second));
    }
    else{
        seg = make_pair(make_pair(*(it), p1.second), make_pair(*(--it), p1.second));
    }

    // cout << seg.first.first << " " << seg.first.second << " " << seg.second.first << " " << seg.second.second << endl;
    done:;

    if(ind[seg.first] - ind[seg.second] == 1 || ind[seg.second] - ind[seg.first] == order.size()-1){
        swap(seg.first, seg.second);
    }
    return seg;
}

void dfs(pair<int, int> cur){
    order.push_back(cur);
    vis.insert(cur);
    // cout << cur.first << " " << cur.second << endl;
    for(pair<int, int> nxt: adj[cur]){
        if(vis.find(nxt) == vis.end()){
            dfs(nxt);
        }
    }
}

int dist(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    cin >> n >> p;

    for(int i = 0; i < p; i++){
        cin >> fence[i].first >> fence[i].second;
    }

    for(int i = 0; i < n; i++){
        cin >> cow[i].first.first >> cow[i].first.second >> cow[i].second.first >> cow[i].second.second;
    }

    hori = findseg();
    for(int i = 0; i < p; i++){
        swap(fence[i].first, fence[i].second);
    }
    vert = findseg();
    for(int i = 0; i < vert.size(); i++){
        swap(vert[i].first.first, vert[i].first.second);
        swap(vert[i].second.first, vert[i].second.second);
    }
    for(int i = 0; i < p; i++){
        swap(fence[i].first, fence[i].second);
    }
    // cout << endl;

    for(pair<pair<int, int>, pair<int, int> > seg: hori){
        adj[seg.first].push_back(seg.second);
        adj[seg.second].push_back(seg.first);
        // cout << seg.first.first << " " << seg.first.second << " " << seg.second.first << " " << seg.second.second << endl;
    }
    // cout << endl;

    for(pair<pair<int, int>, pair<int, int> > seg: vert){
        adj[seg.first].push_back(seg.second);
        adj[seg.second].push_back(seg.first);
        // cout << seg.first.first << " " << seg.first.second << " " << seg.second.first << " " << seg.second.second << endl;
    }

    dfs(fence[0]);

    for(int i = 0; i < order.size(); i++){
        ind[order[i]] = i;
    }

    for(int i = 0; i < p; i++){
        mx[fence[i].first].insert(fence[i].second);
    }
    for(int i = 0; i < p; i++){
        my[fence[i].second].insert(fence[i].first);
    }

    // for(pair<int, set<int> > p: mx){
    //     cout << p.first << endl;
    //     for(int i: p.second){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // for(pair<int, int> par: order){
    //     cout << par.first<< " " << par.second << endl;
    // }

    int pre[p];
    pre[0] = 0;
    for(int i = 1; i < p; i++){
        pre[i] = pre[i-1] + dist(order[i], order[i-1]);
    }

    int tot = pre[p-1] + dist(order[p-1], order[0]);

    int respre[p];
    for(int i = 0; i < p; i++){
        respre[i] = 0;
    }


    for(int i = 0; i < n; i++){
        pair<int, int> st = cow[i].first;
        pair<int, int> en = cow[i].second;

        pair<pair<int, int>, pair<int, int> > stseg = cont(st);
        pair<pair<int, int>, pair<int, int> > enseg = cont(en);

        if(stseg == enseg){
            if(st == stseg.first){
                pre[ind[stseg.first]]++;
                if(ind[stseg.first] != p-1){
                    pre[ind[stseg.first]-1]--;
                }
            }
            if(st == stseg.second){
                pre[ind[stseg.second]]++;
                if(ind[stseg.second] != p-1){
                    pre[ind[stseg.second]-1]--;
                }
            }
            if(en == stseg.first){
                pre[ind[stseg.first]]++;
                if(ind[stseg.first] != p-1){
                    pre[ind[stseg.first]-1]--;
                }
            }
            if(en == stseg.second){
                pre[ind[stseg.second]]++;
                if(ind[stseg.second] != p-1){
                    pre[ind[stseg.second]-1]--;
                }
            }

            continue;
        }

        // cout << "stseg: " << stseg.first.first << " " << stseg.first.second << " " << stseg.second.first << " " << stseg.second.second << endl;
        // cout << "enseg: " << enseg.first.first << " " << enseg.first.second << " " << enseg.second.first << " " << enseg.second.second << endl;

        int path1 = 0, path2 = 0;
        bool here = false;
        if(ind[stseg.second] <= ind[enseg.first]){
            path1 += pre[ind[enseg.first]] - pre[ind[stseg.second]];
            path1 += dist(stseg.second, st);
            path1 += dist(enseg.first, en);
            here = true;
        }
        else{
            path1 += pre[ind[stseg.first]] - pre[ind[enseg.second]];
            path1 += dist(stseg.first, st);
            path1 += dist(enseg.second, en);
        }

        path2 = tot - path1;
        // cout << path1 << " " << path2 << " " << here << endl;
        // cout << endl;
        if(path1 < path2){
            if(here){
                respre[ind[stseg.second]]++;
                if(ind[enseg.first] != p-1){
                    respre[ind[enseg.first]+1]--;
                }
            }
            else{
                respre[ind[enseg.second]]++;
                if(ind[stseg.first] != p-1){
                    respre[ind[stseg.first]+1]--;
                }
            }
        }
        else{
            if(here){
                respre[0]++;
                respre[ind[stseg.first]+1]--;
                respre[ind[enseg.second]]++;
            }
            else{
                respre[0]++;
                respre[ind[enseg.first]+1]--;
                respre[ind[stseg.second]]++;
            }
        }
    }

    for(int i = 1; i < p; i++){
        respre[i] += respre[i-1];
    }

    for(int i = 0; i < p; i++){
        cout << respre[ind[fence[i]]] << endl;
    }

    return 0;
}
