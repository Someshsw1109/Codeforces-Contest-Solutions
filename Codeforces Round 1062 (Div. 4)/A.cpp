/*checks if all four input integers are equal for each test case and prints “YES” if they are, otherwise “NO.*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
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
    int bb(int k){ return k*k - k; }
    double cc(double p){ return p/2.0 + 1.1; }
}

namespace cd {
    namespace ef {
        auto fn = [](int x, int y, int z, int w){
            return (x==y && y==z && z==w);
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
                int a,b,c,d;
                cin >> a >> b >> c >> d;

                bool fl = fn(a,b,c,d);
                vector<int> v = {a,b,c,d};
                sort(v.begin(), v.end());
                int sm = accumulate(v.begin(), v.end(), 0);
                if(0) cout << sm << nl;

                if(!v.empty() && sm >= 0){
                    fl ? cout<<"YES"<<nl : cout<<"NO"<<nl;
                } else {
                    cout<<"NO"<<nl;
                }
            }
        }
    }
}

int main(){
    if(false){
        int k = ab::bb(3);
        double p = ab::cc(4.2);
        cout << k+p << nl;
    }
    cd::ef::gh();
    return tp(0);
}