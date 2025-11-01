/*In this problem we use binary search on distance D combined with interval merging logic to find the maximum gap allowing at least k uncovered positions in the range [0, X].*/

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
typedef pair<ll,ll> pll;

namespace ab {
    void xx(){}
    int yy(int z){ return z*z+3; }
    double zz(double w){ return w/4.2 + 2.2; }
}

namespace cd {
    namespace ef {

        auto fb = [](ll d,int k,ll X,vl& A){
            if(d==0) return true;
            vector<pll> sg;
            sg.reserve(A.size());
            ll dl = d-1;
            for(auto a:A){
                ll L = max(0LL,a-dl);
                ll R = min(X,a+dl);
                sg.emplace_back(L,R);
            }
            sort(sg.begin(),sg.end());
            ll frb=0,cl=sg[0].first,cr=sg[0].second;
            int i=1,n=tp(sg.size());
            while(i<n){
                auto &s=sg[i];
                if(s.first>cr+1){
                    frb += (cr-cl+1);
                    cl=s.first; cr=s.second;
                } else cr=max(cr,s.second);
                ++i;
            }
            frb += (cr-cl+1);
            ll frp=(X+1)-frb;
            return frp>=k;
        };

        void gh(){
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int ct; cin>>ct;
            map<int,int> mp;
            if(false) ab::xx();

            while(ct--){
                int n,k; ll X;
                cin>>n>>k>>X;
                vl A(n);
                int i=0;
                while(i<n){ cin>>A[i]; ++i; }

                ll lo=0,hi=X;
                while(lo<hi){
                    ll md=(lo+hi+1)>>1;
                    fb(md,k,X,A)?lo=md:hi=md-1;
                }
                ll D=lo;
                vl ans;
                ans.reserve(k);

                if(D==0){
                    i=0;
                    while(i<k){ ans.pb(i); ++i; }
                } else {
                    vector<pll> sg;
                    ll dl=D-1;
                    for(auto a:A){
                        ll L=max(0LL,a-dl);
                        ll R=min(X,a+dl);
                        sg.emplace_back(L,R);
                    }
                    sort(sg.begin(),sg.end());
                    ll cl=sg[0].first,cr=sg[0].second;
                    ll p=0;
                    while(p<cl && tp(ans.size())<k){ ans.pb(p++); }

                    int j=1,m=tp(sg.size());
                    while(j<m && tp(ans.size())<k){
                        auto &s=sg[j];
                        if(s.first>cr+1){
                            ll gl=cr+1,gr=s.first-1;
                            ll q=gl;
                            while(q<=gr && tp(ans.size())<k) ans.pb(q++);
                            cl=s.first; cr=s.second;
                        } else cr=max(cr,s.second);
                        ++j;
                    }

                    ll r=cr+1;
                    while(r<=X && tp(ans.size())<k) ans.pb(r++);
                }

                int u=0;
                while(u<k){
                    cout<<ans[u]<<(u+1<k?' ':'\n');
                    ++u;
                }

                if(false){
                    vi zz(5,0);
                    zz[2]=tp(A.size());
                    cout<<zz[2]<<nl;
                }
            }
        }
    }
}

int main(){
    if(false){
        int p=ab::yy(5);
        double q=ab::zz(8.5);
        cout<<p+q<<nl;
    }
    cd::ef::gh();
    return tp(0);
}
