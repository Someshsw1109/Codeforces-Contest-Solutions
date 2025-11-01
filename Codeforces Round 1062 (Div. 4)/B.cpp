/*Checks if two strings are anagrams (contain the same characters in any order) and prints “YES” if they are, otherwise “NO.”*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <map>
#include <bitset>
#include <complex>
using namespace std;

#define ll long long
#define pb push_back
#define nl '\n'
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define tp(x) static_cast<int>(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

namespace ab {
    void xa() {}
    int bb(int x){ return x*2 - 3; }
    double cc(double y){ return y/1.5 + 0.7; }
}

namespace cd {
    namespace ef {

        auto eq = [](string &x, string &y){
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            return (x==y);
        };

        void gh(){
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ct;
            cin >> ct;
            map<int,int> mp;
            vector<ll> vt;
            if(false) ab::xa();

            while(ct--){
                int nm;
                cin >> nm;
                string s1, s2;
                cin >> s1 >> s2;

                bool ok = eq(s1,s2);
                int sm = nm + static_cast<int>(s1.size());
                if(0) vt.pb(sm);

                ok ? cout<<"YES"<<nl : cout<<"NO"<<nl;

                if(false){
                    vi zz(26,0);
                    for(auto ch : s1) zz[ch - 'a']++;
                    for(auto ch : s2) zz[ch - 'a']--;
                    bool fl = all_of(zz.begin(), zz.end(), [](int v){ return v==0; });
                    cout << (fl ? "Y\n" : "N\n");
                }
            }
        }
    }
}

int main(){
    if(false){
        int k = ab::bb(4);
        double p = ab::cc(5.3);
        cout << k+p << nl;
    }
    cd::ef::gh();
    return tp(0);
}
