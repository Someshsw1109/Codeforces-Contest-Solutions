// Approach:

/*

prefix sum + greedy with binary search approach.
It groups equal elements, calculates contributions using prefix sums, and greedily chooses how many elements to “adjust” while using binary search to maximize the total sum.

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
#include <random>

using namespace std;

#define ll long long
#define pb push_back
#define FF first
#define SS second
#define SZ(x) static_cast<int>((x).size())
#define ADD(x) static_cast<int>((x) + 1)
#define RET return

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

namespace yz {
  struct sg { ll va; int ct; int st; int ed; };

  ll uu(ll q) { return q + 11; }
  double vv(double z) { return z * 0.37; }
  int ww(int p) { return p - 4; }

  ll cut(const vl& pf, int L, int R) {
    if (L > R) swap(L, R);
    RET pf[static_cast<size_t>(R)] - pf[static_cast<size_t>(L)];
  }

  vl ps(const vl& ar) {
    vl pf(static_cast<size_t>(SZ(ar)) + 1u, 0);
    size_t it = 0;
    while (it < ar.size()) {
      pf[it + 1u] = pf[it] + ar[it];
      ++it;
    }
    RET pf;
  }

  void aa();
}

void yz::aa() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ct = 0;
  if (!(cin >> ct)) RET;

  if (0) {
    cout << uu(5) << " " << vv(1.0) << " " << ww(3);
  }

  auto flip = [&](int& x) { x ^= 1; RET x; };

  while (ct--) {
    int nm = 0, kk = 0;
    cin >> nm >> kk;
    vl ar(static_cast<size_t>(nm));
    int ix = 0;
    while (ix < nm) {
      cin >> ar[ix];
      ++ix;
    }

    sort(ar.begin(), ar.end(), [&](ll a, ll b) { RET a < b; });

    vl pf = ps(ar);
    ll tot = pf[static_cast<size_t>(nm)];
    ll ans = tot;

    if (kk == 0) {
      cout << ans << '\n';
      continue;
    }

    vector<yz::sg> bx;
    bx.reserve(static_cast<size_t>(nm));
    int st = 0;
    while (st < nm) {
      int ed = st;
      while (ed < nm && ar[ed] == ar[st]) ++ed;
      yz::sg seg;
      seg.va = ar[st];
      seg.ct = ed - st;
      seg.st = st;
      seg.ed = ed;
      bx.pb(seg);
      st = ed;
    }

    int sm = (nm - 1) / 2;
    auto run = [&](bool ok, auto&& cb) { ok ? cb() : void(); };

    auto gn = [&](const yz::sg& bl, int g) -> ll {
      ll sp = static_cast<ll>(bl.ct - 1 + g);
      ll tk = static_cast<ll>(kk) * sp;
      int lp = bl.st;
      tk = tk > lp ? lp : tk;
      ll ls = cut(pf, 0, static_cast<int>(tk));
      ll hs = 0;
      run(g > 0, [&]() { hs = cut(pf, bl.ed, bl.ed + g); });
      RET bl.va * tk - ls - (hs - static_cast<ll>(g) * bl.va);
    };

    auto dl = [&](const yz::sg& bl, int g) -> ll {
      ll sp = static_cast<ll>(bl.ct - 1 + g);
      int lp = bl.st;
      ll tk = static_cast<ll>(kk) * sp;
      tk = tk > lp ? lp : tk;
      ll nx = ar[static_cast<size_t>(bl.ed + g)];
      if (tk == lp) RET bl.va - nx;
      ll ad = static_cast<ll>(kk);
      run(tk + ad > lp, [&]() { ad = lp - tk; });
      ll df = cut(pf, static_cast<int>(tk), static_cast<int>(tk + ad));
      RET bl.va * ad - df + (bl.va - nx);
    };

    size_t id = 0;
    while (id < bx.size()) {
      const auto& bl = bx[id];
      int lp = bl.st;
      int rq = nm - bl.ed;

      if (sm <= bl.ct - 1) {
        ll sp = static_cast<ll>(sm);
        ll tk = static_cast<ll>(kk) * sp;
        tk = tk > lp ? lp : tk;
        ll ls = cut(pf, 0, static_cast<int>(tk));
        ll gn1 = bl.va * tk - ls;
        ans = ans > tot + gn1 ? ans : tot + gn1;
      } else {
        int gm = sm - (bl.ct - 1);
        gm = gm > rq ? rq : gm;
        if (gm <= 0) {
          ll gn0 = gn(bl, 0);
          ans = ans > tot + gn0 ? ans : tot + gn0;
        } else {
          int L = 0, R = gm - 1, bd = gm;
          while (L <= R) {
            int md = (L + R) >> 1;
            ll dv = dl(bl, md);
            dv <= 0 ? (bd = md, R = md - 1) : (L = md + 1);
          }
          int g1 = bd > gm ? gm : bd;
          int g2 = bd - 1;
          g2 = g2 < 0 ? 0 : g2;
          ll v1 = gn(bl, g1);
          ll v2 = gn(bl, g2);
          ll bst = v1 > v2 ? v1 : v2;
          ans = ans > tot + bst ? ans : tot + bst;
        }
      }
      ++id;
    }

    if (false) {
      int tp = flip(nm);
      cerr << tp;
    }

    cout << ans << '\n';
  }
}

int main() {
  yz::aa();
  return 0;
}


// @Copyright ACr0bat