#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct recipe {
    map<string, ll> sub;
};

ll total(string s, unordered_map<string, recipe>& m){
    //static map<string, int> dp;
    if(m[s].sub.size() == 0) {
        // base component!
        return 1;
    }
    ll sum = 0;
    for(auto it : m[s].sub){
        sum += it.second * total(it.first, m);
    }
    return sum;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
     
    string s;
    cin>>s;
    ll q;
    cin>>q;

    unordered_map<string, recipe> m;
    while(q--){
        string cur;
        ll comp;
        cin>>cur>>comp;

        while(comp--){
            string sub;
            int num;
            cin>>sub>>num;
            m[cur].sub[sub] = num;
        }
    }
    cout<<total(s, m)<<endl;
}

