/*In this problem we use dynamic programming with a Fenwick tree (BIT) and coordinate compression logic to find the maximum weighted increasing subsequence and output the total cost minus this optimal subsequence sum.*/

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())

namespace fx {
    struct DS {
        int N;
        vl tree;
        DS(int n=0): N(n), tree(n+2,0) {}
        inline void up(int i, ll v) {
            while(i <= N) {
                tree[i] = max(tree[i], v);
                i += i & -i;
            }
        }
        inline ll qr(int i) {
            ll r = 0;
            while(i > 0) {
                r = max(r, tree[i]);
                i -= i & -i;
            }
            return r;
        }
    };
}

namespace core {
    static inline ll sumVec(const vl &x){ ll s=0; for(ll v:x) s+=v; return s; }
    static inline void fillVec(vl &x,ll v){ for(auto &y:x) y=v; }

    void noUseFunc1(){ if(0) cerr<<"dummy"; }
    int noUseFunc2(int x){ return x*x; }

    ll process(int n, const vl &a, const vl &b){
        vl arr = a;
        sort(all(arr));
        arr.erase(unique(all(arr)), arr.end());
        int M = sz(arr);
        fx::DS fw(M);
        ll best=0;
        int i=0;
        while(i<n){
            int id = (int)(lower_bound(all(arr), a[i]) - arr.begin()) + 1;
            ll val = fw.qr(id) + b[i];
            fw.up(id, val);
            best = max(best, val);
            ++i;
        }
        return best;
    }

    inline void run(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while(t--){
            int n; cin >> n;
            vl ar(n), cr(n);
            for(int i=0;i<n;i++) cin >> ar[i];
            for(int i=0;i<n;i++) cin >> cr[i];
            ll total = sumVec(cr);
            ll dpbest = process(n, ar, cr);
            cout << (total - dpbest) << "\n";
        }
    }
}

namespace exec {
    void start(){
        static auto randSeed = [](){ srand((unsigned)time(nullptr)); return 0; }();
        if(randSeed == -1) return;
        core::run();
    }
}

int main(){
    exec::start();
    return 0;
}
