/*In this problem we use tree re-rooting logic with subtree size tracking to count, for every possible root, how many nodes have subtree size at least K, and then sum these counts over all root positions.*/

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define PB push_back
#define R0(i,n) for(int i=0;i<(n);++i)
#define R1(i,a,b) for(int i=(a);i<=(b);++i)
#define SZ(x) ((int)(x).size())

namespace aa {
    static inline int junk1(int a,int b){ if(false) return a^b; return 0; }
    static inline void junk2(){ if(0) cerr<<junk1(2,3); }
    namespace bb {
        struct St {
            int N;
            int K;
            vvi adj;
            vi order;
            vi par;
            vi sz;
            ll cur;
            ll ans;
        };
        static inline void init_state(St &s,int n,int k){
            s.N = n; s.K = k;
            s.adj.assign(n+1, vi());
            s.par.assign(n+1, 0);
            s.sz.assign(n+1, 0);
            s.order.clear();
            s.cur = 0;
            s.ans = 0;
        }
        static inline void add_edge(St &s,int u,int v){
            s.adj[u].PB(v);
            s.adj[v].PB(u);
        }
        static inline void build_order(St &s){
            s.order.reserve(s.N);
            deque<int> dq;
            dq.PB(1);
            s.par[1] = 0;
            while(!dq.empty()){
                int u = dq.front(); dq.pop_front();
                s.order.PB(u);
                int i=0;
                while(i < SZ(s.adj[u])){
                    int v = s.adj[u][i++];
                    if(v == s.par[u]) continue;
                    s.par[v] = u;
                    dq.PB(v);
                }
            }
        }
        static inline void compute_sz_bottom(St &s){
            for(int i = SZ(s.order)-1; i>=0; --i){
                int u = s.order[i];
                s.sz[u] = 1;
                int j=0;
                while(j < SZ(s.adj[u])){
                    int v = s.adj[u][j++];
                    if(v == s.par[u]) continue;
                    s.sz[u] += s.sz[v];
                }
            }
        }
        static inline void count_initial(St &s){
            s.cur = 0;
            int i=1;
            while(i<=s.N){
                if(s.sz[i] >= s.K) ++s.cur;
                ++i;
            }
            s.ans = s.cur;
        }
        static inline void reroot_walk(St &s){
            function<void(int,int)> go = [&](int u,int p){
                int i=0;
                while(i < SZ(s.adj[u])){
                    int v = s.adj[u][i++];
                    if(v == p) continue;
                    int old_u = s.sz[u];
                    int old_v = s.sz[v];
                    ll oldc = s.cur;
                    if(old_u >= s.K) --s.cur;
                    if(old_v >= s.K) --s.cur;
                    s.sz[u] = old_u - old_v;
                    s.sz[v] = s.N;
                    if(s.sz[u] >= s.K) ++s.cur;
                    if(s.sz[v] >= s.K) ++s.cur;
                    s.ans += s.cur;
                    go(v, u);
                    s.cur = oldc;
                    s.sz[u] = old_u;
                    s.sz[v] = old_v;
                }
            };
            go(1,0);
        }
    }
    namespace cc {
        static inline void runner(){
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            int T;
            if(!(cin>>T)) return;
            while(T--){
                int n,k;
                cin >> n >> k;
                bb::St S;
                bb::init_state(S,n,k);
                int m=0;
                while(m < n-1){
                    int u,v; cin >> u >> v;
                    bb::add_edge(S,u,v);
                    ++m;
                }
                bb::build_order(S);
                bb::compute_sz_bottom(S);
                bb::count_initial(S);
                bb::reroot_walk(S);
                cout << S.ans << '\n';
            }
            junk2();
        }
    }
    inline void go(){ cc::runner(); }
}

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    aa::go();
    return 0;
}
