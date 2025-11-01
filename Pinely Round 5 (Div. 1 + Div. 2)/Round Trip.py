# In this problem we use ----- logic: a greedy scan of the string that accepts '1' always and '2' only while r < x, decrementing r by d (clamped to 0) after each accepted character and counting the acceptances.

''' Author - ACr0bat, Created on 30-10-2025 '''
rg = range
import sys as ss
import itertools as itt
from collections import defaultdict as dd
import math as mth
import bisect as bs
import functools as ft

def rl():
    return ss.stdin.readline()

def ip():
    return list(map(int, rl().split()))

def st():
    return rl().strip()

def md(a, b):
    return max(0, a - b)

def rs():
    return int(rl())

def pr(x):
    print(x)

def ck1(c):
    return c == '1'

def ck2(c):
    return c == '2'

def up_r(r, d):
    return md(r, d)

def rd(t):
    return [ip() + [st()] for _ in rg(t)]

def sc_r(r, x, d, c):
    if ck1(c):
        return up_r(r, d)
    if ck2(c) and r < x:
        return up_r(r, d)
    return r

def sc_a(r, x, c):
    if ck1(c):
        return True
    if ck2(c) and r < x:
        return True
    return False

def cnt_a(s, r, x, d):
    a = 0
    for c in s:
        if sc_a(r, x, c):
            a += 1
            r = sc_r(r, x, d, c)
    return a

def slv_case(r, x, d, n, s):
    return cnt_a(s, r, x, d)

def proc_case(v):
    r, x, d, n, s = v[0], v[1], v[2], v[3], v[4]
    return slv_case(r, x, d, n, s)

def rd_cases(t):
    return rd(t)

def ans_all(vs):
    return [proc_case(v) for v in vs]

def sh_ans(a):
    for x in a:
        pr(x)

def main():
    t = rs()
    vs = rd_cases(t)
    a = ans_all(vs)
    sh_ans(a)

if __name__ == "__main__":
    main()

# @Copyright ACr0bat