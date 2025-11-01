# In this problem we use dynamic programming over rows with 1- or 2-length segment choices, enforcing that adjacent rows' segments must overlap while forbidding any three consecutive rows from having a common overlapping column to decide if the # pattern is valid.

''' Author - ACr0bat, Created on 30-10-2025 '''
import sys
import itertools as it
import math as mh
from collections import defaultdict as dd

rg = range
ri = lambda: int(sys.stdin.readline())
rl = lambda: sys.stdin.readline().rstrip()
pg = lambda n: [rl() for _ in rg(n)]
gb = lambda s: [j for j, c in enumerate(s) if c == '#']
sg = lambda l, r: (l, r)
cv = lambda b, s: True if not b else b[0] >= s[0] and b[-1] <= s[1]

def vr(g, n):
    a = []
    for i in rg(n):
        b = gb(g[i])
        if not b:
            a.append([])
        else:
            m1, m2 = b[0], b[-1]
            if m2 - m1 > 1 or len(b) > 2:
                return 0, None
            a.append(b)
    return 1, a

def f1(r, n):
    for i in rg(n):
        if r[i]:
            return i
    return None

def f2(r, n):
    for i in range(n - 1, -1, -1):
        if r[i]:
            return i
    return None

def gs(n):
    s1 = [sg(j, j) for j in rg(n)]
    s2 = [sg(j, j + 1) for j in rg(n - 1)] if n >= 2 else []
    return list(it.chain(s1, s2))

def br(b, n):
    c = []
    if not b:
        c = gs(n)
    elif len(b) == 1:
        x = b[0]
        c.append(sg(x, x))
        if x - 1 >= 0:
            c.append(sg(x - 1, x))
        if x + 1 < n:
            c.append(sg(x, x + 1))
    else:
        x1, x2 = b[0], b[-1]
        c.append(sg(x1, x2))
    return c

def ba(r, a, b, n):
    s = []
    for i in rg(a, b + 1):
        s.append(br(r[i], n))
    return s

def idp(s0):
    d = dd(bool)
    for i, _ in enumerate(s0):
        d[(i, -1)] = 1
    return d

ov = lambda a, b, c, d: max(a, c) <= min(b, d)
tr = lambda a, b, c, d, e, f: max(a, c, e) <= min(b, d, f)
fk = lambda a, b: (a, b)

def ds(dp, s, i):
    nd = dd(bool)
    cl = s[i]
    for (p1, p2), ok in list(dp.items()):
        if not ok:
            continue
        L1, R1 = s[i - 1][p1]
        if i >= 2:
            L2, R2 = s[i - 2][p2]
        for j, (L0, R0) in enumerate(cl):
            if not ov(L1, R1, L0, R0):
                continue
            if i >= 2 and tr(L2, R2, L1, R1, L0, R0):
                continue
            nd[fk(j, p1)] = 1
    return nd

ae = lambda d: bool(d)

def dr(s, R):
    if R == 0:
        return 1
    dp = idp(s[0])
    for i in rg(1, R):
        dp = ds(dp, s, i)
        if not ae(dp):
            return 0
    return 1

def sc():
    n = ri()
    g = pg(n)
    ok, r = vr(g, n)
    if not ok:
        pn()
        return
    f = f1(r, n)
    if f is None:
        py()
        return
    l = f2(r, n)
    R = l - f + 1
    s = ba(r, f, l, n)
    if not s or not s[0]:
        pn()
        return
    INF = int(mh.pow(10, 9))
    _ = INF
    z = dr(s, R)
    if z:
        py()
    else:
        pn()

py = lambda: print("YES")
pn = lambda: print("NO")

def mn():
    t = ri()
    for _ in rg(t):
        sc()

if __name__ == "__main__":
    mn()
# @Copyright ACr0bat