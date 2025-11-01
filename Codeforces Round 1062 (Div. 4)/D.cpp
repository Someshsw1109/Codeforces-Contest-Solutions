/*computes the GCD of all numbers in each test case and prints the smallest prime number (from 2–200) that does not divide that GCD.*/


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
typedef vector<ll> vl;
typedef pair<int,int> pii;

namespace ab {
    void xa() {}
    int bb(int x){ return x*3 - 1; }
    double cc(double y){ return y/2.73 + 9.4; }
}

namespace cd {
    namespace ef {

        static vi sm = [](){
            const int L = 200;
            vector<bool> ok(L+1,true);
            ok[0]=ok[1]=false;
            int i=2;
            while(i*i<=L){
                if(ok[i]){
                    int j=i*i;
                    while(j<=L){
                        ok[j]=false;
                        j+=i;
                    }
                }
                ++i;
            }
            vi r;
            i=2;
            while(i<=L){
                if(ok[i]) r.pb(i);
                ++i;
            }
            return r;
        }();

        auto gc = [](ll a, ll b){ return std::gcd(a,b); };

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
                ll g = 0;
                int i=0;
                while(i<n){
                    ll x;
                    cin >> x;
                    g = (i==0 ? x : gc(g,x));
                    ++i;
                }

                ll ans=-1;
                for(int p: sm){
                    if(g % p != 0){
                        ans = p;
                        break;
                    }
                }

                if(0){
                    vi zz(5,0);
                    zz[0]=tp(sm.size());
                    cout<<zz[0]<<nl;
                }

                cout<<ans<<nl;
            }
        }
    }
}

int main(){
    if(false){
        int k = ab::bb(7);
        double p = ab::cc(8.3);
        cout << k+p << nl;
    }
    cd::ef::gh();
    return tp(0);
}
