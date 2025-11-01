# In this problem we use ----- logic: a greedy two-pointer on the sorted array that maintains the running sum modulo X and at each step picks the rightmost element if it alone fills the needed complement (or it's the last element), otherwise picks the leftmost — accumulating the count and recording the chosen order.

''' Author - ACr0bat, Created on 30-10-2025 '''
import sys
import math as mh
import itertools as it
from collections import defaultdict as dd

rg = range
ip = sys.stdin.readline
ri = lambda: int(ip())
ril = lambda: list(map(int, ip().split()))
r2 = lambda: map(int, ip().split())
sl = lambda a: sorted(a)
sm = lambda S, X: S % X
cn = lambda S, X: X - sm(S, X) if sm(S, X) != 0 else X
ct = lambda v, n: v >= n
ub = lambda b, v: b + v
asum = lambda S, v: S + v
ao = lambda o, v: (o.append(v), o)[1]
ii = lambda i: i + 1
di = lambda i: i - 1
ls = lambda l: " ".join(map(str, l))
po = lambda b, o: (print(b), print(ls(o)))
cc = lambda: dd(int)

def ca(a, l, r, S, X):
    rm = sm(S, X)
    nd = cn(S, X)
    return (a[r] >= nd or l == r), nd

def pl(a, r, S, b, o, n):
    v = a[r]
    if v >= n:
        b = ub(b, v)
    S = asum(S, v)
    o = ao(o, v)
    r = di(r)
    return 0, r, S, b, o

def ps(a, l, S, o):
    v = a[l]
    S = asum(S, v)
    o = ao(o, v)
    l = ii(l)
    return l, S, o

def pg(a, n, X):
    l, r = 0, n - 1
    S = 0
    b = 0
    o = []
    c = cc()
    while l <= r:
        d, n2 = ca(a, l, r, S, X)
        c['s'] += 1
        if d:
            _, r, S, b, o = pl(a, r, S, b, o, n2)
        else:
            l, S, o = ps(a, l, S, o)
    return b, o

def sc():
    n, X = r2()
    a = ril()
    a = sl(a)
    b, o = pg(a, n, X)
    po(b, o)

def mn():
    t = ri()
    for _ in rg(t):
        sc()

if __name__ == "__main__":
    mn()
# @Copyright ACr0bat