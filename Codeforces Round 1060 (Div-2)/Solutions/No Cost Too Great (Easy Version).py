# Approach:

'''
Combination of Sieve of Eratosthenes (for smallest prime factors) and greedy + set checking.
It factorizes numbers, counts prime occurrences, and then determines the result based on conflicts among prime factors.

'''

''' Author: ACr0bat — Created on 19-10-2025 '''

import sys, math, itertools, functools, bisect
ip = sys.stdin.readline

def spf_build(mx):
    s = [0]*mx
    for i in range(2, mx):
        if not s[i]:
            for j in range(i, mx, i):
                if not s[j]:
                    s[j] = i
    return s

def rd(): 
    return int(ip())

def rl(): 
    return list(map(int, ip().split()))


def init(mx): 
    return [0]*mx, [0]*mx

def get_primes(x, s):
    ps, last = [], 0
    while x > 1:
        p = s[x]
        x //= p
        if p == last: 
            continue
        last = p
        ps.append(p)
    return ps

def mark(p, cnt, rep, idx, seen):
    if not cnt[p]:
        seen.add(p)
    cnt[p] += 1
    rep[p] = idx


def clr(cnt, seen):
    for p in seen:
        cnt[p] = 0

def cost_zero(cnt, seen):
    for p in seen:
        if cnt[p] > 1:
            return True
    return False

def cost_one(cnt, rep, arr, s):
    for j, v in enumerate(arr):
        y, last = v + 1, 0
        while y > 1:
            p = s[y]
            y //= p
            if p == last:
                continue
            last = p
            if cnt[p] and rep[p] != j:
                return True
    return False

def handle(spf, cnt, rep):
    n = rd()
    a = rl()
    ip() 
    seen = set()
    for i, val in enumerate(a):
        for p in get_primes(val, spf):
            mark(p, cnt, rep, i, seen)
    if cost_zero(cnt, seen):
        print(0)
        clr(cnt, seen)
        return
    print(1 if cost_one(cnt, rep, a, spf) else 2)
    clr(cnt, seen)

def main():
    MX = 200005
    spf = spf_build(MX)
    t = rd()
    cnt, rep = init(MX)
    for _ in range(t):
        handle(spf, cnt, rep)

if __name__ == "__main__":
    main()


# @Copyright ACr0bat
