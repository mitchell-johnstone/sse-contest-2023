#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
     
    int n;
    cin>>n;

    vector<pii> ps;
    //int min_s = 1e9, max_e = 0;
    int _end = 0;
    rep(i,0,n){
        int s,e;
        cin>>s>>e;

        _end = min(_end,s);

        //min_s = min(min_s, s);
        //max_e = max(max_e, e);
        ps.emplace_back(s,e);
    }
    //cout<<en<<endl;

    sort(all(ps), [](pii& a, pii& b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
    int res = 0;
    for(pii a : ps){
        //cout<<a.first<<" "<<a.second<<endl;
        if(a.first >= _end){
            res++;
            _end = a.second;
        }
    }
    cout<<res<<endl;



//    sort(all(ps), [](pii& a, pii& b){ 
//        if(a.second != b.second) return a.second < b.second;
//        return a.first < b.first;
//            //if(a.first != b.first) return a.first < b.first;
//    });

//    vector<pii> cur;
//    unordered_map<int,int> m;
//    set<int> s;
//
//    for(pii test : ps){
//        bool good = true;
//        if(cur.size() != 0){
//            auto it = s.upper_bound(test.first);
//
//            if(it != s.begin()){
//                
//            }
//            if(it == s.end()) {
//                // got to end of set!
//                // test should go at end
//                if(s.back().first + s.back().second <= test.first){
//                } else {
//                    good = false;
//                }
//            } else {
//
//            }
//        }
//        if(good) {
//            cur.push_back(test);
//            s.insert(test.first);
//            m[test.first] = test.second;
//        }
//    }

//
//    size_t placed = 0;
//    rep(i, 0, n){
//        if(placed >= n-i) break; // already have max
//
//        vector<pii> cur = {ps[i]};
//        rep(j,i+1,n){
//            bool good = true;
//            pii test = ps[j];
//            for(pii a : cur){
//                if(!(test.first >= a.second || test.second <= a.first)){
//                    good = false;
//                    break;
//                }
//            }
//            if(good) cur.push_back(test);
//        }
//        placed = max(placed, cur.size());
//    }
    //cout<<placed<<endl;

//
//    vector<pii> cur = {ps[0]};
//    rep(i,1,ps.size()){
//        pii test = ps[i];
//        bool good = true;
//        for(pii a : cur){
//            if(!(test.first >= a.second || test.second <= a.first)){
//                good = false;
//                break;
//            }
//        }
//        if(good){
//            cur.push_back(test);
//        }

//        bool good = true;
//        rep(i,a.first - min_s, a.second - min_s){
//            if(visited[i]){
//                good = false;
//                break;
//            }
//        }
//        if(good){
//            placed++;
//            rep(i,a.first - min_s, a.second - min_s) visited[i] = true;
//        }
//    }
//    cout<<cur.size()<<endl;
}

