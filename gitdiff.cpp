#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// process levishtine distance
ll diff(string a, string b){
    if(a == "") return b.size();
    if(b == "") return a.size();
    if(a == b) return 0;

    vector<vector<ll>> dp = vector<vector<ll>>(a.size()+1,vector<ll>(b.size()+1, 0LL));

    rep(i,0,a.size()+1) dp[i][0] = i;
    rep(i,0,b.size()+1) dp[0][i] = i;

    rep(i,1,a.size()+1){
        rep(j,1,b.size()+1){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[a.size()][b.size()];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k;
    cin>>n>>k;
    string n_lines[n];
    string k_lines[k];

    getline(cin,n_lines[0]);
    rep(i,0,n) getline(cin,n_lines[i]);
    rep(i,0,k) getline(cin,k_lines[i]);

    //cout<<"YAY!"<<endl;
    ll res = 0;
    rep(i,0,max(n,k)){
        if(i >= n){
            res += diff("", k_lines[i]);
        } else if(i >= k) {
            res += diff(n_lines[i], "");
        } else {
            res += diff(n_lines[i], k_lines[i]);
        }
    }
    cout<<res<<endl;
}

