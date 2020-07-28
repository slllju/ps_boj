#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nn 26
const ll mod = 1000000007;

struct trie{
    trie* chd[nn];
    bool leaf;
    ll cnt;
    trie(){ fill(chd,chd+nn,nullptr); leaf=0; cnt=0; }
    ~trie(){ for(int i=0;i<nn;i++) if(chd[i]!=nullptr) delete chd[i]; }
    void insert( string a ){
        trie* now = this;
        for( auto i : a ){
            int x = i-'a';
            if( now->chd[x]==nullptr ) now->chd[x]=new trie();
            now = now->chd[x];
            now->cnt++;
        }
        now->leaf=1;
    }
};

int main(){
    int n;
    cin >> n;
    trie* root = new trie();
    while( n-- ){
        string a;
        cin >> a;
        root->insert(a);
    }
    string a;
    cin >> a;
    n = a.size();
    vector<ll> dp(n+1,0);
    for( int i=0; i<n; i++ ){
        trie* now = root;
        ll sum = 1;
        if( i ) sum = dp[i-1];
        for( int j=i; j<n; j++ ){
            int x = a[j]-'a';
            if( now->chd[x]==nullptr ) break;
            now = now->chd[x];
            dp[j] = (dp[j]+sum*now->cnt)%mod;
        }
    }
    cout << dp[n-1];
    return 0;
}
