# Approach :

'''
prefix maximum + greedy adjustment approach.
It builds prefix maximums to track left constraints and then greedily adjusts odd-indexed elements to satisfy height limits based on neighbors.

'''

''' Author: ACr0bat — Created on 19-10-2025 '''

import sys
rd = sys.stdin.readline

def f1():
    return int(rd())

def f2():
    return list(map(int, rd().split()))

def f3(n, a):
    p = [0]*(n+2)
    j = 1
    m = 0
    while j <= n:
        if a[j-1] > m:
            m = a[j-1]
        p[j] = m
        j += 1
    p[n+1] = p[n]
    return p

def f4(a, p, n):
    i = 1
    s = 0
    inf = 10**18
    while i <= n:
        if i % 2 == 1:
            l = p[i-1] if i > 1 else inf
            r = p[i+1] if i < n else inf
            x = min(l, r) - 1
            if a[i-1] > x:
                s += a[i-1] - x
        i += 1
    return s

def main():
    t = f1()
    for _ in range(t):
        n = f1()
        a = f2()
        p = f3(n, a)
        print(f4(a, p, n))

if __name__ == "__main__":
    main()

# @Copyright ACr0bat
