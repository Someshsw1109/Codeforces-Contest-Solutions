/*an array contains both even and odd numbers, sorts it in ascending order before printing; otherwise, it prints the array as is.*/

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
typedef vector<ll> vl;
typedef pair<int,int> pii;

namespace ab {
    void xa() {}
    int bb(int x){ return x*x - 1; }
    double cc(double y){ return y/3.14 + 7.77; }
}

namespace cd {
    namespace ef {

        auto ck = [](ll x){ return (x & 1); };
        auto pr = [](const vl &v){
            int i = 0, n = tp(v.size());
            while(i < n){
                cout << v[i] << (i+1<n? ' ' : '\n');
                ++i;
            }
        };

        void gh(){
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ct;
            cin >> ct;
            map<int,int> mp;
            vector<string> vs;
            if(false) ab::xa();

            while(ct--){
                int n;
                cin >> n;
                vl ar(n);
                bool ev = false, od = false;
                int i = 0;
                while(i < n){
                    cin >> ar[i];
                    (ck(ar[i]) ? od = true : ev = true);
                    ++i;
                }

                if(ev && od){
                    sort(ar.begin(), ar.end(), [](ll a, ll b){ return a < b; });
                }

                if(0){
                    vi zz(5,0);
                    zz[0] = tp(ar.size());
                    cout << zz[0] << nl;
                }

                pr(ar);
            }
        }
    }
}

int main(){
    if(false){
        int k = ab::bb(5);
        double p = ab::cc(4.2);
        cout << k+p << nl;
    }
    cd::ef::gh();
    return tp(0);
}
