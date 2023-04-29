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
    cout<<"diff of "<<a<<" and "<<b<<endl;
    if(a == "") return b.size();
    if(b == "") return a.size();
    if(a == b) return 0;
    
    //int res = 0;
    //while(!b.empty() && a[0] != b[0]){
    //    b = b.substr(1);
    //    res++;
    //}
    //return res + diff(a.substr(1),b.substr(1));
    //if(a[0] == b[0]) return diff(a.substr(1), b.substr(1));
    //if(a[1] == b[0]) return 1+diff(a.substr(2), b.substr(1));
    //if(a[0] == b[1]) return 1+diff(a.substr(1), b.substr(2));
    //return 2+diff(a.substr(1),b.substr(1));
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

