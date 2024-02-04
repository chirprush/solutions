#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long a[1001];

long long rec(long long i, long long prev, long long cnt){
    if(i == n){
        return cnt;
    }
    // cout << a[i] << " " << prev << endl;
    if(a[i] % prev == 0){
        return max(rec(i+1, prev, cnt), rec(i+1, a[i], cnt+1));
    }
    return rec(i+1, prev, cnt);
}

int main(){
    cin >> n;
 
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);

    cout << rec(0, 1, 0) << endl;
}
