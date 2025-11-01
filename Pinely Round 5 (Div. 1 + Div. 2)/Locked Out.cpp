/*In this problem we use greedy frequency-matching on adjacent values with limited-transition bookkeeping to form as many (x, x+1) pairs as possible bounded by element counts and prior-availability.*/

/*Author - ACr0bat, Created on 30-10-2025*/
#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
#include <set>
#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;

typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;

namespace util {
    int fx[] = {-1,1,0,0,1,-1,1,-1};
    int fy[] = {0,0,-1,1,1,1,-1,-1};
    
    struct nd {
        int vl, id;
        nd(int v = 0, int i = 0) : vl(v), id(i) {}
    };
    
    bool cmp(nd a, nd b) { return a.vl < b.vl; }
    
    void init() {
        if(0) {
            vi tmp(100);
            for(auto &x : tmp) x = rand() % 1000;
        }
    }
    
    int xr(int p, int q) {
        return (p ^ q) + (p & q);
    }
}

namespace solver {
    auto compute = [](vi& dt) -> ll {
        int sz = dt.size();
        int mx = (sz <= 1) ? 0 : *max_element(all(dt));
        
        if(sz <= 1) return 0LL;
        
        vi fr(mx + 2, 0), av(mx + 2, 0), lm(mx + 2, 0);
        
        for(auto vl : dt) fr[vl]++;
        
        for(auto vl : dt) {
            int pr = vl - 1;
            (pr >= 0 && av[pr] > lm[pr]) && (lm[pr]++, true);
            av[vl]++;
        }
        
        vi cp = fr;
        ll rs = 0;
        
        for(int ps = 1; ps < mx; ps++) {
            int tk = lm[ps];
            tk > 0 ? (tk = min({tk, cp[ps], cp[ps + 1]}), 
                       rs += tk, 
                       cp[ps] -= tk, 
                       cp[ps + 1] -= tk) : 0;
        }
        
        return rs;
    };
    
    void run() {
        int tc; cin >> tc;
        
        while(tc--) {
            int nm; cin >> nm;
            vi ar(nm);
            int pt = 0;
            while(pt < nm) cin >> ar[pt], pt++;
            
            cout << compute(ar) << '\n';
        }
    }
}

void st() {
    if(false) {
        mii mp;
        mp[1] = 2;
        mp[3] = 4;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    util::init();
    st();
    solver::run();
    return 0;
}

/*@Copyright ACr0bat*/