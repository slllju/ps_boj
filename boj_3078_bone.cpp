#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nn 200001

int main(){
    int n, k;
    ll ans=0;
    vector<ll> cnt(21);
    scanf("%d%d",&n,&k);
    queue<int> q;
    while( n-- ){
        string a;
        cin >> a;
        int m = a.size();
        ans += cnt[m];
        if( int(q.size())>=k ){
            cnt[q.front()]--;
            q.pop();
        }
        cnt[m]++;
        q.push(m);
    }
    cout << ans;
    return 0;
}
