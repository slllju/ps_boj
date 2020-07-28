#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 63

int idx(char x){
    if('a'<=x&&x<='z') return x-'a';
    if('A'<=x&&x<='Z') return 26+(x-'A');
    if('0'<=x&&x<='9') return 52+(x-'0');
    return 62;
}
struct trie{
    trie* ch[nn];
    bool pr, en;
    trie(){ fill(ch,ch+nn,nullptr); pr=en=0; }
    ~trie(){ for( int i=0; i<nn; i++ ) if( ch[i]!=nullptr ) delete ch[i]; }
    void insert(string a){
        trie* now = this;
        for( auto i : a ){
            int x = idx(i);
            if( now->ch[x]==nullptr ) now->ch[x]=new trie();
            now=now->ch[x];
            now->pr=1;
        }
    }
    bool search(string a){
        trie* now = this;
        for( auto i : a ){
            int x = idx(i);
            if( now->ch[x]==nullptr ) now->ch[x]=new trie();
            now=now->ch[x];
            if( now->en ) return 0;
            if( now->pr==0 ){ now->en=1; break; }
        }
        return 1;
    }
};
void solve(){
    trie* root = new trie();
    int n, ans=0;
    vector<string> f1;
    cin >> n;
    while( n-- ){ string a; cin >> a; f1.push_back(a); }
    cin >> n;
    for( int i=0; i<n; i++ ){ string a; cin >> a; root->insert(a); }
    if(n>0) for( auto i : f1 ) if( root->search(i) ) ans++;
    if(n==0) ans=1;
    printf("%d\n",ans);
    delete root;
}
int main(){ int tc; cin >> tc; while( tc-- ) solve(); return 0; }
