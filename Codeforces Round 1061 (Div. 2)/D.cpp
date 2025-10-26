/* Find the Last Number */

/*

Approach: Bit manipulation + Binary Search
interactive bitwise partitioning and elimination approach, 
where it repeatedly queries subsets of elements based on distinguishing bit positions 
to iteratively narrow down and identify the single correct element.

*/




// Author: ACr0bat — Created on 24-10-2025

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
#include <deque>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define FLUSH cout << flush

static inline int rdint() { int x; if(!(cin >> x)) return -1; return x; }
static inline void outq(int i, int m) { cout << "? " << i << " " << m << '\n'; FLUSH; }
static inline void outans(int a) { cout << "! " << a << '\n'; FLUSH; }

namespace ns {
    static inline int du1(int a,int b){ return (a^b); }
    static inline void du2(){ if(false) cout<<du1(1,2); }
    static inline double du3(double x){ return x*x; }

    static inline int cnt_bit(const vi &v,int bit){
        int c=0;
        int i=0;
        while(i < (int)v.size()){
            if((v[i] & (1<<bit)) != 0) ++c;
            ++i;
        }
        return c;
    }

    static inline int find_good_bit(const vi &pos){
        int sp = (int)pos.size();
        int half = sp/2;
        int bj = -1;
        int md = INT_MAX;
        int bb = 0;
        int bit=0;
        while(bit < 15){
            int c = cnt_bit(pos, bit);
            if(c != 0 && c != sp){
                int diff = abs(c - half);
                if(diff < md || (diff == md && bit < bb)){
                    md = diff;
                    bj = bit;
                    bb = bit;
                }
            }
            ++bit;
        }
        if(bj != -1) return bj;
        bit = 0;
        while(bit < 15){
            int c = cnt_bit(pos, bit);
            if(c > 0 && c < sp) return bit;
            ++bit;
        }
        return -1;
    }

    static inline void gather_resp(const vi &act, vi &resp, int m){
        int q = 0;
        while(q < (int)act.size()){
            int i = act[q];
            outq(i, m);
            int b = rdint();
            if(b == -1) exit(0);
            resp[q] = b;
            ++q;
        }
    }

    static inline int sumv(const vi &v){
        int s = 0;
        int i = 0;
        while(i < (int)v.size()){
            s += v[i];
            ++i;
        }
        return s;
    }

    static inline int count_mask(const vi &pos,int m){
        int s = 0;
        int i = 0;
        while(i < (int)pos.size()){
            if((pos[i] & m) != 0) ++s;
            ++i;
        }
        return s;
    }

    static inline void filter_pos_act(const vi &pos,const vi &act,const vi &resp,int m,int dec,vi &npos,vi &nact){
        int i = 0;
        while(i < (int)pos.size()){
            bool keep = ((pos[i] & m) != 0);
            if(!dec) keep = !keep;
            if(keep) npos.pb(pos[i]);
            ++i;
        }
        int q = 0;
        while(q < (int)act.size()){
            if(resp[q] == dec) nact.pb(act[q]);
            ++q;
        }
    }

    static inline void solve_case(){
        int n = rdint();
        if(n <= 0) return;
        vi poss; poss.reserve(n);
        int k=1;
        while(k<=n){ poss.pb(k); ++k; }
        vi act; act.reserve(max(0,n-1));
        int ii=1;
        while(ii < n){ act.pb(ii); ++ii; }
        while((int)poss.size() > 1){
            int bj = find_good_bit(poss);
            if(bj == -1) bj = 0;
            int m = static_cast<int>(1<<bj);
            int na = (int)act.size();
            vi resp(na,0);
            gather_resp(act, resp, m);
            int cy = 0;
            int kk=0;
            while(kk<na){ if(resp[kk]) ++cy; ++kk; }
            int sy = count_mask(poss, m);
            int dec = (cy == sy) ? 0 : 1;
            vi npos; npos.reserve(poss.size());
            vi nact; nact.reserve(act.size());
            filter_pos_act(poss, act, resp, m, dec, npos, nact);
            poss = std::move(npos);
            act = std::move(nact);
        }
        int ans = poss.empty() ? -1 : poss[0];
        outans(ans);
    }

    inline void run(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int T = rdint();
        int tt=0;
        while(tt < T){
            solve_case();
            ++tt;
        }
    }
}

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    ns::run();
    return 0;
}


// @Copyright ACr0bat
