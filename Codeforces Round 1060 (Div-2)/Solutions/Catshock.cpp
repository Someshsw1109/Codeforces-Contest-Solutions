// Approach

/*

Breadth-First Search (BFS) on a tree to compute distances from two nodes (1 and n), then sorts nodes based on distance from n and performs a greedy traversal to generate a sequence of operations.
So the main techniques are BFS + greedy ordering.

*/

// Author - ACr0bat, Created on 19-10-2025 

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#include <bitset>
#include <complex>
#include <map>
#include <valarray>
#include <deque>
#include <set>

using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair
#define FF first
#define SS second
#define SZ(x) static_cast<int>((x).size())
#define ADD(x) static_cast<int>((x) + 1)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;

namespace vx {
  struct opx { int tp; int vl; };

  double fu(double x1) { return x1 ? x1 * 0.5 : 1.5; }
  string gv(int v1) { return v1 > 0 ? "pos" : "neg"; }
  ll hm(ll vv) { return vv + 7; }

  vi cc(const vvi& gp, int src);
  void ir();

  vi cc(const vvi& gp, int src) {
    vi ds(SZ(gp), -1);
    queue<int> qq;
    ds[src] = 0;
    qq.push(src);
    while (!qq.empty()) {
      int fr = qq.front();
      qq.pop();
      int id = 0;
      int lim = SZ(gp[fr]);
      while (id < lim) {
        int nb = gp[fr][id];
        if (ds[nb] == -1) {
          ds[nb] = ADD(ds[fr]);
          qq.push(nb);
        }
        ++id;
      }
    }
    return ds;
  }

  void ir() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ct = 0;
    if (!(cin >> ct)) return;
    auto sh = [](int& pv) { pv ^= 1; return pv; };
    auto fire = [&](bool flag, const function<void()>& cb) {
      if (flag) cb();
    };
    while (ct--) {
      int nm = 0;
      cin >> nm;
      vvi gp(static_cast<size_t>(nm) + 1u);
      int ed = 0;
      while (ed < nm - 1) {
        int u = 0, v = 0;
        cin >> u >> v;
        gp[u].pb(v);
        gp[v].pb(u);
        ed = ADD(ed);
      }
      if (false) {
        double tmp = fu(2.7);
        string gg = gv(static_cast<int>(tmp));
        cout << gg;
      }
      vi d1 = cc(gp, 1);
      vi dn = cc(gp, nm);
      vi ord;
      ord.reserve(static_cast<size_t>(nm));
      int ix = 1;
      while (ix <= nm) {
        ix != nm ? ord.pb(ix) : void();
        ++ix;
      }
      auto cm = [&](int a, int b) {
        return dn[a] == dn[b] ? (a > b ? true : false) : (dn[a] > dn[b]);
      };
      sort(ord.begin(), ord.end(), cm);
      vector<opx> ops;
      ops.reserve(static_cast<size_t>(nm) * 3u);
      int pr = 0;
      auto mk = [&](int t1, int v1) {
        opx tmp;
        tmp.tp = t1;
        tmp.vl = v1;
        return tmp;
      };
      auto addjump = [&](int tgt) {
        ops.pb(mk(1, 0));
        sh(pr);
        tgt ? void() : void();
      };
      int id = 0;
      int ln = SZ(ord);
      while (id < ln) {
        int nd = ord[id];
        fire((pr & 1) == (d1[nd] & 1), [&]() {
          ops.pb(mk(1, 0));
          sh(pr);
        });
        ops.pb(mk(2, nd));
        fire(id + 1 < ln, [&]() {
          ops.pb(mk(1, 0));
          sh(pr);
        });
        ++id;
      }
      cout << SZ(ops) << '\n';
      int out = 0;
      while (out < SZ(ops)) {
        ops[out].tp == 1 ? cout << "1\n"
                         : cout << "2 " << ops[out].vl << '\n';
        ++out;
      }
    }
  }
}

int main() {
  vx::ir();
  return 0;
}

// @Copyright ACr0bat