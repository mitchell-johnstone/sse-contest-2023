#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct V {
    vector<V*> next;
    int n;
    bool visited = false;
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,k;
    cin>>n>>k;
    vector<V> vs(n);
    rep(i,0,n) vs[i].n = i;

    while(k--){
        int u,v;
        cin>>u>>v;
        vs[v].next.push_back(&vs[u]);
    }

    queue<V*> q;
    q.push(&vs[n-1]);
    while(!q.empty()){
        V* cur = q.front();
        q.pop();

        if(cur->visited) continue;
        cur->visited = true;

        cout<<cur->n<<endl;
        //q.push(all(cur->next));
        for(V* next : cur->next){
            q.push(next);
        }
    }
}

