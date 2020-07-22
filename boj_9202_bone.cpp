#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 26
#define lenlim 8
#define mm 4

int score[9]={0,0,0,1,1,2,3,5,11};
int dr[8]={-1,-1,-1,0,0,1,1,1}, dc[8]={-1,0,1,-1,1,-1,0,1};

char grid[mm][mm];
bool did[mm][mm];

vector<string> ans;

struct trie{
    trie* child[nn];
    bool leaf=0;
    trie(){ fill(child,child+nn,nullptr); leaf=0; }
    ~trie(){ for( int i=0;i<nn;i++ ) if(child[i]!=nullptr) delete child[i]; }
    void insert( string a ){
        trie* now = this;
        for( auto i : a ){
            int x = i-'A';
            if( now->child[x]==nullptr ) now->child[x] = new trie();
            now = now->child[x];
        }
        now->leaf = 1;
    }
    bool search( trie* node, string a ){
        trie* now = node;
        for( auto i : a ){
            int x = i-'A';
            if( now->child[x]==nullptr ) return 0;
            now = now->child[x];
        }
        return (now!=nullptr&&now->leaf);
    }
    void dfs( int i, int j, string a ){
        trie* now = this->child[grid[i][j]-'A'];
        int n = a.size();
        if( n>lenlim || now==nullptr ) return;
        a += grid[i][j];
        if( now->leaf ) ans.push_back(a);
        did[i][j]=1;
        for( int k=0; k<8; k++ ){
            int r = i+dr[k], c = j+dc[k];
            if( 0<=r && r<mm && 0<=c && c<mm && !did[r][c] ) now->dfs(r,c,a);
        }
        did[i][j]=0;
    }
};

int main(){

    int n;
    scanf("%d",&n);
    trie* root=new trie();
    while(n--){
        string a;
        cin>>a;
        root->insert(a);
    }
    scanf("\n");

    scanf("%d",&n);
    while(n--){
        for( int i=0; i<mm; i++ ) scanf("%s",grid[i]);
        ans.clear();
        for( int i=0; i<mm; i++ ) for( int j=0; j<mm; j++ ) root->dfs(i,j,"");
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        int mxlen=0, sum=0;
        string mxans;
        for( auto i : ans ){
            int n = i.size();
            if( mxlen<n || (mxlen==n&&i<mxans) ){ mxlen=n; mxans=i; }
            sum += score[n];
        }
        cout<<sum<<" "<<mxans<<" "<<ans.size()<<endl;
        if(n) scanf("\n");
    }
    return 0;
}
